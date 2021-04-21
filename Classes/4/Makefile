all: a.out
	./a.out --gtest_color=yes

OS := $(shell uname -o)

googletest-build:
	ifeq ($(OS),Msys)
		cmake -G 'Unix Makefiles' -B googletest-build -DCMAKE_MAKE_PROGRAM=C:\Users\utkin.n\mingw\bin\make.exe ../../googletest
	else
		cmake -G 'Unix Makefiles' -B googletest-build ../../googletest
	endif
	$(MAKE) -C googletest-build

a.out: gtest.cpp Fraction.hpp | googletest-build
	g++ -o a.out -g -I../../googletest/googletest/include -Lgoogletest-build/lib gtest.cpp -lpthread -lgtest -lgtest_main
