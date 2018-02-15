#pragma once
#include "Object.h"
#include "Obstacle.h"

using namespace std;


class Scenario {

public:

	Scenario();
	~Scenario();
	void reset();


	Object *background;
	Object *floor;

	int time = 0;
	Lista<Obstacle> *obstacles;

	void tick(bool paused, int score);

	void generateObstacle(int score);

};

