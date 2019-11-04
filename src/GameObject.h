#pragma once
#include <memory>
#include <string>

class Sprite;
class Input;

class GameObject
{
private:
	std::shared_ptr<Sprite> sprite;
	std::shared_ptr<Input> input;

	std::string name;

	float xPos, yPos;
	bool is_Interactable;

public:
	GameObject(std::string _name, float _posX, float _posY, std::shared_ptr<Sprite> _sprite);

	virtual void Update();

	void Draw();

	~GameObject();
};