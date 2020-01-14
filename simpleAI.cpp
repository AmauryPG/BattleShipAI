#include "simpleAI.h"

simpleAI::simpleAI(){
	cout << "Creation de simpleAI" << endl;
}

simpleAI::~simpleAI(){
	cout << "Destruction de simpleAI" << endl;
}

void simpleAI::move(int tableau[10][10]){	
	int x = rand() % 10;
	int y = rand() % 10;

	if(tableau[x][y] == 0 || tableau[x][y] == 3){
		tableau[x][y] = 3;
	}else if(tableau[x][y] == 1){
		tableau[x][y] = 2;
	}else {
		//en cas que la case n'est pas disponible
		move(tableau);
	}	
}
