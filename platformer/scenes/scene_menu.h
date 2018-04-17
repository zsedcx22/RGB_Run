#pragma once

#include "../helper_code/Loader.h"
#include "../components/cmp_text.h"
#include "engine.h"

class MenuScene : public Scene {
private:
	std::shared_ptr<Entity> _btn_local_options;
	std::shared_ptr<Entity> _btn_local_game;
	std::shared_ptr<Entity> _btn_local_exit;

	std::vector<std::shared_ptr<Entity>> _btns;
public:
  MenuScene() = default;
  ~MenuScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};
