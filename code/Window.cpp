#include "Window.h"
#include <iostream>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string & title, int width, int height): 
	_title(title), _height(height), _width(width) {

	_closed = !init();
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
}

void Window::pollEvents(SDL_Event &event) {

	switch (event.type) {
	case SDL_QUIT:
		_closed = true;
		break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			_closed = true;
			break;
		}
		break;

	default:
		break;
	}
}

bool Window::init() {

	if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) != 0) {
		std::cerr << "Erro";
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cerr << "Erro Som";
		return 0;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cerr << "Erro imagem";
		return false;
	}

	if (TTF_Init() == -1) {
		std::cerr << "Erro ttf";
		return false;
	}

	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		SDL_WINDOW_SHOWN
	);

	if (_window == nullptr) {
		std::cerr << "Erro2";
		return false;
	}

	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		std::cerr << "Erro3";
	}

	return true;
}

void Window::clear() const {
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}