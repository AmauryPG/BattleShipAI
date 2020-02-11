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
			tableau[x][y] = 0;
			cout << tableau[x][y] << " ";
		}
		cout << endl;
	}
}

void avancerAI::RechercheExhaustif(int tableau[10][10], int longueur)
{ 
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{

			if (tableau[x][y] == 0)
			{ 				 
				bool axeYNegatif = true; 
				bool axeYPositif = true;
				bool axeXNegatif = true;
				bool axeXPositif = true;
				 
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
						m_distribution[x + k][y]++;
					if (axeXNegatif)
						m_distribution[x - k][y]++;

					if (axeYPositif)
						m_distribution[x][y + k]++;
					if (axeYNegatif)
						m_distribution[x][y - k]++;
				} 
			}
		}
	}
	afficherDistribution();
}