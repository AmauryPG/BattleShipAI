#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class simpleAI{
public:
	simpleAI();
	~simpleAI();

	void move(int tableau[10][10]);
	void placement(int tableau[10][10]);
};
