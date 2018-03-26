#include "cmp_dm.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
using namespace sf;
using namespace std;

void DMComponent::update(double dt) {
	const auto pos = _parent->getPosition();
	float x = 0.f;
	float y = 0.f;
	
	//check position state: set if falling, jumping ect.
	_grounded = isGrounded(pos);

	//update jump
	updateMovement();

	if (!_grounded) {
		y -= _y_acceleration;
		_y_acceleration -= _gravity;
	}
	if (_grounded) {
		_y_acceleration = 0;
		x -= 20.0f;

	}

	
	
	move(Vector2f( (x+=_speed)*dt , (y)*dt ));
}

void DMComponent::setSpeed(float spd)
{
	this->_speed = spd;
}

bool DMComponent::isGrounded(sf::Vector2f pos)
{	
	bool grounded;
	bool collidable = false;
	//access the list of entities
	auto x = Component::_parent->scene->ents.list;
	//iteration through entities
	for (auto i = x.begin(); i != x.end(); i++) {
		auto obj = *i;
		
		//check tags to see if object is colidable. floors/ enemies/ platforms
		auto tags = obj->getTags();
		for (std::set<std::string>::iterator it = tags.begin(); it != tags.end(); ++it) {
			if (*it == "floor") {
				collidable = true;

			}

		}
		
		if (collidable) {
			//perform the collision check
			//check y position
			if (pos.y > obj->getPosition().y-5 && pos.y < obj->getPosition().y + 5 ) 
			{
				//check x position
				if (pos.x > obj->getPosition().x &&  pos.x < obj->getPosition().x + 900)
					return true;
			}
			else {
				grounded = false;
			}
		}
		else {
			grounded = false;
		}
	}

	return grounded;
}

float DMComponent::getYPosition(float y)
{
	return 0.f;
}

void DMComponent::updateJump()
{
	
}

void DMComponent::loadEntites()
{
	//get a pointer to the entities 
	Component::_parent->scene->ents;

}

void DMComponent::updatePhysics()
{


}

void DMComponent::updateMovement()
{
	if (Keyboard::isKeyPressed(Keyboard::Left) ||
		Keyboard::isKeyPressed(Keyboard::Right)) {
		// Moving Either Left or Right
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (_speed < 1000)
				_speed += _friction;
		}
		else {
			if (_speed > -1000)
				_speed -= _friction;
		}
	}
	else {
		if (_speed > 5) {
			_speed -= _friction;
		}
		else if (_speed < -5) {
			_speed += _friction;
		}
		else _speed = 0;
	}


	//jump behaviour
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		if (_grounded) {
			_y_acceleration = 0;
			_grounded = false;
			//_jumping = true;
			_y_acceleration += _pulse;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::F1)) {
		//input debug information here
		auto x = Component::_parent->scene->ents.list;

		cout << x[0];
	}
}

DMComponent::DMComponent(Entity* p)
    : _speed(10.f), Component(p) {}

bool DMComponent::validMove(const sf::Vector2f& pos) {
  
   return true;
}

void DMComponent::move(const sf::Vector2f& p) {
  auto pp = _parent->getPosition() + p;
  _parent->setPosition(pp);
}

void DMComponent::move(float x, float y) {
  move(Vector2f(x, y));
}
