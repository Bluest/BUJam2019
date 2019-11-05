#include "Jam.h"
#include "GameObject.h"

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

	IMG_Init(IMG_INIT_PNG);

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

	///Test object delete this
	//addGameObject(std::make_shared<GameObject>("yes", 2, 2, NULL));
}

/*template <typename T>
void Jam::addGameObject(std::shared_ptr<T> _gameObject)
{
	if (_gameObject = std::static_pointer_cast<GameObject>())
	{
		gameObjects.push_back(_gameObject); //Add game object to the list of objects
	}

	throw std::exception();
}*/

void Jam::run()
{
	while (!input.quit)
	{
		update(input.processInput(&event));
		draw();
		// delta time;
	}
}

void Jam::update(InputsThisFrame _inputsThisFrame)
{
	for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		(*it)->Update();
	}

	if (_inputsThisFrame.lmbPress) std::cout << "LMB pressed" << std::endl;
	if (_inputsThisFrame.lmbRelease) std::cout << "LMB released" << std::endl;
	if (_inputsThisFrame.rmbPress) std::cout << "RMB pressed" << std::endl;
	if (_inputsThisFrame.rmbRelease) std::cout << "RMB released" << std::endl;

	if (input.keysHeld.w) std::cout << "^";
	if (input.keysHeld.a) std::cout << "<";
	if (input.keysHeld.s) std::cout << "v";
	if (input.keysHeld.d) std::cout << ">";
	if (input.keysHeld.mouseLeft) std::cout << "A";
	if (input.keysHeld.mouseRight) std::cout << "B";
}

void Jam::draw()
{
	/*
	SDL_RenderClear(renderer);
	for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		SDL_RenderCopy(renderer, it->sprite->tex, it->cellRect, it->pos);
	}
	SDL_RenderPresent(renderer);
	*/

	SDL_Texture* shipSprite = IMG_LoadTexture(renderer, /* Remove "../" when we're finished! */ "../Sprites/ship.png");
	SDL_Rect shipPos = { 100, 0, 600, 400 };

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, shipSprite, nullptr, &shipPos);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(shipSprite);
}

Jam::~Jam()
{
	std::cout << "Quitting..." << std::endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}
