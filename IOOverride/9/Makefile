all: uml a.out
	./a.out

CFLAGS :=

ifeq ($(COVERAGE),1)
	CFLAGS += --coverage
endif

../../googletest-build:
	cd ../.. && ./build-googletest.sh

SOURCES := \
	ClassJournal.cpp \
	CLI.cpp \
	commands.cpp \
	main.cpp

HEADERS := \
	AppState.hpp \
	ClassJournal.hpp \
	CLI.hpp \
	commands.hpp

a.out: $(SOURCES) $(HEADERS) | ../../googletest-build
	g++ $(CFLAGS) -o a.out -g -I../../googletest/googletest/include -I../../ -L../../googletest-build/lib $(SOURCES) -lpthread -lgtest -lgtest_main

.PHONY: coverage
coverage:
	@mkdir -p coverage
	gcovr -o coverage/coverage.html --html-details

.PHONY: uml
uml: IO_Override_9.png
IO_Override_9.png: classes.puml
	plantuml $<
