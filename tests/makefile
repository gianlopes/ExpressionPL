tests = *.cpp
sources = ../*.cpp

test : ${tests} ${sources}
	g++ -std=c++14 -o test testmain.cpp -lgtest -pthread -g

clean :
	rm test
