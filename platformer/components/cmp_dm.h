#pragma once
#pragma once
#include <ecm.h>
#include <random>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include "system_resources.h"

class DMComponent : public Component {
private:
	int _gameStepCount= 0;
	int _levelGenFreq = 200;
	int _level;
	float _lvlSpeed;
	float _platformFrequency;
	unsigned int _lvlStEnemy;
	unsigned int _lvlPlatEnemy;
	
	struct LevelGenerator *_currentLevel;

	void nextLevel();

public:
	
  void update(double dt) override;
  void render() override {}
  
  DMComponent(Entity* p);
  DMComponent() = delete;
};

struct LevelGenerator{
private:
	unsigned int _levelDuration;
	unsigned int _levelStepCount;
	unsigned int _generateSpeed;
	int _platformSpeed;
	unsigned int _enemyShooty;
	unsigned int _enemyPlatform;

	int _spawnBuffer;
	//random number generator
	std::mt19937 range;
	sf::Color _colors[3];
	sf::Vector2f _platformPosition;
	sf::Vector2u _screenSize;

	void spawnEnemy(int type);
	void getNextPlatform();

protected:

public:
	void RunStep();
	LevelGenerator(float speed, float frequency, unsigned int enm_shoot, unsigned int enm_platform, unsigned int duration);
	LevelGenerator() = delete;
};
