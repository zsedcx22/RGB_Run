
#include "cmp_bullet.h"
using namespace std;
using namespace sf;

void BulletComponent::update(double dt) {
	_lifetime -= dt;
	if (_lifetime <= 0.f) {
		_parent->setForDelete();
	}

	move(1500.f*dt, 0.f*dt);
}

void BulletComponent::move(float x, float y)
{
	auto pp = _parent->getPosition();
	pp.x += x;
	pp.y += y;

	_parent->setPosition(pp);
}

BulletComponent::BulletComponent(Entity* p, float lifetime)
	: Component(p), _lifetime(lifetime) {}