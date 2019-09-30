expPL : main.o lp.o ap.o np.o le.o ae.o ne.o
	g++ -o expPL main.o lp.o ap.o np.o le.o ae.o ne.o -g

main.o : main.cpp lp.cpp le.cpp ap.cpp ae.cpp np.cpp ne.cpp
	g++ -c main.cpp -g -Wall
lp.o : lp.cpp
	g++ -c lp.cpp -g -Wall
ap.o : ap.cpp lp.cpp
	g++ -c ap.cpp -g -Wall
np.o : np.cpp lp.cpp
	g++ -c np.cpp -g -Wall
le.o : le.cpp lp.cpp
	g++ -c le.cpp -g -Wall
ae.o : ae.cpp ap.cpp lp.cpp le.cpp
	g++ -c ae.cpp -g -Wall
ne.o : ne.cpp np.cpp lp.cpp le.cpp
	g++ -c ne.cpp -g -Wall

clean :
	#windows
	del expPL main.o lp.o ap.o np.o le.o ae.o ne.o
	#linux
	#rm expPL main.o lp.o ap.o np.o le.o ae.o ne.o 