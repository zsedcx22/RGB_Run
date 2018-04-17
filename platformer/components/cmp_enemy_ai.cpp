#include "cmp_enemy_ai.h"
#include <engine.h>
#include "../components/cmp_sprite.h"
using namespace std;
using namespace sf;

void EnemyAIComponent::update(double dt) {
 
  getMovement(_parent->getPosition());	//getMovement updates the _direction 
  auto mov = _direction * (float)(dt * _speed);
  move(mov * (float)(dt * _speed));
 
}



void EnemyAIComponent::getMovement(sf::Vector2f mov) {
	//reset stats
	_canShoot = true;
	_speed = _normalSpeed; 
	//get player 
	auto ply = this->_parent->scene->ents.find("player")[0];
	auto plyPos = ply->getPosition();

	//first avoid bullets
	auto plyBlt = this->_parent->scene->ents.find("bullet_player");
	for (auto i = plyBlt.begin(); i != plyBlt.end(); i++) {
		auto bullet = *i;
		auto bulletPos = bullet->getPosition();

		//check if bullet close enough to start avoiding
		if (bulletPos.x > mov.x - _avoidDistanceX && bulletPos.x < mov.x) {
			if (bulletPos.y >= mov.y - _avoidDistanceY && bulletPos.y < mov.y) {
				_direction.y = 1;
				_speed = _avoidSpeed;
				_canShoot = false;
				return;
			}
			else if (bulletPos.y <= mov.y + _avoidDistanceY && bulletPos.y > mov.y) {
				_direction.y = -1;
				_speed = _avoidSpeed;
				_canShoot = false;
				return;
			}

		}
	}

	//get direction which he is going and move in this direction
	if (plyPos.y < mov.y) {
		_direction.y = -1;

	}
	else if (plyPos.y >= mov.y) {
		_direction.y = 1;
	}

	//check if facing the player
	if (plyPos.y > mov.y - 30 && plyPos.y < mov.y + 30) {
		_direction.y = 0;
	}
}


EnemyAIComponent::EnemyAIComponent(Entity* p) : ActorMovementComponent(p) {
  _direction = Vector2f(0.f, 0.f);
  _speed = 150.0f;
  _normalSpeed = 100;	//100 and 110
  _avoidSpeed = 110;
  _avoidDistanceX = 400;		//x distance to start avoiding the the bullet 
  _avoidDistanceY = 150;

}
