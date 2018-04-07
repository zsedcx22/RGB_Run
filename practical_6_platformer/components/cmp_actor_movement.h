
#pragma once
#include <ecm.h>

class ActorMovementComponent : public Component {
protected:
  bool validMove(const sf::Vector2f&);
  float _speed = -200.0f;

public:
  void update(double dt) override;
  void move(const sf::Vector2f&);
  void move(float x, float y);
  void render() override {}
  float getSpeed();
  void setSpeed(float s);
   ActorMovementComponent(Entity* p);
  ActorMovementComponent() = delete;
};
