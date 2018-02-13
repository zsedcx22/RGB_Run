#include "ecm.h"
#include "system_renderer.h"

using namespace std;
using namespace sf;

//Entity methods
Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::update(const double dt)
{
}

const sf::Vector2f & Entity::getPosition() const
{
	return _position;
}

void Entity::setPosition(const sf::Vector2f & _position)
{
	this->_position = _position;
}

bool Entity::is_fordeletion() const
{
	return false;
}

bool Entity::isAlive() const
{
	return false;
}

void Entity::setAlive(bool _alive)
{
	this->_alive = _alive;
}

void Entity::setForDelete()
{
	_fordeletion = true;
}

bool Entity::isVisible() const
{
	return _visible;
}

void Entity::setVisible(bool _visible)
{
	this->_visible = _visible;
}





//All the components and their methods

//SHAPE COMPONENT
void ShapeComponent::update(double dt) {
	//change shape by accessing the pointer to entity class
	_shape->setPosition(_parent->getPosition());
}

//render the shape 
void ShapeComponent::render() { Renderer::queue(_shape.get()); }

sf::Shape & ShapeComponent::getShape() const
{
	return *_shape;
}

//i have no idea... i guess you take the entity you make it a component ? 
//you definately create a new shape. 
ShapeComponent::ShapeComponent(Entity* p)
	: Component(p), _shape(make_shared<sf::CircleShape>()) {}


