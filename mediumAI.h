#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "AI.h"

class mediumAI : public AI{
public:
	mediumAI();
	~mediumAI();

	void move(int tableau[10][10]);
	void placement(int tableau[10][10]);
};
