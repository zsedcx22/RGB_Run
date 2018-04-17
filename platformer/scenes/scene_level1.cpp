#include "scene_level1.h"
#include "../helper_code/Loader.h"
#include "../game.h"
#include <thread>

using namespace std;
using namespace sf;
#include "system_resources.h"

static shared_ptr<Entity> player;

void Level1Scene::Load() {
	auto playerStart = Vector2f(400, 50);
	

	// Create player
	{
		auto player = createPlayer();
		player->setPosition(Vector2f(380.f, 20.f));
	}
	{
		createDungeonMaster();
	}
	setLoaded(true);
}

void Level1Scene::UnLoad() {
	std::cout << "Scene 1 Unload" << endl;
	ents.list.clear();
	Scene::UnLoad();
}

void Level1Scene::Update(const double& dt) {
	if (state_reset) {
		state_reset = false;
		Engine::ChangeScene(&level1);
	}
	if (state_menu) {
		state_menu = false;
		Engine::ChangeScene(&menu);
	}
	Scene::Update(dt);
}

void Level1Scene::Render() {
	Scene::Render();
}