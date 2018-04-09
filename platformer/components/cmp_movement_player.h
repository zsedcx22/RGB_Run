#pragma once
#include <ecm.h>

class PlayerMovementComponent : public Component {
private:
	//debug things
	//bool keyPressed = false;

protected:
  bool validMove(const sf::Vector2f&);
  //current speed.
  float _speed=40.f;
  
  // -1,0 or 1;
  int dirX = 0;
  int dirY = 0;
  int falling = 1;
  
  //collision swiches
  bool _grounded = false;
  bool _jumping = true;
  bool _mvLeft = true;
  bool _mvRight = true;
  
  


  float _pulse = 7.0f;
  float _y_acceleration = 0.f;
  //float _x_acceleration = 0.f;
  const float _friction = 2.f;
  const float _gravity = 9.8f;

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
  void getCollision(sf::Vector2f pos);

  void updatePhysics();
  void updateMovement(sf::Vector2f pos,double dt);

   PlayerMovementComponent(Entity* p);
  PlayerMovementComponent() = delete;
};
