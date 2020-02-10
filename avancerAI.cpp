#include "avancerAI.h"

void avancerAI::affichagePetitTableau(int tableau[3][3]) 
{
	setTableauVide(tableau);

	tableau[1][1] = 3;

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			switch (tableau[x][y]) {
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

void avancerAI::RechercheExhaustif(int tableau[3][3], int longueur)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			m_distribution[x][y] = 0;
		}
	}

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			//on recherche la distribution possible
			if (tableau[x][y] == 0)
			{
				m_distribution[x][y]++;
				bool axeXPositif = true;
				bool axeYPositif = true;
				bool axeXNegatif = true;
				bool axeYNegatif = true;
				
				for (int i = 1; i < longueur; i++)
				{
					cout << "-------------------" << i << "-------------------" << endl;
					//on check si on est dans les limites
					if (x + i >= 3 || tableau[x + i][y] != 0)
					{					
						axeXPositif = false;
					}
					if (x - i < 0 || tableau[x - i][y] != 0)
					{					
						axeXNegatif = false;
					}

					if (y + i >= 3 || tableau[x][y + 1] != 0)
					{
						axeYPositif = false;
					}
					if (y - i < 0 || tableau[x][y - i] != 0)
					{
						axeYNegatif = false;
					}

					cout << "============================================" << endl;
					cout << axeXNegatif << endl;
					cout << axeXPositif << endl;
					cout << axeYNegatif << endl;
					cout << axeYPositif << endl;
					cout << "============================================" << endl;
				}

				//on ajoute les nombres  
				for (int i = 2; i <= longueur; i++)
				{
					if (axeXPositif)
						m_distribution[x + 1][y]++;

					if (axeXNegatif)
						m_distribution[x - 1][y]++;

					if (axeYPositif)
						m_distribution[x][y + 1]++;

					if (axeYNegatif)
						m_distribution[x][y - i]++;
				} 
			}

			for (int x = 0; x < 3; x++)
			{
				for (int y = 0; y < 3; y++)
				{
					cout << m_distribution[x][y] << " | ";
				}
				cout << endl << "---------" << endl;
			}
			cout << endl;
		}
	}
}