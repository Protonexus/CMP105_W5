#include "Zombie.h"

Zombie::Zombie()
{
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(0.1);

}

Zombie::~Zombie()
{
}

void Zombie::update(float dt)
{
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput()
{
	//Move Right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		Zombie::setVelocity(2, Zombie::getVelocity().y);
		if (walk.getFlipped())
		{
			walk.setFlipped(false);
		}
	}

	//Move Left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		Zombie::setVelocity(-2, Zombie::getVelocity().y);
		if (!walk.getFlipped())
		{
			walk.setFlipped(true);
		}
	}

	//If neither left or right dir.x is 0
	if (!input->isKeyDown(sf::Keyboard::Left) & !input->isKeyDown(sf::Keyboard::Right))
	{
		Zombie::setVelocity(0, Zombie::getVelocity().y);
	}
}

