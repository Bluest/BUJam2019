#include "Jam.h"

Jam::Jam()
{
	init(window, renderer);
}

void Jam::init(SDL_Window* _window, SDL_Renderer* _renderer)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		printf("SDL could not initialize! SDL Error:");
		throw std::exception(SDL_GetError());
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		printf("SDL_Mixer could not initialize! SDL Error:");
		throw std::exception(SDL_GetError());
	}

	_window = SDL_CreateWindow("Jam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight,
	                           SDL_WINDOW_SHOWN);
	if (_window == nullptr)
	{
		printf("SDL Window could not be created SDL Error:");
		throw std::exception(SDL_GetError());
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr)
	{
		printf("SDL Renderer could not be created! SDL Error:");
		throw std::exception(SDL_GetError());
	}

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
