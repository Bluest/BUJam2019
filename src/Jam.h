#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <list>

#include "Input.h"
#include "Audio.h"

class GameObject;

class Jam
{
private:
	SDL_Window* window = nullptr;
	const int windowWidth = 1600;
	const int windowHeight = 800;

	SDL_Renderer* renderer = nullptr;
	const int rendererScale = 2;

	std::list<std::shared_ptr<GameObject>> gameObjects;

	Input input;
	SDL_Event event;
	Audio sfx;

	//Functions
	void init(SDL_Window* _window, SDL_Renderer** _renderer);

	//template<typename T>
	//void addGameObject(std::shared_ptr<T> _gameObject);

	void start();
	void update(GameKeys _keysPressed);
	void draw();

public:
	Jam();
	~Jam();

	void run();
};
