#include "cmp_dm.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
#include "../components/cmp_movement_player.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_enemy_ai.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <stdlib.h>  

using namespace sf;
using namespace std;


void DMComponent::update(double dt)
{
	if (_frameCount < _generateSpeed) {
		_frameCount += 1;
	}
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
			if (_genCounter >= 1)
			{
				_gameState = 1;
				_genCounter = 0;
				_generateSpeed = 10;
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
			//determine number of blocks to renderat the same time
			int range = getRandom(1, 2);

			//generate the number of blocks based on the random number
			while (range > 0) {
				auto wall = Component::_parent->scene->makeEntity();
				wall->setPosition(Vector2f(_platLGen, _platHGen));
				wall->addTag("floor");
				auto s = wall->addComponent<ShapeComponent>();
				s->setShape<sf::RectangleShape>(Vector2f(150.f, 40.f));

				//select colour at random
				int col = getRandom(1, 3);
				if(col==1){
					s->getShape().setFillColor(Color::Red);
				}
				else if (col == 2) {
					s->getShape().setFillColor(Color::Green);
				}
				else if (col == 3) {
					s->getShape().setFillColor(Color::Blue);
				}

				//select y position
				while (_platHGen > 40.f && _platHGen < 720.f)
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
						cout << _platHGen;
						break;
					}
					else
					{
						_platHGen = 360.f;
					}

				}
				// add movement 
				auto m = wall->addComponent<ActorMovementComponent>();
				m->setSpeed(this->_speed);
				range--;
			}			
			//set new generateSpeed value, to randomise the distance between the blocks
			_generateSpeed = getRandom(40+(_speed*-0.01), 60 + (_speed*-0.01));
			this->_speed -= 10.0f;
			_frameCount = 0;
		}
	}

}

int DMComponent::getRandom(int min, int max) {
	//range = min -> max 
	int range = rand() % max + min;

	return range;
}

void DMComponent::loadEntites()
{
	//get a pointer to the entities 
	Component::_parent->scene->ents;

}

DMComponent::DMComponent(Entity* p)
    : _speed(-200.f), Component(p) {}

