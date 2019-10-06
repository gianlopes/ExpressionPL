# expPL : main.o lp.o ap.o np.o le.o ae.o ne.o
# 	g++ -o expPL main.o lp.o ap.o np.o le.o ae.o ne.o -g
expPL : 
	g++ -o expPL main.cpp

# main.o : main.cpp lp.cpp le.cpp ap.cpp ae.cpp np.cpp ne.cpp
# 	g++ -c main.cpp -g -Wall
# lp.o : lp.cpp
# 	g++ -c lp.cpp -g -Wall
# ap.o : ap.cpp lp.cpp
# 	g++ -c ap.cpp -g -Wall
# np.o : np.cpp lp.cpp
# 	g++ -c np.cpp -g -Wall
# le.o : le.cpp lp.cpp
# 	g++ -c le.cpp -g -Wall
# ae.o : ae.cpp ap.cpp lp.cpp le.cpp
# 	g++ -c ae.cpp -g -Wall
# ne.o : ne.cpp np.cpp lp.cpp le.cpp
# 	g++ -c ne.cpp -g -Wall
programa1 : programa1.cpp lp.cpp
	g++ -o programa1 programa1.cpp
programa6 : programa6.cpp lp.cpp le.cpp np.cpp ne.cpp
	g++ -o programa6 programa6.cpp

clean :
	rm expPL *.o programa1
#linux
#del expPL main.o lp.o ap.o np.o le.o ae.o ne.o
#windows