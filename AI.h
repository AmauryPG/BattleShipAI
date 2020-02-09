#pragma once
#include <iostream>
using namespace std;

class AI {
public:
	AI() {};
	virtual ~AI() {};

	virtual void move(int tableau[10][10])
	{
		cout << "move de AI" << endl;
	}
	virtual void placement(int tableau[10][10])
	{
		cout << "placement de AI" << endl;
	}


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
};