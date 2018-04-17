#pragma once
#include <ecm.h>
#include "../engine/src/system_resources.h"

class ShootingEnemy : public Component {
protected:
	unsigned int _counter;		//counts steps
	int _freq;	//how often can shoot

	sf::SoundBuffer _loadFire;
	sf::Sound _sndFire;

public:
	void update(double dt) override;
	void render() override {}
	explicit ShootingEnemy(Entity* p);

	ShootingEnemy() = delete;
};