.SECONDEXPANSION:

BUILD_DIR := build
OUT_DIR := build
SRC_DIR = sbf-cpp

ifdef DEBUG
DBG_OPT_FLAGS=-g
else
DBG_OPT_FLAGS=-O2
endif

ifdef ASAN
ASAN_FLAGS=-fsanitize=address
else
ASAN_FLAGS=
endif

BREW86_PREFIX := $(shell arch -x86_64 /usr/local/homebrew/bin/brew --prefix)
BREW_PREFIX := $(shell brew --prefix)
LIB_DIR = $(BUILD_DIR)/lib
INCLUDE_DIRS = sbf-cpp $(BREW_PREFIX)/opt/ncurses/include
INCLUDES := $(patsubst %, -I%, $(INCLUDE_DIRS))
LIBRARY_DIRS = $(BUILD_DIR)/lib
LIBRARIES := $(patsubst %, -L%, $(LIBRARY_DIRS)) -lncurses
FRAMEWORK_NAMES = 
FRAMEWORKS := $(patsubst %, -framework %, $(FRAMEWORK_NAMES))
ARCHS = -arch arm64 -arch x86_64
CCFLAGS := -std=c++17 -Wall -fno-objc-arc -finput-charset=UTF-8 $(INCLUDES) $(DBG_OPT_FLAGS) $(ASAN_FLAGS) $(ARCHS)
LDFLAGS := $(LIBRARIES) $(FRAMEWORKS) $(ARCHS) $(DBG_OPT_FLAGS) $(ASAN_FLAGS)
CC = clang++
LD = clang++
CLIAPPNAME=sbf
TESTAPPNAME=test
APPS = $(CLIAPPNAME) $(TESTAPPNAME)
APPNAME=SBF
BUNDLENAME = $(APPNAME).app
BUNDLEFOLDER = $(BUILD_DIR)/$(BUNDLENAME)
BUNDLEIDENTIFIER = com.majinnaibu.test.$(APPNAME)
BUNDLESIGNATURE = SBF_
RESOURCES_DIR = Resources
#APP_OBJECTS = Character.o Colors.o Menus.o
MODULES = Abilities Archetypes Attributes Backgrounds Character Clans Colors Derangements Disciplines Genders Ranks Utils Virtues
TEST_MODULES = $(patsubst %, %_test, $(MODULES))
APP_OBJECTS = $(patsubst %, $(BUILD_DIR)/%.o, $(MODULES))
TEST_OBJECTS = $(patsubst %, $(BUILD_DIR)/%.o, $(TEST_MODULES))
FAT_LIBS = ncurses
FAT_LIB_OBJECTS = $(patsubst %, $(LIB_DIR)/lib%.a, $(FAT_LIBS))

MANDATORY_TARGETS = Makefile

.Phony: all clean app test run_all_tests run_incremental_tests

all: $(patsubst %, $(BUILD_DIR)/%, $(APPS)) app 

clean:
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/Contents
	mkdir -p $(BUILD_DIR)/lib
	mkdir -p $(BUNDLEFOLDER)/Contents/MacOS
	mkdir -p $(BUNDLEFOLDER)/Contents/Resources

run_all_tests: clean $(BUILD_DIR)/$(TESTAPPNAME) $(MANDATORY_TARGETS)
	$(BUILD_DIR)/$(TESTAPPNAME)

run_incremental_tests: $(BUILD_DIR)/$(TESTAPPNAME) $(MANDATORY_TARGETS)
	$(BUILD_DIR)/$(TESTAPPNAME)

test: run_incremental_tests

run_test:
# should depend on Makefile build/something
# runs a single test bundle build/MODULE_test.o's main and prints the results.

run: $(BUILD_DIR)/$(CLIAPPNAME)
	$(BUILD_DIR)/$(CLIAPPNAME)

# Main app
app: $(BUILD_DIR)/$(CLIAPPNAME) $(SRC_DIR)/Info.plist $(RESOURCES_DIR)/en-US.lproj/InfoPlist.strings $(MANDATORY_TARGETS)
	cp $(SRC_DIR)/Info.plist $(BUILD_DIR)/Contents/Info.plist
	plutil -replace CFBundleExecutable -string "$(APPNAME)" $(BUILD_DIR)/Contents/Info.plist
	plutil -replace CFBundleIdentifier -string "com.majinnaibu.$(APPNAME)" $(BUILD_DIR)/Contents/Info.plist
	plutil -replace CFBundleName -string "$(APPNAME)" $(BUILD_DIR)/Contents/Info.plist
	plutil -replace CFBundleSignature -string $(BUNDLESIGNATURE) $(BUILD_DIR)/Contents/Info.plist
	cp $(BUILD_DIR)/Contents/Info.plist $(BUNDLEFOLDER)/Contents/
	cp $(BUILD_DIR)/$(CLIAPPNAME) $(BUNDLEFOLDER)/Contents/MacOS/$(APPNAME)
	cp -r $(RESOURCES_DIR)/* $(BUNDLEFOLDER)/Contents/Resources/

$(BUILD_DIR)/$(CLIAPPNAME): $(BUILD_DIR)/sbf.o $(APP_OBJECTS) $(FAT_LIB_OBJECTS) $(MANDATORY_TARGETS)
	$(LD) $(LDFLAGS) -o $@ $< $(APP_OBJECTS)

$(BUILD_DIR)/$(TESTAPPNAME): $(BUILD_DIR)/test_main.o $(BUILD_DIR)/test.o $(APP_OBJECTS) $(TEST_OBJECTS) $(FAT_LIB_OBJECTS) $(BUILD_DIR)/test_main.cpp $(MANDATORY_TARGETS)
	$(LD) $(LDFLAGS) -o $@ $< $(APP_OBJECTS) $(TEST_OBJECTS) $(BUILD_DIR)/test.o

$(BUILD_DIR)/test_main.o: $(BUILD_DIR)/test_main.cpp $(SRC_DIR)/*.h $(SRC_DIR)/*_test.cpp $(MANDATORY_TARGETS)
	$(CC) $(CCFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/*.h $(MANDATORY_TARGETS)
	$(CC) $(CCFLAGS) -c -o $@ $<

# Create build/test_main.cpp with a main function that calls all of the test_main_* functions in each of the $(TEST_OBJECTS).
$(BUILD_DIR)/test_main.cpp: $(TEST_OBJECTS)
	echo "// This file is auto generated\n" > $(BUILD_DIR)/test_main.cpp
	echo "$(patsubst %, #include \"../$(SRC_DIR)/%.h\"\n, $(MODULES))" >> $(BUILD_DIR)/test_main.cpp
	echo "#include \"../$(SRC_DIR)/test.h\"" >> $(BUILD_DIR)/test_main.cpp
	echo "#include <clocale>" >> $(BUILD_DIR)/test_main.cpp
	echo "#include <string>" >> $(BUILD_DIR)/test_main.cpp
	echo "#include <iostream>" >> $(BUILD_DIR)/test_main.cpp
	echo "#include <tuple>" >> $(BUILD_DIR)/test_main.cpp
	echo "using namespace Test;" >> $(BUILD_DIR)/test_main.cpp
	echo "using std::wcout;\nusing std::endl;\nusing std::tuple;\nusing std::get;" >> $(BUILD_DIR)/test_main.cpp
	echo "$(patsubst %, extern test_method_result main_test_%(int argc, char** argv);\n, $(MODULES))" >> $(BUILD_DIR)/test_main.cpp
	echo "int main(int argc, char** argv) {\n    setlocale(LC_ALL, \"\");\n    test_method_result results;\n" >> $(BUILD_DIR)/test_main.cpp
	echo "$(patsubst %,    results = results + main_test_%(argc, argv);\n, $(MODULES))" >> $(BUILD_DIR)/test_main.cpp
	echo "    wcout << \"Total tests ran: \" << get<0>(results) << endl;\n" >> $(BUILD_DIR)/test_main.cpp
	echo "    wcout << \"Total failures: \" << get<1>(results) << endl;\n" >> $(BUILD_DIR)/test_main.cpp
	echo "\n    return 0;\n}" >> $(BUILD_DIR)/test_main.cpp

# We make our own fat libs cause homebrew sucks
$(LIB_DIR)/lib%.a: $(BREW_PREFIX)/opt/$$*/lib/lib$$*.a $(BREW86_PREFIX)/opt/$$*/lib/lib$$*.a $(MANDATORY_TARGETS)
	lipo -create -output $@ $(word 1, $^) $(word 2, $^)


