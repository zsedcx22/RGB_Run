#include "scene_options.h"
#include "../components/cmp_text.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_button.h"
#include "../helper_code/Loader.h"
#include "../helper_code/Controls.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;



void OptionsScene::Load() {
	_btns.clear();

	_btn_local_back.reset();
	_btn_local_back = createButton("Back");
	_btn_local_back->setPosition(Vector2f(Engine::getWindowSize().x -240, Engine::getWindowSize().y - 100));
	_btn_local_back->GetCompatibleComponent<TextComponent>()[0]->SetPosition(_btn_local_back->getPosition());

	_btn_local_windowed.reset();
	_btn_local_windowed = createButton("Window");
	_btn_local_windowed->setPosition(Vector2f(Engine::getWindowSize().x - 630, Engine::getWindowSize().y - 100));
	_btn_local_windowed->GetCompatibleComponent<TextComponent>()[0]->SetPosition(_btn_local_windowed->getPosition());


	_btn_Left.reset();
	_btn_Left = createButton("Left");
	_btns.push_back(_btn_Left);
	_buttonMap[_btn_Left] = "Left";

	_btn_Right.reset();
	_btn_Right = createButton("Right");
	_btns.push_back(_btn_Right);
	_buttonMap[_btn_Right] = "Right";

	_btn_Jump.reset();
	_btn_Jump = createButton("Jump");
	_btns.push_back(_btn_Jump);
	_buttonMap[_btn_Jump] = "Jump";

	_btn_Shoot.reset();
	_btn_Shoot = createButton("Shoot");
	_btns.push_back(_btn_Shoot);
	_buttonMap[_btn_Shoot] = "Shoot";

	_btn_Red.reset();
	_btn_Red = createButton("Red");
	_btns.push_back(_btn_Red);
	_buttonMap[_btn_Red] = "Red";

	_btn_Green.reset();
	_btn_Green = createButton("Green");
	_btns.push_back(_btn_Green);
	_buttonMap[_btn_Green] = "Green";

	_btn_Blue.reset();
	_btn_Blue = createButton("Blue");
	_btns.push_back(_btn_Blue);
	_buttonMap[_btn_Blue] = "Blue";

	_btn_Pause.reset();
	_btn_Pause = createButton("Pause");
	_btns.push_back(_btn_Pause);
	_buttonMap[_btn_Pause] = "Pause";

	_btn_Return.reset();
	_btn_Return = createButton("Return");
	_btns.push_back(_btn_Return);
	_buttonMap[_btn_Return] = "Return";

	for(int i = 0; i < _btns.size(); i++)
	{
		_btns[i]->setPosition(Vector2f( 40, (65.0f * i) + 20));
		_btns[i]->GetCompatibleComponent<TextComponent>()[0]->SetPosition( Vector2f(_btns[i]->getPosition().x+25, _btns[i]->getPosition().y + 15));
	}
    setLoaded(true);
}

void OptionsScene::Update(const double& dt) {
	  checkInput();
 
  Scene::Update(dt);
}


void OptionsScene::back()
{
	Engine::ChangeScene(&menu);
}

void OptionsScene::loadButtons()
{
}

void OptionsScene::checkInput()
{
	if (_btn_local_back->GetCompatibleComponent<ButtonComponent>()[0]->isPressed()) {
		Engine::ChangeScene(&menu);
	}
	else if (_btn_local_windowed->GetCompatibleComponent<ButtonComponent>()[0]->isPressed()) {
		Engine::setFullscreen(isWindowed);
		Engine::ChangeScene(&options);

		if (isWindowed == false) isWindowed = true;
		else if (isWindowed == true) isWindowed = false;
	}

	if (_changingBuffer == nullptr) {
		//step1. choose a button to change
		for (auto btn : _buttonMap) {
			if (btn.first->GetCompatibleComponent<ButtonComponent>()[0]->isPressed()) {
				_changingBuffer = btn.first;
				_changingBuffer->GetCompatibleComponent<ShapeComponent>()[0]->getShape().setFillColor(Color::Red);
			}
		}
	}

	if (_changingBuffer != nullptr) {
		//2 alocate new control.
		//iterate through all keys
		for (auto key = Keyboard::Unknown; key != Keyboard::Pause; key = static_cast<Keyboard::Key>(key + 1)) {
			if (Keyboard::isKeyPressed(key)) {
				Controls::SetKey(_buttonMap[_changingBuffer], key);
				_changingBuffer->GetCompatibleComponent<ShapeComponent>()[0]->getShape().setFillColor(Color::White);
				_changingBuffer = nullptr;
			}
		}
	}

}
