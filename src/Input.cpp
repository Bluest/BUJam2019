#include "Input.h"

Input::Input()
{
	keysHeld = { false, false, false, false };

	quit = false;
}

void Input::processKeyDown(SDL_Event* _event)
{
	switch (_event->key.keysym.sym)
	{
	case SDLK_w: { keysHeld.w = true; break; }
	case SDLK_a: { keysHeld.a = true; break; }
	case SDLK_s: { keysHeld.s = true; break; }
	case SDLK_d: { keysHeld.d = true; break; }
	}
}

void Input::processKeyUp(SDL_Event* _event)
{
	switch (_event->key.keysym.sym)
	{
	case SDLK_w: { keysHeld.w = false; break; }
	case SDLK_a: { keysHeld.a = false; break; }
	case SDLK_s: { keysHeld.s = false; break; }
	case SDLK_d: { keysHeld.d = false; break; }
	}
}

void Input::processMouseDown(SDL_Event* _event)
{
	switch (_event->button.button)
	{
	case SDL_BUTTON_LEFT: { inputsThisFrame.lmbPress = true; break; }
	case SDL_BUTTON_RIGHT: { inputsThisFrame.rmbPress = true; break; }
	}
}

void Input::processMouseUp(SDL_Event* _event)
{
	switch (_event->button.button)
	{
	case SDL_BUTTON_LEFT: { inputsThisFrame.lmbRelease = true; break; }
	case SDL_BUTTON_RIGHT: { inputsThisFrame.rmbRelease = true; break; }
	}
}

InputsThisFrame Input::processInput(SDL_Event* _event)
{
	inputsThisFrame = { false, false, false, false };

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

	return inputsThisFrame;
}
