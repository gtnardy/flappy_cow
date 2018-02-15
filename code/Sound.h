#pragma once
#include "SDL_mixer.h"
#include <string>


class Sound {
public:
	Sound();
	~Sound();

	void playBackground();
	void stopBackground();
	void playPoop();
	void playPoopCrashed();
	void playBeepSound();

	Mix_Music *background;
	Mix_Chunk *poopSound;
	Mix_Chunk *poopCrashedSound;
	Mix_Chunk *beepSound;
};

