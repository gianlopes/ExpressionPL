sources = ../*.cpp
expPL : ${sources}
	g++ -std=c++17 -o expPL main.cpp -Wall

programa1 : programa1.cpp ../lp.cpp
	g++ -std=c++17 -o programa1 programa1.cpp
programa6 : programa6.cpp ../lp.cpp ../le.cpp ../np.cpp ../ne.cpp
	g++ -std=c++17 -o programa6 programa6.cpp

clean :
	rm expPL programa1 programa6
