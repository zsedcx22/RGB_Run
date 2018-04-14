

#pragma once
#include "engine.h"
#include <SFML\Graphics.hpp>


std::shared_ptr<Entity> createPlayer();
std::shared_ptr<Entity> createPlatform(sf::Vector2f position, float speed);
std::shared_ptr<Entity> createButton(std::string text);
std::shared_ptr<Entity> createEnemyPlatform(sf::Vector2f position, float speed);

