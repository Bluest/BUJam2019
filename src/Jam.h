#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Jam
{
private:
	const int windowWidth = 200;
	const int windowHeight = 200;
	const int rendererScale = 2;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	void init(SDL_Window* _window, SDL_Renderer* _renderer);

public:
	Jam();
	~Jam();

	void run();
};
