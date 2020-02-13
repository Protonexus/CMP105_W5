#include "GameObject.h"

GameObject::GameObject()
{
	input = nullptr;
}

GameObject::~GameObject()
{

}

// Override this function to provide input handling for the derived class
void GameObject::handleInput(float dt)
{
}

// override this function to provide functionality
void GameObject::update(float dt)
{
}

// Sets the velocity of the sprite
void GameObject::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}
void GameObject::setVelocity(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}

// get sprite velocity
sf::Vector2f GameObject::getVelocity()
{
	return velocity;
}

void GameObject::setSpeed(float spd)
{
	speed = spd;
}

float GameObject::getSpeed()
{
	return speed;
}

// Returns collision box + position, giving the collision box in the correct position
sf::FloatRect GameObject::getCollisionBox() {
	
	return sf::FloatRect(collisionBox.left + getPosition().x, collisionBox.top + getPosition().y, collisionBox.width, collisionBox.height); 
}

// Reponse function, what the sprite does based on collision
// Colliding object is passed in for information
// e.g. compare sprite positions to determine new velocity direction.
// e.g. checking sprite type (world, enemy, bullet etc) so response is based on that.
void GameObject::collisionResponse(GameObject * collider)
{
}

sf::Vector2f GameObject::normalise(sf::Vector2f dir)
{

	if ((dir.x == 0) & (dir.y == 0))
	{
		return dir;
	}

	dir = dir / (sqrt((dir.x * dir.x) + (dir.y * dir.y)));

	return dir;

}
