#include "rgbRun.h"

using namespace std;
using namespace sf;

std::shared_ptr<Scene> gameScene{ new GameScene() };
std::shared_ptr<Scene> menuScene{ new MenuScene() };
std::shared_ptr<Scene> activeScene = gameScene;

//Here we control what happens within the scenes, so load/render ect.

//simple example of switching between two scenes.
void MenuScene::update(double dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		activeScene = gameScene;
	}
	Scene::update(dt);
	
}

void MenuScene::render()
{
}

void MenuScene::load()
{
}

void GameScene::respawn()
{
}

//Game Scene methods
void GameScene::update(double dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		activeScene = gameScene;
	}
	Scene::update(dt);

}

void GameScene::render()
{
}

void GameScene::load() {
	//generate all entities using the components 
	
	//player
	//auto pl = make_shared<Entity>();

	//add a shape component and specify its variables
	//auto s = pl->addComponent<ShapeComponent>();
	//s->setShape<CircleShape>(12.f);
	//s->getShape().setFillColor(Color::White);
	//s->getShape().setOrigin(Vector2f(300.f, 300.f));

	//TODO: add all the other logic in form of components

	//push the object to entity manager that is inherited form Scene parent class 
	//	_ents.list.push_back(pl);
}