#include <iostream>
using namespace std;

class Affichage{
private:
	void terrainNull();
public: 
	Affichage();
	~Affichage();

	void afficherTerrain(int ptr[10][10]);
	void populerTerrainZero(int ptr[10][10]);
};
