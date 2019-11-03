#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Jam
{
private:
	const int windowW = 200;
	const int windowH = 200;
	const int rendererScale = 2;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	void init(SDL_Window** _window, SDL_Renderer** _renderer);

public:
	Jam();

	void run();
	void quit();
};
