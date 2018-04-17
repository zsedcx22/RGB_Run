#include "scene_menu.h"
#include "../components/cmp_button.h"
#include "../game.h"
#include <iostream>

using namespace std;
using namespace sf;

void MenuScene::Load() {

	_btns.clear();

	_btn_local_options.reset();
	_btn_local_options = createButton("Options");
	_btn_local_options->setPosition(Vector2f(Engine::getWindowSize().x - Engine::getWindowSize().x * 0.7, Engine::getWindowSize().y - 100));
	_btn_local_options->GetCompatibleComponent<TextComponent>()[0]->SetPosition(_btn_local_options->getPosition());

	_btn_local_game.reset();
	_btn_local_game = createButton("Start");
	_btn_local_game->setPosition(Vector2f(Engine::getWindowSize().x - Engine::getWindowSize().x * 0.9, 100));
	_btn_local_game->GetCompatibleComponent<TextComponent>()[0]->SetPosition(_btn_local_game->getPosition());

	_btn_local_exit.reset();
	_btn_local_exit = createButton("Exit");
	_btn_local_exit->setPosition(Vector2f(Engine::getWindowSize().x - Engine::getWindowSize().x * 0.9, Engine::getWindowSize().y - 100));
	_btn_local_exit->GetCompatibleComponent<TextComponent>()[0]->SetPosition(_btn_local_exit->getPosition());

  setLoaded(true);
}

void MenuScene::Update(const double& dt) {
  // cout << "Menu Update "<<dt<<"\n";

  if (_btn_local_game->GetCompatibleComponent<ButtonComponent>()[0]->isPressed() ) {
    Engine::ChangeScene(&level1);
  }
  else if (_btn_local_options->GetCompatibleComponent<ButtonComponent>()[0]->isPressed()) {
	  Engine::ChangeScene(&options);
  }
  else if (_btn_local_exit->GetCompatibleComponent<ButtonComponent>()[0]->isPressed()) {
	  Engine::GetWindow().close();
  }

  Scene::Update(dt);
}
