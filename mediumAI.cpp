#include "mediumAI.h"

#include <cmath>

mediumAI::mediumAI(){
	cout << "Creation de medimAI" << endl; 
}

mediumAI::~mediumAI(){
	cout << "Destruction de mediumAI" << endl;
}

void mediumAI::move(int tableau[10][10]){
	bool navire = false;
	/*
		0
	  3 X 1
		2
	*/
	int direction = 0;
	int positionX = 0;
	int positionY = 0;

	//cherche un point bateau
	if(!navire){
		cout << "Recherche du bateau" << endl;

		int x = rand() % 10;
		int y = rand() % 10;

		//reduit la recherche par moitie
		if((x % 2) == 1){
			if((rand() % 2) == 0){
				x--;
			}else{
				x++;
			}
		}

		if((y % 2) == 1){
			if((rand() % 2) == 0){
				x--;
			}else{
				x++;
			}
		}

		cout << x << " : " << y << endl;

		if(tableau[x][y] == 1){
			navire = true;
			
			positionX = x;
			positionY = y;

			tableau[x][y] = 2; 
		}else if(tableau[x][y] == 0 || tableau[x][y] == 3){
			tableau[x][y] = 3;
		}
	}else{
		//quand on trouve un point 
		cout << "Chasse du bateau" << endl;	

		if(direction == 0 && (positionY - 1) >= 0
			&& tableau[positionX][positionY - 1] == 1){
			
			positionY--;
			tableau[positionX][positionY] = 2;
			navire = false;

		}else if(direction == 1 && (positionX + 1) < 10
			&& tableau[positionX + 1][positionY] == 1){
			
			positionX++;
			tableau[positionX][positionY] = 2;
			navire = false;

		}else if(direction == 2 && (positionY + 1) < 10
			&& tableau[positionX][positionY + 1] == 1){

			positionY++;
			tableau[positionX][positionY] = 2;
			navire = false;

		}else if(direction == 2 && (positionX - 1) >= 0
			&& tableau[positionX - 1][positionY] == 1){
			
			positionX--;
			tableau[positionX][positionY] = 2;
			navire = false;
		}else{
		//changer de direction de la recherche
			if((direction + 1) == 4){
				direction = 0;
			}else{
				direction++;
			}
		}
	}	
}

void mediumAI::placement(int tableau[10][10])
{
	setTableauVide(tableau);

	srand(time(NULL));

	int x = rand() % 10;
	int y = rand() % 10;
	bool loop = false;

	if (tableau[x][y] == 0)
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
	
	////////////////////////////////////placement strategique////////////////////////////////////


}