#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include "system_resources.h"
#include <ecm.h>

class PlayerMovementComponent : public Component {
private:

	float dirX = 0;
	float dirY = 0;
	float _platformMovement;	//the x speed of the platform the player is standing on
	int falling = 1;
	float _y_acceleration;
	const float _gravity = 70.0f;

	sf::SoundBuffer _loadShoot;
	sf::SoundBuffer _loadcolChange;
	sf::Sound _sndShoot;
	sf::Sound _sndColChange;

protected:
	bool validMove(const sf::Vector2f&);
	//current speed.
	float _speed;
	float _pulse;

	//collision swiches
	bool _grounded;
	bool _jumping;
	bool _mvLeft;
	bool _mvRight;
	bool _firePressed;
	bool _alive;
	bool _showGameOver;

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
	void fireBullet(sf::Vector2f pos);
	void updateMovement(sf::Vector2f pos, double dt);
	void setDead();
	PlayerMovementComponent(Entity* p);
	PlayerMovementComponent() = delete;
};