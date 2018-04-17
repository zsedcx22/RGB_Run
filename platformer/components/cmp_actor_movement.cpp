#include "cmp_actor_movement.h"
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;

void ActorMovementComponent::update(double dt) {
	move(Vector2f(_speed*dt, 0.f));
}

ActorMovementComponent::ActorMovementComponent(Entity* p)
	: _speed(-200.0f), Component(p) {}

bool ActorMovementComponent::validMove(const sf::Vector2f& pos) {

	return true;
}

void ActorMovementComponent::move(const sf::Vector2f& p) {
	auto pp = _parent->getPosition() + p;
	if (validMove(pp)) {
		_parent->setPosition(pp);
	}
}

void ActorMovementComponent::move(float x, float y) {
	move(Vector2f(x, y));
}

float ActorMovementComponent::getSpeed()
{
	return _speed;
}

void ActorMovementComponent::setSpeed(float s)
{
	this->_speed = s;
}
