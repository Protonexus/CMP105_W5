#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario : public GameObject
{
public:
	Mario();
	~Mario();

	void update(float);
	void handleInput(float);
	
protected:
	Animation walk;
	Animation crouch;
	Animation stand;
};