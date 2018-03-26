#pragma once
#include <ecm.h>

class PlayerMovementComponent : public Component {
private:
	//debug things
	//bool keyPressed = false;

protected:
  bool validMove(const sf::Vector2f&);
  float _speed=0.f;
  bool _grounded = false;
 // bool _jumping = false;
  

  float _pulse = 600.0f *3;
  float _y_acceleration = 0.f;
  //float _x_acceleration = 0.f;
  const float _friction = 4.f;
  const float _gravity = 3.0f;

public:
  void update(double dt) override;
  void move(const sf::Vector2f&);
  void move(float x, float y);
  void render() override {}
  void setSpeed(float spd);
  bool isGrounded(sf::Vector2f pos);
  float getYPosition(float y);
  void updateJump();
  void loadEntites();

  void updatePhysics();
  void updateMovement();

   PlayerMovementComponent(Entity* p);
  PlayerMovementComponent() = delete;
};
