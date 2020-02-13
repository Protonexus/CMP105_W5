#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	xombieTexture.loadFromFile("gfx/animZombie.png");
	xombie.setSize(sf::Vector2f(55, 108));
	xombie.setPosition(100, 100);
	xombie.setTexture(&xombieTexture);
	xombie.setInput(input);
	xombie.setSpeed(50.f);

	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setSize(sf::Vector2f(15, 21));
	mario.setPosition(100, 200);
	mario.setTexture(&marioTexture);
	mario.setInput(input);
	mario.setSpeed(50.f);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	xombie.handleInput();
	mario.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	xombie.setVelocity(xombie.normalise(xombie.getVelocity()));
	xombie.move(xombie.getVelocity() * dt * xombie.getSpeed());
	xombie.update(dt);

	mario.setVelocity(mario.normalise(mario.getVelocity()));
	mario.move(mario.getVelocity() * dt * mario.getSpeed());
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(xombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}