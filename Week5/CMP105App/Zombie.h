#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Zombie : public GameObject
{
public:
	Zombie();
	~Zombie();

	void update(float dt);
	void handleInput();

protected:
	Animation walk;
};