tests := tests/*.cpp
sources := src/*.cpp

programsdir := src/programs
programssources := $(programsdir)/*.cpp

exampledir := src/programs/example
examplesources := $(exampledir)/*.cpp


all : tests/test $(exampledir)/example_main $(programsdir)/program1 $(programsdir)/program6

tests/test : ${tests} ${sources}
	g++ -std=c++17 -o $@ tests/main_gtest.cpp -lgtest -pthread -g

$(programsdir)/program1 : $(sources) $(examplesources)
	g++ -std=c++17 -o $@ $(programsdir)/program1.cpp

$(programsdir)/program6 : $(sources) $(examplesources)
	g++ -std=c++17 -o $@ $(programsdir)/program6.cpp

$(exampledir)/example_main : $(examplesources)
	g++ -std=c++17 -o $@ $(exampledir)/example_main.cpp




clean :
	$(RM) tests/test $(exampledir)/example_main $(programsdir)/program1 $(programsdir)/program6 
