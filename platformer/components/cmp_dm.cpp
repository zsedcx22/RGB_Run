#include "cmp_dm.h"
#include <engine.h>
#include <iostream>
#include "../components/cmp_movement_player.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_enemy_ai.h"
#include "../components/cmp_score.h"
#include "../components/cmp_shooting_enemy.h"
#include "../components/cmp_hurt_enemy.h"
#include "../helper_code/Loader.h"


using namespace sf;
using namespace std;

void DMComponent::nextLevel()
{
	//reset parameters and set new level
	//increase the difficulty parameters. 
	_gameStepCount = 0;
	_level++;
	//increment the difficulty for the next sequence
	_lvlSpeed -= 150;
	_platformFrequency -= 10;
	_lvlStEnemy++;
	_lvlPlatEnemy += 10;
	_levelGenFreq += 1500;	//make spaces between levels longer

	_currentLevel = new LevelGenerator(_lvlSpeed, _platformFrequency, _lvlStEnemy, _lvlPlatEnemy, _levelGenFreq);
	createText(Vector2f(Engine::getWindowSize().x+500, 50), -150, Color::White, "Level " + std::to_string(_level));
	
}

void DMComponent::update(double dt)
{
	//initial 
	//generate new set
	if (_gameStepCount >= _levelGenFreq) {
		nextLevel();
	}
	else {
		_gameStepCount++;
		_currentLevel->RunStep();
	}

	if (_gameStepCount == 60 * 5) {
		auto p = Engine::GetActiveScene()->ents.find("player");
		auto scr = p[0]->GetCompatibleComponent<Score>()[0]->returnScore();
		
		createText(Vector2f(Engine::getWindowSize().x + 500, 50), -150, Color::White, std::to_string(scr)+"m" );
	}
}

DMComponent::DMComponent(Entity* p)
    : Component(p) {
	
	_levelGenFreq = 1000;
	_level = 1;
	_lvlSpeed = -200;
	_platformFrequency = 50;
	_lvlStEnemy = 0;
	_lvlPlatEnemy = 0;

	//create the begining platforms
	for (int i = 0; i < 12; i++) {
		createPlatform(Vector2f(150*i , Engine::getWindowSize().y / 2), _lvlSpeed, Color::Green);
	}

	createText(Vector2f(Engine::getWindowSize().x,  50), -150, Color::Red, "R");
	createText(Vector2f(Engine::getWindowSize().x+20, 50), -150, Color::Green, "G");
	createText(Vector2f(Engine::getWindowSize().x+40, 50), -150, Color::Blue, "B");
	createText(Vector2f(Engine::getWindowSize().x+80, 50), -150, Color::White, "Run !");

	createText(Vector2f(Engine::getWindowSize().x+400, 50), -150, Color::White, "Level " + std::to_string(_level));

	_currentLevel = new LevelGenerator(_lvlSpeed, _platformFrequency, _lvlStEnemy, _lvlPlatEnemy, _levelGenFreq);

}



//////////////////////////////
void LevelGenerator::RunStep()
{
	//step by step level control
	_levelStepCount++;
	_spawnBuffer++;

	if (_levelStepCount >= _generateSpeed) {
		_levelStepCount = 0;
		//randomise the parameters
		std::uniform_int_distribution<std::mt19937::result_type> color(0, 2);
		createPlatform(_platformPosition, _platformSpeed, _colors[color(range)]);
		getNextPlatform();
	

		//decide on enemy placement./ 
		//get even distribution of events
		if (_spawnBuffer >= (150)) {
			std::uniform_int_distribution<std::mt19937::result_type> enemyType(0, 2);

			//generating situations 
			if (_enemyShooty > 0 && _enemyPlatform > 0) {
				//booth enemies are still to be spawned, choose one
				auto tmp = enemyType(range);
				if (tmp = 0) {
					spawnEnemy(0);
				}
				else if (tmp = 1) {
					spawnEnemy(1);
				}
				else {
					//2 == create both
					spawnEnemy(0);
					spawnEnemy(1);
				}
				_spawnBuffer = 0;
				return;
			}
			else if (_enemyShooty > 0) {
				spawnEnemy(0);
				_spawnBuffer = 0;
			}
			else if (_enemyPlatform > 0) {
				spawnEnemy(0);
				_spawnBuffer = 0;
			}
		}
	}
}

void LevelGenerator::spawnEnemy(int type)
{
	// 0 == shooty enemy 1 = platform enemy;
	if (type == 0) {
		createShootingEnemy();
		_enemyShooty--; 
	}
	else {
		getNextPlatform();
		createEnemyPlatform(_platformPosition, _platformSpeed);
		_enemyPlatform--; 
	}
}

void LevelGenerator::getNextPlatform()
{
	//logic for setting the next y positon of the platforms
	while (_platformPosition.y > 0.f && _platformPosition.y < _screenSize.y-50)
	{
		if (_platformPosition.y < (_screenSize.y/2) && _platformPosition.y > 50.f)
		{
			_platformPosition.y += (rand() % 500) * 1.f;
		}
		else
		{
			_platformPosition.y -= (rand() % 500) * 1.f;
		}
		if (_platformPosition.y > 150.f && _platformPosition.y < _screenSize.y - 50)
		{
			break;
		}
		else
		{
			_platformPosition.y = _screenSize.y/2;
		}

	}
}

LevelGenerator::LevelGenerator(float speed, float frequency, unsigned int enm_shoot, unsigned int enm_platform, unsigned int duration)
{
	
	//get random seed
	range.seed(std::random_device()());
	
	//initialize the parameters
	_colors[0] = Color::Blue;
	_colors[1] = Color::Green;
	_colors[2] = Color::Red;

	_levelDuration = duration;
	_levelStepCount = 0;
	_generateSpeed = frequency;
	_enemyShooty = enm_shoot;
	_enemyPlatform = enm_platform;
	_platformSpeed = speed;
	_platformPosition.x = Engine::getWindowSize().x;
	_platformPosition.y = 250.f;
	_screenSize = Engine::getWindowSize();
	_spawnBuffer = 0; 
}
