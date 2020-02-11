#include <iostream>
using namespace std;

#include "avancerAI.h"

int main()
{
	int tableau[10][10];
	avancerAI ai;

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			tableau[x][y] = 0; 
		} 
	}

	tableau[4][4] = 2;

	ai.affichageTableau(tableau);
	cout << "--------------------------" << endl;

	ai.RechercheExhaustif(tableau, 2); 

	return 0;
}

/*
#include "affichage.h"  
#include "simpleAI.h"
#include "moyenAI.h"
#include "AI.h"

int main(void) {
	int tableau[10][10];

	Affichage affi;  
	moyenAI ai;

	ai.placement(tableau);
	affi.afficherTerrain(tableau);

	cout << "---- AI move ----" << endl;
	for (int tour = 1; tour <= 10; tour++) {
		cout << "---- Tour : " << tour << " ----" << endl;
		 
		ai.move(tableau);

		affi.afficherTerrain(tableau);
	}
	return 0;
}
*/