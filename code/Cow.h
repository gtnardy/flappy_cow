#pragma once
#include "GravitationalObject.h"
#include "Poop.h"
#include "Lista.h"

using namespace std;

class Cow :
	public GravitationalObject {

public:
	Cow();
	~Cow();
	void draw(bool paused);
	bool checkCollision();
	void tick();

	void jump(Sound *sound);
	void evacuatePoop(Sound *sound);
	void reset();

	Lista<Poop> *poops;

	bool jumping = false;

};

