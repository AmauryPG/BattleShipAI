main: main.o affichage.o simpleAI.o mediumAI.o
	g++ -o main main.o affichage.o simpleAI.o mediumAI.o
#
main.o: main.cpp affichage.h simpleAI.h mediumAI.h
	g++ main.cpp -g -c
#
affichage.o: affichage.cpp affichage.h
	g++ affichage.cpp -g -c
#
simpleAI.o: simpleAI.cpp simpleAI.h
	g++ simpleAI.cpp -g -c
#
mediumAI.o: mediumAI.cpp mediumAI.h
	g++ mediumAI.cpp -g -c
