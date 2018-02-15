#pragma once
#include "GravitationalObject.h"
#include "Sound.h"
#include "Lista.h"

class Poop :
	public GravitationalObject, public No<Poop> {
public:
	Poop();
	~Poop();

	void draw(bool paused);
	void tick();
	void crash(int height);

	void eject(Vector2 position);

	Sound *sound;

	bool crashed = false;
	bool active = false;
};

