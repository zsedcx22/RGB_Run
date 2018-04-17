#pragma once

#include "engine.h"
#include <SFML\Graphics.hpp>


std::shared_ptr<Entity> createPlayer();
std::shared_ptr<Entity> createPlatform(sf::Vector2f position, float speed, sf::Color color);
std::shared_ptr<Entity> createButton(std::string text);
std::shared_ptr<Entity> createEnemyPlatform(sf::Vector2f position, float speed);
std::shared_ptr<Entity> createShootingEnemy();
std::shared_ptr<Entity> createText(sf::Vector2f position, float speed, sf::Color color, std::string text);
std::shared_ptr<Entity> createGameOver();
std::shared_ptr<Entity> createDungeonMaster();
std::shared_ptr<Entity> createEnemyBullet(sf::Vector2f position, sf::Color color);
std::shared_ptr<Entity> createPlayerBullet(sf::Vector2f position, sf::Color color);