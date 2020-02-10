#pragma once
#include <iostream>
using namespace std;

class avancerAI {
private:
	int m_distribution[3][3];

	void setTableauVide(int tableau[3][3])
	{
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				tableau[x][y] = 0;
			}
		}
	}

public:
	avancerAI() {};

	~avancerAI() {};

	void affichagePetitTableau(int tableau[3][3]);

	void RechercheExhaustif(int tableau[3][3], int longueur);
};
