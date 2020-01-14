#include <iostream>
using namespace std;

#include "affichage.h"
#include "simpleAI.h"
#include "mediumAI.h"

int main(void){
	Affichage affi;	
	mediumAI ai;
	int tableau[10][10];

	affi.populerTerrainAI(tableau);
	affi.afficherTerrain(tableau);	
	
	cout << "---- AI move ----" << endl;
	for(int tour = 1; tour <= 10; tour++){
		cout << "---- Tour : " << tour << " ----" << endl;		

		ai.move(tableau);	
		
		affi.afficherTerrain(tableau);
	}
	return 0;
}
