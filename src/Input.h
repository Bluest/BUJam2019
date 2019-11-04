#pragma once
#include <SDL.h>

struct GameKeys
{
	bool mouseLeft;
	bool mouseRight;
	/// bool key;
};

class Input
{
private:
	/// bool holdKey;

	GameKeys keysPressed;
	GameKeys keysHeld;

	void processKeyDown(SDL_Event* _event);
	void processKeyUp(SDL_Event* _event);
	void processMouseDown(SDL_Event* _event);
	void processMouseUp(SDL_Event* _event);

public:
	bool quit;

	Input();

	GameKeys processInput(SDL_Event* _event);
};
