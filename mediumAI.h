#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class mediumAI{
private:
	bool m_navire;
	/*
		0
	  3 X 1
		2
	*/
	int m_direction; 
	int m_positionX, m_positionY;
public:
	mediumAI();
	~mediumAI();

	void move(int tableau[10][10]);
	void placement(int tableau[10][10]);
};
