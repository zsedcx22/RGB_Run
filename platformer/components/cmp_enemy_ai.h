#pragma once
#include "cmp_actor_movement.h"
#include "../engine/src/system_resources.h"
#include "ecm.h"
class EnemyAIComponent : public ActorMovementComponent {
private:
	float _normalSpeed;
	float _avoidSpeed;
	float _avoidDistanceX;		//x distance to start avoiding the the bullet 
	float _avoidDistanceY;		//distance to start avoiding the bullets


protected:
  sf::Vector2f _direction;
  float scrX;
  float scrY;

public:
  bool _canShoot;
  void getMovement(sf::Vector2f mov);
  void update(double dt) override;
 

  explicit EnemyAIComponent(Entity* p);
  
  EnemyAIComponent() = delete;
};
