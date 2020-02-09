#include <iostream>
using namespace std;

#include "affichage.h"
#include "simpleAI.h"
#include "mediumAI.h"
#include "AI.h"

int main(void){
	Affichage affi;	
	simpleAI simple;
	mediumAI medium;

	AI* ordi;

	ordi = &simple;

	int tableau[10][10];

	affi.populerTerrainZero(tableau);

	ordi->placement(tableau);

	affi.afficherTerrain(tableau);	
	
	cout << "---- AI move ----" << endl;
	for(int tour = 1; tour <= 10; tour++){
		cout << "---- Tour : " << tour << " ----" << endl;		

		ordi->move(tableau);	
		
		affi.afficherTerrain(tableau);
	}
	return 0;
}
