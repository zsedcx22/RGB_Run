#include "cmp_dm.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
#include "../components/cmp_movement_player.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_enemy_ai.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;


void DMComponent::update(double dt)
{
	if (_frameCount < _generateSpeed) {
		_frameCount++;

	}
	else {

		auto wall = Component::_parent->scene->makeEntity();
		//auto wall = makeEntity();
		wall->setPosition(Vector2f(400.f, 250.f));
		wall->addTag("floor");
		//shape component 
		auto s = wall->addComponent<ShapeComponent>();
		s->setShape<sf::RectangleShape>(Vector2f(90.f, 40.f));
		//changeable variable
		s->getShape().setFillColor(Color::White);
		//movement 
		auto m = wall->addComponent<ActorMovementComponent>();

		_frameCount = 0;
	}

}

void DMComponent::loadEntites()
{
	//get a pointer to the entities 
	Component::_parent->scene->ents;

}

DMComponent::DMComponent(Entity* p)
    : _speed(10.f), Component(p) {}

