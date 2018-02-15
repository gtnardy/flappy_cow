#include "Poop.h"

Poop::Poop() : GravitationalObject(Vector2(16, 16), Vector2(100, 100), "res/poophappy.png", 1) {
}


Poop::~Poop() {
	GravitationalObject::~GravitationalObject();
}


void Poop::draw(bool paused) {

	if (!active) return;
	if (position.x + size.x < 0) { active = false; }

	if (!paused)
		tick();

	GravitationalObject::draw(true);
}


void Poop::tick() {

	if (crashed) {
		position.x -= 3;
		return;
	}

	if (position.y + size.y >= 530) { 
		crash(550);
		return;
	}

	GravitationalObject::tick();
}

void Poop::crash(int height) {
	if (!crashed) {
		sound->playPoopCrashed();
		crashed = true;

		position.y = height - size.y;
	
	}
}


void Poop::eject(Vector2 _position) {

	_position.x += 5;
	sound->playPoop();
	position = _position;
	timeFree = 0;
	active = true;
	crashed = false;
}