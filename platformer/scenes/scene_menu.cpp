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
	_btn_local_options->setPosition(Vector2f(Engine::getWindowSize().x - 120, Engine::getWindowSize().y - 100));
	_btn_local_options->GetCompatibleComponent<TextComponent>()[0]->SetPosition(_btn_local_options->getPosition());

	_btn_local_game.reset();
	_btn_local_game = createButton("Start");
	_btn_local_game->setPosition(Vector2f(30, 30));
	_btn_local_game->GetCompatibleComponent<TextComponent>()[0]->SetPosition(_btn_local_game->getPosition());

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

  Scene::Update(dt);
}
