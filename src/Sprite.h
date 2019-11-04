#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Sprite
{
private:
	SDL_Texture* tex;

	int cellsInRow;
	int cellsInColumn;

	int width;
	int height;
	int speed;

public:
	Sprite(SDL_Renderer* _renderer, char* _textureSheet, int _w, int _h, int _cellsRow, int _cellsCol, int _speed);
	~Sprite();

	SDL_Texture* ReturnTex() { return tex; }

	int GetCellsRow() { return cellsInRow; }
	int GetCellsCol() { return cellsInColumn; }

	int GetWidth() { return width; }
	int GetHeight() { return height; }

	int GetSpeed() { return speed; }

};
