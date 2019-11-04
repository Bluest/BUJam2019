#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* _renderer, char* _textureSheet, int _w, int _h, int _cellsRow, int _cellsCol, int _speed)
{
	tex = IMG_LoadTexture(_renderer, _textureSheet);
	width = _w;
	height = _h;
	cellsInRow = _cellsRow;
	cellsInColumn = _cellsCol;
	speed = _speed;
}

Sprite::~Sprite()
{

}