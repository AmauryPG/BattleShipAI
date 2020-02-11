#include "avancerAI.h"

avancerAI::avancerAI()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			m_distribution[x][y] = 0;
		}
	}
}

avancerAI::~avancerAI()
{ 
}

void avancerAI::afficherDistribution()
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			cout << m_distribution[x][y] << " ";
		}
		cout << endl;
	}
}



void avancerAI::affichageTableau(int tableau[10][10])
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) { 
			cout << tableau[x][y] << " ";
		}
		cout << endl;
	}
}

bool avancerAI::PriorisationZoneTouche(int tableau[10][10])
{
	bool bateauTouche = false;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if (tableau[x][y] == 2)
			{
				bateauTouche = true;

				if (x - 1 >= 0)
					m_distribution[x - 1][y] += 2;
				if (x + 1 < 10)
					m_distribution[x + 1][y] += 2;

				if (y - 1 >= 0)
					m_distribution[x][y - 1] += 2;
				if (y + 1 < 10)
					m_distribution[x][y + 1] += 2;
			}
		}
	}
	return bateauTouche;
}

bool avancerAI::RechercheExhaustif(int tableau[10][10], int longueur)
{  
	bool axeYNegatif = true;
	bool axeYPositif = true;
	bool axeXNegatif = true;
	bool axeXPositif = true;
	//si un bateau peut rentre dans la map
	bool bateau = false;

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{

			if (tableau[x][y] == 0)
			{ 				 
				axeYNegatif = true; 
				axeYPositif = true;
				axeXNegatif = true;
				axeXPositif = true;
				 
				for (int i = 1; i < longueur; i++)
				{ 
					if (x + i >= 10 || tableau[x + i][y] != 0)
						axeXPositif = false;
					if (x - i < 0 || tableau[x - i][y] != 0)
						axeXNegatif = false;

					if (y + i >= 10 || tableau[x][y + i] != 0)
						axeYPositif = false;
					if (y - i < 0 || tableau[x][y - i] != 0)
						axeYNegatif = false;
				}
				 

				for (int k = 0; k < longueur - 1; k++)
				{
					if (axeXPositif)
					{
						m_distribution[x + k][y]++;
						bateau = true;
					}
					if (axeXNegatif)
					{
						m_distribution[x - k][y]++;
						bateau = true;

					}

					if (axeYPositif)
					{
						m_distribution[x][y + k]++;
						bateau = true;
					}

					if (axeYNegatif)
					{
						m_distribution[x][y - k]++;
						bateau = true;
					}
				} 
			}
		}
	} 
	PriorisationZoneTouche(tableau);
	afficherDistribution();
	return bateau;
}