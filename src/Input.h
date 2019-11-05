#pragma once
#include <SDL.h>

struct KeysHeld
{
	bool w;
	bool a;
	bool s;
	bool d;
	bool mouseLeft;
	bool mouseRight;
};

struct InputsThisFrame
{
	bool lmbPress;
	bool lmbRelease;
	bool rmbPress;
	bool rmbRelease;
};

class Input
{
private:
	InputsThisFrame inputsThisFrame;

	void processKeyDown(SDL_Event* _event);
	void processKeyUp(SDL_Event* _event);
	void processMouseDown(SDL_Event* _event);
	void processMouseUp(SDL_Event* _event);

public:
	KeysHeld keysHeld;
	bool quit;

	Input();

	InputsThisFrame processInput(SDL_Event* _event);
};
