all: a.out
	./a.out

OS := $(shell uname -o)

CFLAGS :=

ifeq ($(COVERAGE),1)
	CFLAGS += --coverage
endif

googletest-build:
	ifeq ($(OS),Msys)
		cmake -G 'Unix Makefiles' -B googletest-build -DCMAKE_MAKE_PROGRAM=C:\Users\utkin.n\mingw\bin\make.exe ../../googletest
	else
		cmake -G 'Unix Makefiles' -B googletest-build ../../googletest
	endif
	$(MAKE) -C googletest-build

SOURCES := ArrayIO.cpp gtest.cpp
HEADERS := ArrayIO.hpp

a.out: $(SOURCES) $(HEADERS) | googletest-build
	g++ $(CFLAGS) -o a.out -g -I../../googletest/googletest/include -I../../ -Lgoogletest-build/lib $(SOURCES) -lpthread -lgtest -lgtest_main

.PHONY: coverage
coverage:
	@mkdir -p coverage
	gcovr -o coverage/coverage.html --html-details
