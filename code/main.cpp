#include "Window.h"
#include "Cow.h"
#include "Text.h"
#include "Scenario.h"
#include "Poop.h"
#include "Obstacle.h"
#include "Sound.h"
#include <iostream>

bool playing = false;
bool lost = false;
Cow *cow;
Scenario *scenario;
Sound *sound;
int score = 0;
Text *text;

void toLost() {
	lost = true;
	sound->playBeepSound();
	sound->stopBackground();
}


void toScore(int s) {
	score = s;
	delete text;
	text = new Text(Window::renderer, "res/flappy.ttf", 46, std::to_string(score), { 255, 255, 255, 255 });
}

void pollEvents(Window &window) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		window.pollEvents(event);	
		
		switch (event.type) {
		case SDL_KEYDOWN:

			if (!lost) {
				cow->jump(sound);
				toScore(score + 1);
			}
			
			if (!playing) 
				sound->playBackground();

			playing = true;

			if (lost) {
				lost = false;
				playing = false;
				toScore(0);
				cow->reset();
				scenario->reset();
			}
			break;

		default:
			break;
		}
	}
}


int main(int argc, char *argv[]) {

	const int FPS = 60;
	int frameTime = 0;

	Window window("Flappy Cow", 800, 600);

	sound = new Sound();
	
	cow = new Cow();
	scenario = new Scenario();

	Object getReady(Vector2(186, 43), Vector2(307, 200), "res/get-ready.png");
	Object tapAny(Vector2(120, 36), Vector2(390, 340), "res/tap-any.png");
	Object gameOver(Vector2(189, 38), Vector2(305, 200), "res/game-over.png");
	Object title(Vector2(313, 68), Vector2(243, 100), "res/flappy-cow.png");

	while (!window.isClosed()) {

		pollEvents(window);

		// seta se está pausado
		bool paused = !playing || lost;

		frameTime++;
		// 60 frames por segundo
		if (FPS / frameTime == 60) {
			frameTime = 0;

			if (!lost)
				// desliza o cenário
				scenario->tick(paused, score);
		}

		// desenha a imagem de background
		scenario->background->draw(paused);

		if (!lost && cow->checkCollision()) {
			toLost();
		}

		// itera entre os obstáculos
		Obstacle *iObstacle = scenario->obstacles->first;
		while (iObstacle != nullptr) {

			Poop *iPoop = cow->poops->first;
			while (iPoop != nullptr) {
				if (iObstacle->checkCollision(iPoop->position.x, iPoop->position.y + iPoop->size.y, iPoop->size.x, iPoop->size.y)
					&& iPoop->position.y < iObstacle->obstacleUp->position.y + 10) {
					iPoop->crash(iObstacle->obstacleUp->position.y);
				}
				iPoop = iPoop->next;
			}

			// desenha o obstáculo
			iObstacle->draw(paused, score);
			if (!lost)
				// checa se colidiu e perdeu o jogo
				if (iObstacle->checkCollision(cow->position.x, cow->position.y, cow->size.x, cow->size.y)) {
					toLost();
				}

			iObstacle = iObstacle->next;
		}

		// desenha o chão
		scenario->floor->draw(paused);

		// itera entre os poops
		Poop *iPoop = cow->poops->first;
		while (iPoop != nullptr) {
			iPoop->draw(paused);

			if (iPoop->position.x < 100)
				cow->poops->remove(iPoop);

			iPoop = iPoop->next;

		}

		// desenha o título se não estiver jogando
		if (!playing) {
			title.draw(paused);
			getReady.draw(paused);
			tapAny.draw(paused);
		} else
			// desenha o score
			text->display(390, 20, Window::renderer);

		// desenha a vaca
		cow->draw(paused);

		// se perdeu desenha a mensagem de perda
		if (lost)
			gameOver.draw(paused);

		window.clear();
	}

	return 0;
}