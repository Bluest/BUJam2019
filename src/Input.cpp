#include "Input.h"

Input::Input()
{
	keysPressed = { false, false };
	keysHeld = { false, false };

	quit = false;
}

void Input::processKeyDown(SDL_Event* _event)
{
	switch (_event->key.keysym.sym)
	{
	/// case SDL_Keycode: { keysPressed.key = true; keysHeld.key = true; break; }
	}
}

void Input::processKeyUp(SDL_Event* _event)
{
	switch (_event->key.keysym.sym)
	{
	/// case SDL_Keycode: { /*keysReleased.key = true;*/ keysHeld.key = false; break; }
	}
}

void Input::processMouseDown(SDL_Event* _event)
{
	switch (_event->button.button)
	{
	case SDL_BUTTON_LEFT: { keysPressed.mouseLeft = true; break; }
	case SDL_BUTTON_RIGHT: { keysPressed.mouseRight = true; break; }
	}
}

void Input::processMouseUp(SDL_Event* _event)
{
	switch (_event->button.button)
	{
	case SDL_BUTTON_LEFT: { keysPressed.mouseLeft = true; break; }
	case SDL_BUTTON_RIGHT: { keysPressed.mouseRight = true; break; }
	}
}

GameKeys Input::processInput(SDL_Event* _event)
{
	keysPressed = { false, false };

	while (SDL_PollEvent(_event))
	{
		switch (_event->type)
		{
		case SDL_KEYDOWN: { processKeyDown(_event); break; }
		case SDL_KEYUP: { processKeyUp(_event); break; }
		case SDL_MOUSEBUTTONDOWN: { processMouseDown(_event); break; }
		case SDL_MOUSEBUTTONUP: { processMouseUp(_event); break; }
		case SDL_QUIT: { quit = true; break; }
		}
	}

	return keysPressed; // return inputsThisFrame
}
