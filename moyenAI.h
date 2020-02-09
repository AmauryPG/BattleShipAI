#pragma once
#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "AI.h"

class moyenAI : public AI { 
public:
	moyenAI();
	~moyenAI();

	void move(int tableau[10][10]);
	void placement(int tableau[10][10]); 

};
