#include "Mario.h"

Mario::Mario()
{
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(0.1);

	crouch.addFrame(sf::IntRect(0, 41, 16, 20));
	crouch.addFrame(sf::IntRect(16, 41, 16, 20));
	crouch.setFrameSpeed(0.1);

	stand.addFrame(sf::IntRect(0, 0, 15, 21));

}

Mario::~Mario()
{
}

void Mario::update(float dt)
{

}

void Mario::handleInput(float dt)
{
	//Move Right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		Mario::setVelocity(2, Mario::getVelocity().y);
		if (walk.getFlipped())
		{
			walk.setFlipped(false);
		}
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}

	//Move Left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		Mario::setVelocity(-2, Mario::getVelocity().y);
		if (!walk.getFlipped())
		{
			walk.setFlipped(true);
		}
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}

	//If neither left or right dir.x is 0 and set to stand
	if (!input->isKeyDown(sf::Keyboard::Left) & !input->isKeyDown(sf::Keyboard::Right))
	{
		if (walk.getFlipped())
		{
			stand.setFlipped(true);
		}
		else
		{
			stand.setFlipped(false);
		}

		Mario::setVelocity(0, Mario::getVelocity().y);
		stand.animate(dt);
		setTextureRect(stand.getCurrentFrame());
	}

	//if down pressed, stop moving and set to crouch
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		if (walk.getFlipped())
		{
			crouch.setFlipped(true);
		}
		else
		{
			crouch.setFlipped(false);
		}

		Mario::setVelocity(0, 0);
		crouch.animate(dt);
		setTextureRect(crouch.getCurrentFrame());

	}
}
