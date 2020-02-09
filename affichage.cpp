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
