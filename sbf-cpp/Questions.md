## Which is uglier
```c++
(*after_each)()
after_each->operator()()
after_each.value()();
```

## What do all of these command line args do and which do I really want?
```bash
clang \
    -xc++ \
    -D_FORTIFY_SOURCE=1 \
    -fstack-protector \
    -fcolor-diagnostics \
    -Wall \
    -Wthread-safety \
    -Wself-assign \
    -fno-omit-frame-pointer \
    -O0 \
    -DDEBUG \
    -std=c++11 \
    -iquote \
    . \
    -iquote \
    bazel-out/darwin_arm64-fastbuild/bin \
    -MD \
    -MF \
    bazel-out/darwin_arm64-fastbuild/bin/sbf-cpp/_objs/menus/Menus.d \
    -DBAZEL_CURRENT_REPOSITORY="" \
    -frandom-seed=bazel-out/darwin_arm64-fastbuild/bin/sbf-cpp/_objs/menus/Menus.o \
    -isysroot \
    /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk \
    -F/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks \
    -F/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/Library/Frameworks \
    -no-canonical-prefixes \
    -pthread \
    -no-canonical-prefixes \
    -Wno-builtin-macro-redefined \
    -D__DATE__="redacted" \
    -D__TIMESTAMP__="redacted" \
    -D__TIME__="redacted" \
    -target \
    arm64-apple-macosx13.3 \
    -c \
    sbf-cpp/Menus.cpp \
    -o \
    bazel-out/darwin_arm64-fastbuild/bin/sbf-cpp/_objs/menus/Menus.o
```
