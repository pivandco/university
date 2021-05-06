all: a.out
	./a.out

OS := $(shell uname -o)

CFLAGS :=

ifeq ($(COVERAGE),1)
	CFLAGS += --coverage
endif

../../googletest-build:
	cd ../.. && ./build-googletest.sh

SOURCES := gtest.cpp
HEADERS := DynArray.hpp

a.out: $(SOURCES) $(HEADERS) | ../../googletest-build
	g++ $(CFLAGS) -o a.out -g -I../../googletest/googletest/include -I../../ -L../../googletest-build/lib $(SOURCES) -lpthread -lgtest -lgtest_main

.PHONY: coverage
coverage:
	@mkdir -p coverage
	gcovr -o coverage/coverage.html --html-details
