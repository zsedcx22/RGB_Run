#pragma once
#include <ecm.h>

class BulletComponent : public Component {
protected:
	float _lifetime;
	int _dir;
public:
	void update(double dt) override;
	void render() override {}
	void move(float x, float y);
	void setDirection(int dir);
	explicit BulletComponent(Entity* p, float lifetime = 3.f);
	BulletComponent() = delete;
};