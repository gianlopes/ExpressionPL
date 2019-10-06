tests = *.cpp
sources = ../*.cpp

test : ${tests} ${sources}
	g++ -std=c++14 -o test testmain.cpp -lgtest -pthread -g

clean :
	rm test *.o

# test : testmain.o lp_test.o le_test.o ap_test.o ae_test.o 
# 	g++ -std=c++14 -o test *.o -lgtest -pthread -g

# testmain.o : testmain.cpp np_test.cpp
# 	g++ -std=c++14 -c testmain.cpp -lgtest -pthread -g

# lp_test.o : lp_test.cpp ../lp.cpp
# 	g++ -std=c++14 -c lp_test.cpp -lgtest -pthread -g

# le_test.o : le_test.cpp ../le.cpp
# 	g++ -std=c++14 -c le_test.cpp -lgtest -pthread -g

# ap_test.o : ap_test.cpp ../ap.cpp
# 	g++ -std=c++14 -c ap_test.cpp -lgtest -pthread -g

# ae_test.o : ae_test.cpp ../ae.cpp
# 	g++ -std=c++14 -c ae_test.cpp -lgtest -pthread -g

