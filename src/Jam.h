#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Jam
{
private:
	SDL_Window* window = nullptr;
	const int windowWidth = 200;
	const int windowHeight = 200;

	SDL_Renderer* renderer = nullptr;
	const int rendererScale = 2;

	void init(SDL_Window* _window, SDL_Renderer* _renderer);

public:
	Jam();
	~Jam();

	void run();
};
