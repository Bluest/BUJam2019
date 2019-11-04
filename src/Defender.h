#pragma once

#include <ctime>
#include "GameObject.h"

class Defender : public GameObject
{
private:

	int maxPower, currPower; //Power system

	//Functions
	void wait(float _cooldownTime);
	void checkPower(); //Check current power and prevent it from going bellow 0
	void updatePower(); //Update the current power

public:
	Defender(std::string _name, float _posX, float _posY, std::shared_ptr<Sprite> _sprite);

	void Update();

	~Defender();
};