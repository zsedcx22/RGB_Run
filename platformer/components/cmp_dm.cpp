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
		_frameCount += 2;
	}
	/*if (Keyboard::isKeyPressed(Keyboard::F1)) {
		_genCounter = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::F2)) {
		_genCounter = 2;
	}*/
	else 
	{
		if (_gameState == 0)
		{
			auto wall = Component::_parent->scene->makeEntity();
			//auto wall = makeEntity();
			wall->setPosition(Vector2f(_platLGen, _platHGen));
			wall->addTag("floor");
			//shape component 
			auto s = wall->addComponent<ShapeComponent>();
			s->setShape<sf::RectangleShape>(Vector2f(150.f, 40.f));
			//changeable variable
			s->getShape().setFillColor(Color::White);
			//movement 
			auto m = wall->addComponent<ActorMovementComponent>();
			_frameCount = 0;
			_genCounter += 1;
			if (_genCounter >= 15)
			{
				_gameState = 1;
				_genCounter = 0;
			}
		}
		else if (_gameState == 1)
		{
			auto wall = Component::_parent->scene->makeEntity();
			//auto wall = makeEntity();
			wall->setPosition(Vector2f(_platLGen, _platHGen));
			wall->addTag("floor");
			//shape component 
			auto s = wall->addComponent<ShapeComponent>();
			s->setShape<sf::RectangleShape>(Vector2f(150.f, 40.f));
			//changeable variable
			if (_lastColour == 0)
			{
				s->getShape().setFillColor(Color::Red);
				_lastColour = 1;
			}
			else
			{
				s->getShape().setFillColor(Color::Green);
				_lastColour = 0;
			}
			//movement 
			auto m = wall->addComponent<ActorMovementComponent>();
			_frameCount = 0;
			_genCounter += 1;
			if (_genCounter >= 15)
			{
				_gameState = 2;
				_genCounter = 0;
			}
		}
		else if (_gameState == 2)
		{
			auto wall = Component::_parent->scene->makeEntity();
			//auto wall = makeEntity();
			wall->setPosition(Vector2f(_platLGen, _platHGen));
			wall->addTag("floor");
			//shape component 
			auto s = wall->addComponent<ShapeComponent>();
			s->setShape<sf::RectangleShape>(Vector2f(150.f, 40.f));
			//changeable variable
			if (_lastColour == 0)
			{
				s->getShape().setFillColor(Color::Red);
				_lastColour = rand() % 3;
				//cout << _lastColour;
			}
			else if(_lastColour == 1)
			{
				s->getShape().setFillColor(Color::Green);
				_lastColour = rand() % 3;
				//cout << _lastColour;
			}
			else if (_lastColour == 2)
			{
				s->getShape().setFillColor(Color::Blue);
				_lastColour = rand() % 3;
			}
			while (_platHGen > 0.f && _platHGen < 720.f)
			{
				if (_platHGen < 360.f)
				{
					_platHGen += (rand() % 500) * 1.f;
				}
				else
				{
					_platHGen -= (rand() % 500) * 1.f;
				}

				if (_platHGen > 0.f && _platHGen < 720.f)
				{
					//cout << _platHGen;
					break;
				}
				else
				{
					_platHGen = 360.f;
				}
				
			}
			//movement 
			auto m = wall->addComponent<ActorMovementComponent>();
			_frameCount = 0;
		}
	}

}

void DMComponent::loadEntites()
{
	//get a pointer to the entities 
	Component::_parent->scene->ents;

}

DMComponent::DMComponent(Entity* p)
    : _speed(10.f), Component(p) {}

