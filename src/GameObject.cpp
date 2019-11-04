#include "Sprite.h"
#include "Input.h"

#include "GameObject.h"

GameObject::GameObject(std::string _name, float _posX, float _posY, std::shared_ptr<Sprite> _sprite)
{
	name = _name;
	xPos = _posX;
	yPos = _posY;

	sprite = _sprite;
}

void GameObject::Update()
{


	Draw();
}

void GameObject::Draw()
{

}

GameObject::~GameObject()
{

}