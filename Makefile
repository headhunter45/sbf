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
APP_OBJECTS = main.o
FAT_LIBS = ncurses

MANDATORY_TARGETS = Makefile

.Phony: all clean app run_all_tests run_incremental_tests

all: $(patsubst %, $(BUILD_DIR)/%, $(APPS)) app 

clean:
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/Contents
	mkdir -p $(BUILD_DIR)/lib
	mkdir -p $(BUNDLEFOLDER)/Contents/MacOS
	mkdir -p $(BUNDLEFOLDER)/Contents/Resources

run_all_tests: clean all
	$(BUILD_DIR)/$(TESTAPPNAME)

run_incremental_tests: $(BUILD_DIR)/$(TESTAPPNAME)
	$(BUILD_DIR)/$(TESTAPPNAME)

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

$(BUILD_DIR)/$(CLIAPPNAME): $(patsubst %, $(BUILD_DIR)/%, $(APP_OBJECTS)) $(patsubst %, $(BUILD_DIR)/lib/lib%.a, $(FAT_LIBS)) $(MANDATORY_TARGETS)
	$(LD) $(LDFLAGS) -o $@ $(patsubst %, $(BUILD_DIR)/%, $(APP_OBJECTS))

$(BUILD_DIR)/$(TESTAPPNAME): $(BUILD_DIR)/test.o $(patsubst %, $(BUILD_DIR)/%, $(APP_OBJECTS)) $(patsubst %, $(BUILD_DIR)/lib/lib%.a, $(FAT_LIBS)) $(MANDATORY_TARGETS)
	$(LD) $(LDFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/*.h $(MANDATORY_TARGETS)
	$(CC) $(CCFLAGS) -c -o $@ $<

# We make our own fat libs cause homebrew sucks
build/lib/lib%.a: $(BREW_PREFIX)/opt/$$*/lib/lib$$*.a $(BREW86_PREFIX)/opt/$$*/lib/lib$$*.a $(MANDATORY_TARGETS)
	lipo -create -output $@ $(word 1, $^) $(word 2, $^)
