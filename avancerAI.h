#pragma once
#include <iostream>
using namespace std;

class avancerAI {
private:
	int m_distribution[10][10];

	void setTableauVide(int tableau[10][10])
	{
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 10; y++)
			{
				tableau[x][y] = 0;
			}
		}
	}

	void afficherDistribution();

public:
	avancerAI();

	~avancerAI();

	void affichageTableau(int tableau[10][10]);

	bool RechercheExhaustif(int tableau[10][10], int longueur);
	bool PriorisationZoneTouche(int tableau[10][10]);
};
