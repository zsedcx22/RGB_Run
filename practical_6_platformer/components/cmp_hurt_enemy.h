#pragma once
#include <ecm.h>

class HurtEnemyComponent : public Component {

public:
  void update(double dt) override;
  void render() override {}
  explicit HurtEnemyComponent(Entity* p);
  HurtEnemyComponent() = delete;
};
