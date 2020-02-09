#pragma once
#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class moyenAI  {
private:
	void setTableauVide(int tableau[10][10]);

public:
	moyenAI();
	~moyenAI();

	void move(int tableau[10][10]);
	void placement(int tableau[10][10]); 

};
