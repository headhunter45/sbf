.SECONDEXPANSION:

BUILD_DIR := build
OUT_DIR := build
SRC_DIR = sbf-cpp
RELATIVE_SRC_DIR = ../$(SRC_DIR)

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
CCFLAGS := -std=c++17 -Wall -fno-objc-arc -finput-charset=UTF-8 $(INCLUDES) $(DBG_OPT_FLAGS) $(ASAN_FLAGS) $(ARCHS) -fdiagnostics-show-template-tree -fno-elide-type
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
APP_OBJECTS = $(patsubst %, $(BUILD_DIR)/%.o, $(MODULES))
FAT_LIBS = ncurses
FAT_LIB_OBJECTS = $(patsubst %, $(LIB_DIR)/lib%.a, $(FAT_LIBS))
TEST_MODULES = $(patsubst %, %_test, $(MODULES))
TEST_OBJECTS = $(patsubst %, $(BUILD_DIR)/%.o, $(TEST_MODULES))
TEST_MAIN_CPP = $(BUILD_DIR)/test_main.cpp
ifdef $(MODULE)
TEST_HARNESS_CPP = $(BUILD_DIR)/$(MODULE)_test_harness.cpp
TEST_HARNESS_OBJ = $(BUILD_DIR)/$(MODULE)_test_harness.o
TEST_HARNESS_APP = $(BUILD_DIR)/$(MODULE)_test
TEST_OBJ = $(BUILD_DIR)/$(MODULE)_test.o
endif
COMMA = ,
EMPTY = 
SPACE = $(EMPTY) $(EMPTY)
DOCS_DIR = $(BUILD_DIR)/docs

MANDATORY_TARGETS = Makefile

.Phony: all clean app test run_all_tests run_incremental_tests targets docs read-docs

all: $(patsubst %, $(BUILD_DIR)/%, $(APPS)) app 

clean:
	rm -rf "$(BUILD_DIR)"
	mkdir -p "$(BUILD_DIR)"
	mkdir -p "$(BUILD_DIR)/Contents"
	mkdir -p "$(BUILD_DIR)/lib"
	mkdir -p "$(BUNDLEFOLDER)/Contents/MacOS"
	mkdir -p "$(BUNDLEFOLDER)/Contents/Resources"

run_all_tests: clean $(BUILD_DIR)/$(TESTAPPNAME) $(MANDATORY_TARGETS)
	$(BUILD_DIR)/$(TESTAPPNAME)

run_incremental_tests: $(BUILD_DIR)/$(TESTAPPNAME) $(MANDATORY_TARGETS)
	$(BUILD_DIR)/$(TESTAPPNAME)

test: run_incremental_tests

targets:
	@echo "Usefull make targets"
	@echo "  targets       - Displays this list of make targets."
	@echo "  clean         - Deletes the build folder including all apps and intermediate build files."
	@echo "  all           - Builds CLI apps $(subst $(SPACE),$(COMMA)$(SPACE),$(APPS)) and the app bundle $(BUNDLENAME)."
	@echo "  app           - Builds the app bundle $(BUNDLENAME). This also indirectly builds $(CLIAPPNAME)."
	@echo "  test          - Does an incremental build and runs all tests."
	@echo "  run_all_tests - Does a clean and rebuild then runs all tests."
	@echo "  docs          - Generates documentation in the $(DOCS_DIR)"
	@echo "  read-docs     - Opens the index.html file in your default browser. Builds the documentation if necessary."

docs: Doxyfile $(wildcard **/*.h) $(MANDATORY_TARGETS)
	@doxygen Doxyfile

read-docs: docs
	@open build/docs/html/index.html

$(BUILD_DIR)/_test:
	@echo "You need to define MODULE when you run make run_test."

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

$(BUILD_DIR)/$(TESTAPPNAME): $(BUILD_DIR)/test_main.o $(BUILD_DIR)/test.o $(APP_OBJECTS) $(TEST_OBJECTS) $(FAT_LIB_OBJECTS) $(TEST_MAIN_CPP) $(MANDATORY_TARGETS)
	$(LD) $(LDFLAGS) -o $@ $< $(APP_OBJECTS) $(TEST_OBJECTS) $(BUILD_DIR)/test.o

$(BUILD_DIR)/test_main.o: $(TEST_MAIN_CPP) $(SRC_DIR)/*.h $(SRC_DIR)/*_test.cpp $(MANDATORY_TARGETS)
	$(CC) $(CCFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/*.h $(MANDATORY_TARGETS)
	$(CC) $(CCFLAGS) -c -o $@ $<

# Create build/test_main.cpp with a main function that calls all of the test_main_* functions in each of the $(TEST_OBJECTS).
$(TEST_MAIN_CPP): $(TEST_OBJECTS)
	@echo "// This file is auto generated\n" > $(TEST_MAIN_CPP)
	@echo "$(patsubst %, #include \"$(RELATIVE_SRC_DIR)/%.h\"\n, $(MODULES))" >> $(TEST_MAIN_CPP)
	@echo "#include \"$(RELATIVE_SRC_DIR)/test.h\"" >> $(TEST_MAIN_CPP)
	@echo "#include <clocale>" >> $(TEST_MAIN_CPP)
	@echo "#include <string>" >> $(TEST_MAIN_CPP)
	@echo "#include <iostream>" >> $(TEST_MAIN_CPP)
	@echo "#include <tuple>" >> $(TEST_MAIN_CPP)
	@echo "#include <algorithm>" >> $(TEST_MAIN_CPP)
	@echo "#include <vector>" >> $(TEST_MAIN_CPP)
	@echo "using namespace Test;" >> $(TEST_MAIN_CPP)
	@echo "using std::cout;\nusing std::endl;\nusing std::tuple;\nusing std::get;\nusing std::for_each;\nusing std::vector;" >> $(TEST_MAIN_CPP)
	@echo "$(patsubst %, extern TestResults main_test_%(int argc, char** argv);\n, $(MODULES))" >> $(TEST_MAIN_CPP)
	@echo "int main(int argc, char** argv) {\n    setlocale(LC_ALL, \"\");\n    TestResults results;\n" >> $(TEST_MAIN_CPP)
	@echo "$(patsubst %,    results += main_test_%(argc, argv);\n, $(MODULES))" >> $(TEST_MAIN_CPP)
	@echo "    auto failure_messages = results.failure_messages();" >> $(TEST_MAIN_CPP)
	@echo "    if (failure_messages.size() > 0) {" >> $(TEST_MAIN_CPP)
	@echo "        cout << \"Failures:\" << endl;" >> $(TEST_MAIN_CPP)
	@echo "        for_each(failure_messages.begin(), failure_messages.end(), [](const string& message){cout << message << endl;});\n" >> $(TEST_MAIN_CPP)
	@echo "    }" >> $(TEST_MAIN_CPP)
	@echo "    cout << \"Total tests: \" << results.total() << endl;" >> $(TEST_MAIN_CPP)
	@echo "    cout << \"Passed:      \" << results.passed() << endl;" >> $(TEST_MAIN_CPP)
	@echo "    cout << \"Failed:      \" << results.failed() << endl;" >> $(TEST_MAIN_CPP)
	@echo "    cout << \"Skipped:     \" << results.skipped() << endl;" >> $(TEST_MAIN_CPP)
	@echo "    cout << \"Errors:      \" << results.errors() << endl;" >> $(TEST_MAIN_CPP)
	@echo "\n    return 0;\n}\n//tom2" >> $(TEST_MAIN_CPP)

# We make our own fat libs cause homebrew sucks. # We may have to do something similar for macports, but that's not supported yet.
$(LIB_DIR)/lib%.a: $(BREW_PREFIX)/opt/$$*/lib/lib$$*.a $(BREW86_PREFIX)/opt/$$*/lib/lib$$*.a $(MANDATORY_TARGETS)
	lipo -create -output $@ $(word 1, $^) $(word 2, $^)

ifdef $(MODULE)
# Runs a single test harness app e.g. build/Ranks_test made from
# sbf-cpp/Ranks{.h,.cpp,_test.cpp} and the generated test shim
# build/Ranks_test_harness.cpp
run_test: $(TEST_HARNESS_APP) $(MANDATORY_TARGETS)
	$(TEST_HARNESS_APP)

$(TEST_HARNESS_CPP): $(MANDATORY_TARGETS)
	@echo "// This file is auto generated\n" > $(TEST_HARNESS_CPP)
	@echo "#include \"$(RELATIVE_SRC_DIR)/$(MODULE).h\"" >> $(TEST_HARNESS_CPP)
	@echo "#include \"../sbf-cpp/test.h\"" >> $(TEST_HARNESS_CPP)
	@echo "#include \"$(RELATIVE_SRC_DIR)/test.h\"" >> $(TEST_HARNESS_CPP)
	@echo "#include <clocale>" >> $(TEST_HARNESS_CPP)
	@echo "#include <string>" >> $(TEST_HARNESS_CPP)
	@echo "#include <iostream>" >> $(TEST_HARNESS_CPP)
	@echo "#include <tuple>" >> $(TEST_HARNESS_CPP)
	@echo "#include <algorithm>" >> $(TEST_HARNESS_CPP)
	@echo "#include <vector>" >> $(TEST_HARNESS_CPP)
	@echo "using namespace Test;" >> $(TEST_HARNESS_CPP)
	@echo "using std::cout;\nusing std::endl;\nusing std::tuple;\nusing std::get;\nusing std::for_each;\nusing std::vector;" >> $(TEST_HARNESS_CPP)
	@echo "extern TestResults main_test_$(MODULE)(int argc, char** argv);" >> $(TEST_HARNESS_CPP)	
	@echo "int main(int argc, char** argv) {\n    setlocale(LC_ALL, \"\");\n    TestResults results;\n" >> $(TEST_HARNESS_CPP)
	@echo "    results = results + main_test_$(MODULE)(argc, argv);\n" >> $(TEST_HARNESS_CPP)
	@echo "    auto failure_messages = results.failure_messages();" >> $(TEST_HARNESS_CPP)
	@echo "    if (failure_messages.size() > 0) {" >> $(TEST_HARNESS_CPP)
	@echo "        cout << \"Failures:\" << endl;" >> $(TEST_HARNESS_CPP)
	@echo "        for_each(failure_messages.begin(), failure_messages.end(), [](const string& message){cout << message << endl;});\n" >> $(TEST_HARNESS_CPP)
	@echo "    }" >> $(TEST_HARNESS_CPP)
	@echo "    cout << \"Total tests: \" << results.total() << endl;" >> $(TEST_HARNESS_CPP)
	@echo "    cout << \"Passed:      \" << results.passed() << endl;" >> $(TEST_HARNESS_CPP)
	@echo "    cout << \"Failed:      \" << results.failed() << endl;" >> $(TEST_HARNESS_CPP)
	@echo "    cout << \"Skipped:     \" << results.skipped() << endl;" >> $(TEST_HARNESS_CPP)
	@echo "    cout << \"Errors:      \" << results.errors() << endl;" >> $(TEST_HARNESS_CPP)
	@echo "\n    return 0;\n}\n//tom" >> $(TEST_HARNESS_CPP)

$(TEST_HARNESS_OBJ): $(TEST_HARNESS_CPP) $(SRC_DIR)/*.h $(TEST_CPP) $(MANDATORY_TARGETS)
	$(CC) $(CCFLAGS) -c -o $@ $<	

$(TEST_HARNESS_APP): $(TEST_HARNESS_OBJ) $(APP_OBJECTS) $(TEST_OBJ) $(BUILD_DIR)/test.o $(MANDATORY_TARGETS)
	$(LD) $(LDFLAGS) -o $@ $< $(APP_OBJECTS) $(TEST_OBJ) $(BUILD_DIR)/test.o
endif
