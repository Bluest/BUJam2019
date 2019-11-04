#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <list>

#include "Input.h"
#include "Audio.h"

class Jam
{
private:
	SDL_Window* window = nullptr;
	const int windowWidth = 1600;
	const int windowHeight = 800;

	SDL_Renderer* renderer = nullptr;
	const int rendererScale = 2;

	Input input;
	SDL_Event event;
	Audio sfx;

	void init(SDL_Window* _window, SDL_Renderer** _renderer);

	void update(GameKeys _keysPressed);

public:
	Jam();
	~Jam();

	void run();
};
