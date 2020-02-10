#include <iostream>
using namespace std;

#include "avancerAI.h"

int main()
{
	int tableau[3][3];
	avancerAI ai;

	ai.affichagePetitTableau(tableau);

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