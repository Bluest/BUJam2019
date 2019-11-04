#include "Defender.h"

Defender::Defender(std::string _name, float _posX, float _posY, std::shared_ptr<Sprite> _sprite) : GameObject(_name, _posX, _posY, _sprite)
{

}

void Defender::wait(float _cooldownTime)
{
	
}

void Defender::checkPower()
{
	if (currPower < 0)
	{
		currPower = 0;
	}
}

void Defender::updatePower()
{

}

void Defender::Update()
{

	checkPower();
}

Defender::~Defender()
{
}