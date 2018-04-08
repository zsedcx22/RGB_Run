#pragma once
#include <ecm.h>

class ShootingEnemy : public Component {
protected:
	unsigned int _counter;		//counts steps
	int _freq = 50;	//how often can shoot

public:
	void update(double dt) override;
	void render() override {}
	explicit ShootingEnemy(Entity* p);

	ShootingEnemy() = delete;
};