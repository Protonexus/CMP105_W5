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
	crouch.setLooping(false);

	stand.addFrame(sf::IntRect(0, 0, 15, 21));

	currentAnimation = &stand;
	setTextureRect(currentAnimation->getCurrentFrame());

}

Mario::~Mario()
{
}

void Mario::update(float dt)
{
	
	setTextureRect(currentAnimation->getCurrentFrame());
	currentAnimation->animate(dt);

}

void Mario::handleInput(float dt)
{
	


	//Move Right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		
		if (walk.getFlipped())
		{
			walk.setFlipped(false);
		}
		
		Mario::setVelocity(2, Mario::getVelocity().y);
		currentAnimation = &walk;
	} else if (input->isKeyDown(sf::Keyboard::Left))
	{
		if (!walk.getFlipped())
		{
			walk.setFlipped(true);
		}
		
		Mario::setVelocity(-2, Mario::getVelocity().y);
		currentAnimation = &walk;
	} else walk.reset();

	//If neither left or right dir.x is 0 and set to stand
	if ((!input->isKeyDown(sf::Keyboard::Left) & !input->isKeyDown(sf::Keyboard::Right))| (input->isKeyDown(sf::Keyboard::Left) & input->isKeyDown(sf::Keyboard::Right)))
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
		currentAnimation = &stand;
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
		currentAnimation = &crouch;

	}
	else crouch.reset();
}
