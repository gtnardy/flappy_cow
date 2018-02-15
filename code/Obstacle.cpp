#include "Obstacle.h"
#include <time.h>
#include <iostream>

Obstacle::Obstacle(int size) {

	middle = rand() % 250 + 150;

	obstacleDown = new Object(Vector2(40, 800), Vector2(1000, middle - 800 - size), "res/obstacledown.png");
	obstacleUp = new Object(Vector2(40, 800), Vector2(1000, middle + size), "res/obstacleup.png");
}


Obstacle::~Obstacle() {
	//obstacleUp->~Object();
	//obstacleDown->~Object();
}


void Obstacle::tick(int score) {
	obstacleUp->position.x -= 3;
	obstacleDown->position.x -= 3;
}

bool Obstacle::checkCollision(int x, int y, int w, int h) {

	return (x + w > obstacleUp->position.x &&
		x < obstacleUp->position.x + obstacleUp->size.x &&
		abs(y + h / 2 - middle) > 100 - h / 2
	);
}


void Obstacle::draw(bool paused, int score) {
	if (obstacleUp->position.x + obstacleUp->size.x < 0) {
		return;
	}

	if (!paused)
		tick(score);

	obstacleUp->draw(paused);
	obstacleDown->draw(paused);
}