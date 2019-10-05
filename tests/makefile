test : testmain.o lp_test.o
	g++ -o test testmain.o lp_test.cpp -lgtest -pthread

testmain.o : testmain.cpp
	g++ -c testmain.cpp -lgtest -pthread

lp_test.o : lp_test.cpp ../lp.cpp
	g++ -c lp_test.cpp -lgtest -pthread