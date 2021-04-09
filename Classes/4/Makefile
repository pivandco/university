all: a.out
	./a.out

SOURCES = Fraction.cpp gtest.cpp

.PHONY: gtest
gtest:
	cmake -G 'Unix Makefiles' -B googletest-build ../../googletest
	$(MAKE) -C googletest-build

a.out: $(SOURCES) | gtest
	g++ -g -I../../googletest/googletest/include -Lgoogletest-build/lib $^ -lpthread -lgtest -lgtest_main
