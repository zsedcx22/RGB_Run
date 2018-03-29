#include "cmp_movement_player.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
using namespace sf;
using namespace std;

void PlayerMovementComponent::update(double dt) {
	const auto pos = _parent->getPosition();
	float x = 0.f;
	float y = 0.f;
	
	//check position state: set if falling, jumping ect.
	
	_grounded = isGrounded(pos);
	updateMovement(pos);
	
	//update jump
	


	if (!_jumping && !_grounded) {
		_y_acceleration = _pulse/_gravity * -1;
	}
	if (!_grounded) {
		y -= _y_acceleration;
		_y_acceleration -= _gravity;
	}
	
	if (_grounded) {
		_jumping = false;	
		//todo -= the speed of the object standing on
		x -= 10.0f;

	}

	
	move(Vector2f( (dirX*_speed*50)*dt , (y)*dt ));
}

void PlayerMovementComponent::setSpeed(float spd)
{
	this->_speed = spd;
}

void PlayerMovementComponent::getCollision(sf::Vector2f pos)
{	
	auto playerTop = pos.y;
	auto playerBottom = pos.y +15 ;	//players height
	auto playerLeft = pos.x;
	auto playerRight = pos.x + 10;	//players width

	bool grounded = false;
	bool collidable;
	//access the list of entities
	auto x = Component::_parent->scene->ents.list;

	//iteration through entities
	for (auto i = x.begin(); i != x.end(); i++) {
		auto obj = *i;
		//auto comp = obj->get_components();	
		collidable = false;
		//check tags to see if object is colidable. floors/ enemies/ platforms
		auto tags = obj->getTags();
		for (std::set<std::string>::iterator it = tags.begin(); it != tags.end(); ++it) {
			if (*it == "floor") {
				collidable = true;		
			}
		}
		
		if (collidable && !grounded) {	
			//perform the collision check
			//check y position
			//height of the platforms is static.
			
			//check if touching the floor
			if (playerBottom < obj->getPosition().y + 5  && playerBottom > obj->getPosition().y) 
			{
				//check x position
				//TODO hardcoded size of the platform
				if (pos.x > obj->getPosition().x &&  pos.x < obj->getPosition().x + 150) {
					_jumping = false;
				}
				else {
				}
			}
			
			//check if touches the ceiling 
			if (playerTop > obj->getPosition().y + 20 && playerTop < obj->getPosition().y +55)
			{
				//check x position
				//TODO hardcoded size of the platform
				if (pos.x > obj->getPosition().x &&  pos.x < obj->getPosition().x + 150) {
					_jumping = false;
				}
			}
		}
		if (collidable) {
			//check if a platform is in your way
			//right
			//if (pos.y > obj->getPosition().y + 20  && pos.y < obj->getPosition().y + 20)
			//{
			//	//check x position
			//	//TODO hardcoded size of the platform
			//	if (playerRight < obj->getPosition().x && playerTop > obj->getPosition().x - 10) {
			//		_mvRight = false;
			//	}
			//	else {
			//		_mvRight = true;
			//	}
			//}
			
			//right
			if (obj->getPosition().y > pos.y - 30 && obj->getPosition().y < pos.y + 30) {
				if (pos.x +5 > obj->getPosition().x - 5 && pos.x < obj->getPosition().x +5) {
					_mvRight = false;
				}
				else {
					_mvRight = true;
				}
			}
			else {
				_mvRight = true;
			}

			//left
			if (obj->getPosition().y > pos.y - 30 && obj->getPosition().y < pos.y + 30) {
				if (pos.x + 5 > obj->getPosition().x +155 && pos.x < obj->getPosition().x + 160) {
					_mvLeft = false;
				}
				else {
					_mvLeft = true;
				}
			}
			else {
				_mvLeft = true;
			}
			//left


		}

	}
}

float PlayerMovementComponent::getYPosition(float y)
{
	return 0.f;
}

void PlayerMovementComponent::updateJump()
{
	
}

void PlayerMovementComponent::loadEntites()
{
	//get a pointer to the entities 
	Component::_parent->scene->ents;

}

bool PlayerMovementComponent::isGrounded(sf::Vector2f pos)
{
	auto playerTop = pos.y;
	auto playerBottom = pos.y + 15;	//players height
	auto playerLeft = pos.x;
	auto playerRight = pos.x + 10;	//players width

	bool grounded;
	bool collidable;
	//access the list of entities
	auto x = Component::_parent->scene->ents.list;
	//iteration through entities
	for (auto i = x.begin(); i != x.end(); i++) {
		auto obj = *i;
		//auto comp = obj->get_components();	
		collidable = false;
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
			if (playerBottom < obj->getPosition().y + 40 && playerBottom > obj->getPosition().y)
			{
				//check x position
				if (pos.x > obj->getPosition().x - 5 &&  pos.x < obj->getPosition().x + 155)
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

void PlayerMovementComponent::updatePhysics()
{


}

void PlayerMovementComponent::updateMovement(sf::Vector2f pos)
{
	//check collision
	

	if (Keyboard::isKeyPressed(Keyboard::Left) ||
		Keyboard::isKeyPressed(Keyboard::Right)) {
		// Moving Either Left or Right
		//check collision everytime a buyttoin is pressed
		
		if (Keyboard::isKeyPressed(Keyboard::Right) && _mvRight) {
			getCollision(pos);
			if (_mvRight) {
				dirX = 1;
			}
			else {
				dirX = 0;
			}
		}
		else if(Keyboard::isKeyPressed(Keyboard::Left) && _mvLeft){
			getCollision(pos);
			if (_mvLeft) {
				dirX = -1;
			}
			else {
				dirX = 0;
			}
		}
	}
	else {
		dirX = 0;
	}

	//jump behaviour
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		getCollision(pos);
		if (_grounded) {
			_y_acceleration = 0;
			_grounded = false;
			_jumping = true;
			_y_acceleration += _pulse;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::F1)) {
		//input debug information here
		auto x = Component::_parent->scene->ents.list;
		_grounded = false;
		_parent->setPosition(Vector2f(400, 50));
		cout << x[0];
	}
}

PlayerMovementComponent::PlayerMovementComponent(Entity* p)
    : _speed(10.f), Component(p) {}

bool PlayerMovementComponent::validMove(const sf::Vector2f& pos) {
  
   return true;
}

void PlayerMovementComponent::move(const sf::Vector2f& p) {
  auto pp = _parent->getPosition() + p;
  _parent->setPosition(pp);
}

void PlayerMovementComponent::move(float x, float y) {
  move(Vector2f(x, y));
}
