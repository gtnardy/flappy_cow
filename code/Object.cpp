#include "Object.h"
#include <SDL_image.h>
#include <iostream>

Object::Object(Vector2 _size, Vector2 _position, string image_path) {
	position = _position;
	size = _size;

	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Erro load image";
	}

	_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	if (!_texture) {
		std::cerr << "Erro texture";
	}

	SDL_FreeSurface(surface);
}


Object::~Object() {
	SDL_DestroyTexture(_texture);
}


bool Object::draw(bool paused) {

	SDL_Rect rect = { position.x, position.y, size.x, size.y };
	SDL_RenderCopy(Window::renderer, _texture, NULL, &rect);
	return true;
}