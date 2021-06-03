all: uml a.out
	./a.out

.PHONY: debug
debug: a.out
	gdb ./a.out

CFLAGS := -g

SOURCES := \
	command_sets/_util.cpp \
	command_sets/file.cpp \
	command_sets/misc.cpp \
	command_sets/model.cpp \
	App.cpp \
	AppState.cpp \
	ClassJournal.cpp \
	ClassJournalFile.cpp \
	CLI.cpp \
	CommandRegistry.cpp \
	Date.cpp \
	Lesson.cpp \
	main.cpp

HEADERS := \
	command_sets/_util.hpp \
	command_sets/file.hpp \
	command_sets/misc.hpp \
	command_sets/model.hpp \
	App.hpp \
	AppState.hpp \
	binary_io.hpp \
	ClassJournal.hpp \
	ClassJournalFile.hpp \
	CLI.hpp \
	Command.hpp \
	CommandRegistry.hpp \
	Date.hpp \
	Lesson.hpp \
	printing.hpp

OBJECTS := $(SOURCES:.cpp=.o)

a.out: $(OBJECTS)
	g++ $(CFLAGS) -o $@ $^

%.o: %.cpp
	g++ $(CFLAGS) -c -o $@ $<

.PHONY: uml
uml: IO_Override_9.png
IO_Override_9.png: classes.puml
	plantuml $<

.PHONY: clean
clean:
	rm -rf *.o a.out
