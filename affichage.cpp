#include "affichage.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Affichage::Affichage(){
	cout << "Creation d'affichage" << endl;
}

Affichage::~Affichage(){
	cout << "Destruction d'affichage" << endl;
}

void Affichage::populerTerrainAI(int ptr[10][10]){
	srand(time(NULL));
	
	for(int k = 0; k < 10; k++){
		for(int j = 0; j < 10; j++){
			ptr[k][j] = 0;
		}
	}

	int x, y;

	for(int i = 0;i < 2; i++){	
		x = rand()%10;
		y = rand()%10;

		ptr[x][y] = 1;
		//dans le vrai code il faut utiliser les classes 
		//mais dans cette petite simulation on va l'ignorer
		if((x+1) < 10 && ptr[x+1][y] != 1){
			ptr[x+1][y] = 1;
		}else if((x-1) >= 0 && ptr[x-1][y] != 1){
			ptr[x-1][y] = 1;
		}else if((y+1) < 10 && ptr[x][y+1] != 1){
			ptr[x][y+1] = 1;
		}else if((y-1) >= 0 && ptr[x][y-1] != 1){
			ptr[x][y-1] = 1;
		}
	}
}

void Affichage::afficherTerrain(int ptr[10][10]){
	for(int x = 0; x < 10; x++){
		for(int y = 0; y < 10; y++){
			switch(ptr[x][y]){
				case 0:
					cout << " - ";
				break;
				case 1:
					cout << " O ";
				break;
				case 2:
					cout << " X ";
				break;
				case 3:
					cout << " E ";
				break;
			}
		}
		cout << endl;
	}

}
