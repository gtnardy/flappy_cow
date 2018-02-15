#pragma once
#include "Object.h"
#include "Lista.h"

class Obstacle: public No<Obstacle> {
public:
	Obstacle(int _size);
	~Obstacle();

	void tick(int score);

	bool checkCollision(int x, int y, int w, int h);

	void draw(bool paused, int score);

	int middle = 300;

	Object *obstacleUp, *obstacleDown;
};

