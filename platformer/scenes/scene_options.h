#pragma once

#include "engine.h"
#include <map>
class OptionsScene : public Scene {
private:
	bool isWindowed = false;
	void loadButtons();
	void checkInput();

	//back & fullscreen
	std::shared_ptr<Entity> _btn_local_back;
	std::shared_ptr<Entity> _btn_local_windowed;
	//buttons
	std::shared_ptr<Entity> _btn_Left;
	std::shared_ptr<Entity> _btn_Right;
	std::shared_ptr<Entity> _btn_Jump;
	std::shared_ptr<Entity> _btn_Shoot;

	std::shared_ptr<Entity> _btn_Red;
	std::shared_ptr<Entity> _btn_Green;
	std::shared_ptr<Entity> _btn_Blue;

	std::shared_ptr<Entity> _btn_Pause;
	std::shared_ptr<Entity> _btn_Return;
	
	//All buttons, collected upon method
	std::vector<std::shared_ptr<Entity>> _btns;

	// Map button to control
	std::map<std::shared_ptr<Entity>, std::string> _buttonMap;

	// The control being changed
	std::shared_ptr<Entity> _changingBuffer = nullptr;

protected:
	void back();
public:
  OptionsScene() = default;
  ~OptionsScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};
