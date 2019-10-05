test : testmain.o lp_test.o
	g++ -std=c++14 -o test testmain.o lp_test.cpp -lgtest -pthread -g

testmain.o : testmain.cpp
	g++ -std=c++14 -c testmain.cpp -lgtest -pthread -g

lp_test.o : lp_test.cpp ../lp.cpp
	g++ -std=c++14 -c lp_test.cpp -lgtest -pthread -g

clean :
	rm test testmain.o lp_test.o