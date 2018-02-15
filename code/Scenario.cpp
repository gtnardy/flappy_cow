#include "Scenario.h"
#include "Obstacle.h"
#include "Object.h"
#include <iostream>

Scenario::Scenario() {

	background = new Object(Vector2(2216, 600), Vector2(0, 0), "res/background-large.png");
	floor = new Object(Vector2(1196, 50), Vector2(0, 550), "res/floor.png");

	obstacles = new Lista<Obstacle>;
}


Scenario::~Scenario() {
}


void Scenario::reset() {
	obstacles->clear();
	time = 0;
}


void Scenario::tick(bool paused, int score) {
	if (!paused) {
		time++;
		if (time >= 100 - score / 5) {
			time = 0;
			generateObstacle(score);
		}
	}

	background->position.x -= 2;
	floor->position.x -= 3;

	if (background->position.x < -275)
		background->position.x = 0;

	if (floor->position.x < -299)
		floor->position.x = 0;
}

void Scenario::generateObstacle(int score) {
	obstacles->addLast(new Obstacle(100 - score / 5));
}
