all: a.out
	./a.out

CFLAGS :=

ifeq ($(COVERAGE),1)
	CFLAGS += --coverage
endif

../../googletest-build:
	cd ../.. && ./build-googletest.sh

SOURCES := main.cpp Journal.cpp

HEADERS := Journal.hpp

a.out: $(SOURCES) $(HEADERS) | ../../googletest-build
	g++ $(CFLAGS) -o a.out -g -I../../googletest/googletest/include -I../../ -L../../googletest-build/lib $(SOURCES) -lpthread -lgtest -lgtest_main

.PHONY: coverage
coverage:
	@mkdir -p coverage
	gcovr -o coverage/coverage.html --html-details
