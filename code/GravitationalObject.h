#pragma once
#include "Object.h"
class GravitationalObject :
	public Object {
public:
	GravitationalObject(Vector2 _size, Vector2 _position, string image_path, double _weight);
	~GravitationalObject();

	bool draw(bool paused);

	void tick();

	int timeFree = 0;
	double weight;
};

