#pragma once
#include "GameObject.h"

class Invader : public GameObject
{
public:
	Invader(std::string _name, float _posX, float _posY, std::shared_ptr<Sprite> _sprite);
	~Invader();
};
