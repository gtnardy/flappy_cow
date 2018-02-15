#pragma once

#include "Window.h"
#include "Vector2.h"
#include <string>

using namespace std;

class Object {

public:
	Object(Vector2 _position, Vector2 _size, string image_path);
	~Object();

	bool draw(bool paused);

	Vector2 position, size;

protected:
	SDL_Texture *_texture = nullptr;
};

