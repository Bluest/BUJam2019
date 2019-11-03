#include "Jam.h"

Jam::Jam()
{
	init(window, renderer);
}

void Jam::init(SDL_Window* _window, SDL_Renderer* _renderer)
{
	SDL_Init(SDL_INIT_VIDEO);

	_window = SDL_CreateWindow("Jam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	SDL_RenderSetLogicalSize(_renderer, windowWidth / rendererScale, windowHeight / rendererScale);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
}

void Jam::run()
{
	for (int i = 1; i <= 10; i++)
	{
		std::cout << i << std::endl;
	}
}

Jam::~Jam()
{
	std::cout << "Quitting..." << std::endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
