#include "mediumAI.h"

#include <cmath>

mediumAI::mediumAI(){
	cout << "Creation de medimAI" << endl;
	m_navire = false; 
	m_direction = 0;
	m_positionX = 0;
	m_positionY = 0;
}

mediumAI::~mediumAI(){
	cout << "Destruction de mediumAI" << endl;
}

void mediumAI::move(int tableau[10][10]){
	//cherche un point bateau
	if(!m_navire){
		cout << "Recherche du bateau" << endl;

		int x = rand() % 10;
		int y = rand() % 10;

		//reduit la recherche par moitie
		if((x % 2) == 1){
			if((rand() % 2) == 0){
				x--;
			}else{
				x++;
			}
		}

		if((y % 2) == 1){
			if((rand() % 2) == 0){
				x--;
			}else{
				x++;
			}
		}

		cout << x << " : " << y << endl;

		if(tableau[x][y] == 1){
			m_navire = true;
			
			m_positionX = x;
			m_positionY = y;

			tableau[x][y] = 2; 
		}else if(tableau[x][y] == 0 || tableau[x][y] == 3){
			tableau[x][y] = 3;
		}
	}else{
		//quand on trouve un point 
		cout << "Chasse du bateau" << endl;	

		if(m_direction == 0 && (m_positionY - 1) >= 0
			&& tableau[m_positionX][m_positionY - 1] == 1){
			
			m_positionY--;
			tableau[m_positionX][m_positionY] = 2;
			m_navire = false;

		}else if(m_direction == 1 && (m_positionX + 1) < 10
			&& tableau[m_positionX + 1][m_positionY] == 1){
			
			m_positionX++;
			tableau[m_positionX][m_positionY] = 2;
			m_navire = false;

		}else if(m_direction == 2 && (m_positionY + 1) < 10
			&& tableau[m_positionX][m_positionY + 1] == 1){

			m_positionY++;
			tableau[m_positionX][m_positionY] = 2;
			m_navire = false;

		}else if(m_direction == 2 && (m_positionX - 1) >= 0
			&& tableau[m_positionX - 1][m_positionY] == 1){
			
			m_positionX--;
			tableau[m_positionX][m_positionY] = 2;
			m_navire = false;
		}else{
		//changer de direction de la recherche
			if((m_direction + 1) == 4){
				m_direction = 0;
			}else{
				m_direction++;
			}
		}
	}	
}

void mediumAI::placement(int tableau[10][10])
{

}