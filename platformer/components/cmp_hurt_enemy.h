#pragma once
#include "../engine/src/system_resources.h"
#include <ecm.h>

class HurtEnemyComponent : public Component {
private:
	sf::SoundBuffer _loadExplode;
	sf::Sound _sndExplode;

public:
  void update(double dt) override;
  void render() override {}
  explicit HurtEnemyComponent(Entity* p);
  HurtEnemyComponent() = delete;
};
