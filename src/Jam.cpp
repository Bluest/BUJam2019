#include "Jam.h"

Jam::Jam()
{
	init(window, &renderer);
}

void Jam::init(SDL_Window* _window, SDL_Renderer** _renderer)
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

	*_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr)
	{
		printf("SDL Renderer could not be created! SDL Error:");
		throw std::exception(SDL_GetError());
	}

	SDL_RenderSetLogicalSize(*_renderer, windowWidth / rendererScale, windowHeight / rendererScale);
	SDL_SetRenderDrawColor(*_renderer, 0, 0, 32, 255);
}

void Jam::run()
{
	while (!input.quit)
	{
		update(input.processInput(&event));
		// draw();
		// delta time;
	}
}

void Jam::update(GameKeys _keysPressed)
{
	if (_keysPressed.mouseLeft)
	{
		std::cout << "LMB pressed" << std::endl;
		//sfx.loadEffect("Assets/Gun-Shot.wav");
		//sfx.play();
	}

	if (_keysPressed.mouseRight)
	{
		std::cout << "RMB pressed" << std::endl;
	}

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

Jam::~Jam()
{
	std::cout << "Quitting..." << std::endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_Quit();
	SDL_Quit();
}
