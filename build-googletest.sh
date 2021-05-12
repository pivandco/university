#!/bin/sh

if [ "$(uname -o)" = "Msys" ]; then
    cmake -G 'Unix Makefiles' -B googletest-build '-DCMAKE_MAKE_PROGRAM=C:\Users\utkin.n\mingw\bin\make.exe' googletest
    /bin/make -C googletest-build
else
    cmake -G 'Unix Makefiles' -B googletest-build googletest
    make -C googletest-build
fi
