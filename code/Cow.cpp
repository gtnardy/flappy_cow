#include "Cow.h"
#include <iostream>
#include <cmath>


Cow::Cow(): GravitationalObject(Vector2(25, 38), Vector2(381, 300), "res/cow.png", 4) {
	//poops = new Fila<Poop>();
	poops = new Lista<Poop>();
}


Cow::~Cow() {
	Object::~Object();
}


void Cow::reset() {
	position.y = 300;
	timeFree = 0;
	jumping = false;
	poops->clear();

}

void Cow::draw(bool paused) {

	if (!paused)
		tick();

	SDL_Rect dstrect = { jumping? 0 : size.x, 0, size.x, size.y };
	SDL_Rect rect = { position.x, position.y, size.x * 2, size.y };

	SDL_RenderCopy(Window::renderer, _texture, &dstrect, &rect);
}


bool Cow::checkCollision() {
	return (position.y <= 0 || position.y + size.y >= 550);
}


void Cow::tick(){

	if (jumping) {
		if (timeFree >= 25) {
			jumping = false;
			timeFree = 0;
			weight = 4;
		} else {
			//timeFree / weight;

			//weight = timeFree / timeFree  /25;
			timeFree++;
			position.y -= ceil((25 - timeFree) / 4);
		}
	} else {
		GravitationalObject::tick();
	}
}


void Cow::jump(Sound *sound) {
	jumping = true;
	timeFree = 0;
	evacuatePoop(sound);
}


void Cow::evacuatePoop(Sound *sound) {

	Poop *poop = new Poop();
	poop->sound = sound;
	poop->eject(position);
	poops->addLast(poop);

}