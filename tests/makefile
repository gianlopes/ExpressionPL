tests = *.cpp
sources = ../src/*.cpp

test : ${tests} ${sources}
	g++ -std=c++17 -o test testmain.cpp -lgtest -pthread -g

clean :
	rm test
