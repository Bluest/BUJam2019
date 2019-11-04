#pragma once
#include <memory>

class Sprite;

class GameObject
{
private:
	std::shared_ptr<Sprite> sprite;
	float xpos, ypos;
	bool is_Interactable;

public:
	GameObject();
	~GameObject();

	virtual void Update();

	void Draw();

};