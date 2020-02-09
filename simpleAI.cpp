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

void simpleAI::placement(int tableau[10][10]) {

	setTableauVide(tableau);

	srand(time(NULL));

	int x, y;
	bool loop = true;

	for (int i = 0; i < 2; i++) {
		x = rand() % 10;
		y = rand() % 10;

		if(tableau[x][y] == 0)
		{
			tableau[x][y] = 1;
		}
		else 
		{
			do {
				x = rand() % 10;
				y = rand() % 10;
			} while (tableau[x][y] != 0);
		}
		//dans le vrai code il faut utiliser les classes 
		//mais dans cette petite simulation on va l'ignorer

		do {
			switch (rand() % 4) {
			case 0:
				if ((x + 1) < 10 && tableau[x + 1][y] != 1 && tableau[x + 1][y] == 0) {
					tableau[x + 1][y] = 1;
					loop = false;
				}
				break;
			case 1:
				if ((x - 1) >= 0 && tableau[x - 1][y] != 1 && tableau[x - 1][y] == 0) {
					tableau[x - 1][y] = 1;
					loop = false;
				}
				break;
			case 2:
				if ((y + 1) < 10 && tableau[x][y + 1] != 1 && tableau[x][y + 1] == 0) {
					tableau[x][y + 1] = 1;
					loop = false;
				}
				break;
			case 3:
				if ((y - 1) >= 0 && tableau[x][y - 1] != 1 && tableau[x][y - 1] == 0) {
					tableau[x][y - 1] = 1;
					loop = false;
				}
				break;
			}
		} while (loop);
	}
}