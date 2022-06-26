# This is the default target, which will be built when you invoke
.PHONY: all
# This rule tells make how to build HelloWorld from
all: hello ut_all

hello: HelloWorld.cpp
	g++ HelloWorld.cpp -o HelloWorld
# This rule tells make to delete hello and hello.o
ut_all: ut_main.cpp
	g++ -std=c++11 -Wfatal-errors ut_main.cpp -o ut_all -lgtest -lpthread

.PHONY: clean
clean:
	rm -f HelloWorld
	rm -f ut_all