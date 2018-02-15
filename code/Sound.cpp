#include "Sound.h"
#include <iostream>

Sound::Sound() {

	background = Mix_LoadMUS("res/musica.mp3");
	poopSound = Mix_LoadWAV("res/cagada.wav");
	beepSound = Mix_LoadWAV("res/beep.wav");
	poopCrashedSound = Mix_LoadWAV("res/poopcrash.wav");
}

Sound::~Sound() {
	Mix_FreeChunk(poopSound);
	Mix_FreeChunk(poopCrashedSound);
	Mix_FreeChunk(beepSound);
	Mix_FreeMusic(background);
}

void Sound::playBackground() {
	Mix_VolumeMusic(128);
	if (!Mix_PlayingMusic())
		Mix_PlayMusic(background, -1);
	//else
		//Mix_ResumeMusic();

}

void Sound::stopBackground() {
	//Mix_PauseMusic();
	Mix_VolumeMusic(16);
}

void Sound::playPoop() {
	Mix_PlayChannel(-1, poopSound, 0);
}

void Sound::playBeepSound() {
	Mix_PlayChannel(-1, beepSound, 0);
}

void Sound::playPoopCrashed() {
	Mix_PlayChannel(-1, poopCrashedSound, 0);
}
