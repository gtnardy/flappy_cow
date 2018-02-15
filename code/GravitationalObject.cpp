#include "GravitationalObject.h"



GravitationalObject::GravitationalObject(Vector2 _size, Vector2 _position, string image_path, double _weight): Object(_size, _position, image_path) {
	weight = _weight;
}


GravitationalObject::~GravitationalObject() {
}


bool GravitationalObject::draw(bool paused) {
	if (!paused)
		tick();
	return Object::draw(paused);
}


void GravitationalObject::tick() {
	timeFree++;
	position.y += timeFree / weight;
}
