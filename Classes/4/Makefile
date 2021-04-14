all: a.out
	./a.out

SOURCES = gtest.cpp

googletest-build:
	cmake -G 'Unix Makefiles' -B googletest-build -DCMAKE_MAKE_PROGRAM=C:\Users\utkin.n\mingw\bin\make.exe ../../googletest
	$(MAKE) -C googletest-build

a.out: $(SOURCES) | googletest-build
	g++ -o a.out -g -I../../googletest/googletest/include -Lgoogletest-build/lib $^ -lpthread -lgtest -lgtest_main
