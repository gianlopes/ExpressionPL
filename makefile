sources = *.cpp
expPL : ${sources}
	g++ -o expPL main.cpp

programa1 : programa1.cpp lp.cpp
	g++ -o programa1 programa1.cpp
programa6 : programa6.cpp lp.cpp le.cpp np.cpp ne.cpp
	g++ -o programa6 programa6.cpp

clean :
	rm expPL programa1 programa6
