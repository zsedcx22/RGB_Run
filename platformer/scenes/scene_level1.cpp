#include "scene_level1.h"
#include "../components/cmp_movement_player.h"
#include "../components/cmp_score.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_enemy_ai.h"
#include "../components/cmp_dm.h"
#include "../helper_code/Loader.h"
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
		auto player = createPlayer();
		player->setPosition(Vector2f(380.f, 20.f));
	}
	{
		auto dm = makeEntity();
		auto x = dm->addComponent<DMComponent>();
	}

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