#include "scene_level1.h"
#include "../components/cmp_movement_player.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_enemy_ai.h"
#include "../components/cmp_dm.h"
#include "../components/cmp_shooting_enemy.h"
#include "../components/cmp_hurt_enemy.h"
#include "../game.h"
#include <LevelSystem.h>
#include <iostream>
#include <thread>
#include <SFML\Graphics.hpp>
using namespace std;
using namespace sf;

static shared_ptr<Entity> player;

void Level1Scene::Load() {
	auto playerStart = Vector2f(400, 50);
	// Create player
	{
		player = makeEntity();
		player->setPosition(playerStart);
		player->addTag("player");
		auto s = player->addComponent<ShapeComponent>();
		s->setShape<sf::RectangleShape>(Vector2f(20.f, 30.f));
		s->getShape().setFillColor(Color::Red);
		s->getShape().setOrigin(10.f, 15.f);
		auto q = player->addComponent<PlayerMovementComponent>();
	}
	{
		auto wall = makeEntity();
		wall->setPosition(Vector2f(380.f, 300.f));
		wall->addTag("floor");
		//shape component 
		auto s = wall->addComponent<ShapeComponent>();
		s->setShape<sf::RectangleShape>(Vector2f(150.f, 40.f));
		s->getShape().setFillColor(Color::White);

		//movement 
		auto m = wall->addComponent<ActorMovementComponent>();
	}
	{
		auto wall = makeEntity();
		wall->setPosition(Vector2f(530.f, 300.f));
		wall->addTag("floor");
		//shape component 
		auto s = wall->addComponent<ShapeComponent>();
		s->setShape<sf::RectangleShape>(Vector2f(150.f, 40.f));
		s->getShape().setFillColor(Color::White);

		//movement 
		auto m = wall->addComponent<ActorMovementComponent>();
	}
	{
		auto wall = makeEntity();
		wall->setPosition(Vector2f(530.f, 300.f));
		wall->addTag("floor");
		//shape component 
		auto s = wall->addComponent<ShapeComponent>();
		s->setShape<sf::RectangleShape>(Vector2f(150.f, 40.f));
		s->getShape().setFillColor(Color::White);

		//movement 
		auto m = wall->addComponent<ActorMovementComponent>();
	}
	{
		//shoting boy test
		auto shootyBoy = makeEntity();
		shootyBoy->setPosition(Vector2f(Engine::getWindowSize().x - 30, Engine::getWindowSize().y / 2));
		auto s = shootyBoy->addComponent<ShapeComponent>();
		s->setShape<sf::RectangleShape>(Vector2f(150.f, 80.f));
		s->getShape().setFillColor(Color::Yellow);
		auto mv = shootyBoy->addComponent<EnemyAIComponent>();
		auto hrt = shootyBoy->addComponent<HurtEnemyComponent>();
		auto sht = shootyBoy->addComponent<ShootingEnemy>();
	}
	{
		auto dm = makeEntity();
		dm->setPosition(Vector2f(200, 200));
		auto x = dm->addComponent<DMComponent>();

	}
	// GenerateBlocks();
	////Simulate long loading times
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << " Scene 1 Load Done" << endl;

	setLoaded(true);
}

void Level1Scene::UnLoad() {
	std::cout << "Scene 1 Unload" << endl;
	player.reset();
	Scene::UnLoad();
}

void Level1Scene::Update(const double& dt) {
	//GenerateBlocks();
	
	Scene::Update(dt);
}

void Level1Scene::Render() {
	Scene::Render();
}