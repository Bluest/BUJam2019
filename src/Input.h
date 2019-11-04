#pragma once
#include <SDL.h>

struct GameKeys
{
	bool mouseLeft;
	bool mouseRight;
	/// bool key;
};

// struct MouseEvents

/*struct GameInputs
{
	GameKeys keysPressed;
	GameKeys keysReleased;
	MouseEvents such as clicks, scrolls and mouse movement?
};*/

class Input
{
private:
	GameKeys keysPressed;
	GameKeys keysHeld;
	// GameKeys keysReleased;

	// GameInputs inputsThisFrame;

	void processKeyDown(SDL_Event* _event);
	void processKeyUp(SDL_Event* _event);
	void processMouseDown(SDL_Event* _event);
	void processMouseUp(SDL_Event* _event);

public:
	bool quit;

	Input();

	GameKeys processInput(SDL_Event* _event);
};
