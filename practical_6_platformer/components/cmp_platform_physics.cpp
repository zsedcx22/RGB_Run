#include "cmp_platform_physics.h"
#include "system_physics.h"
#include <LevelSystem.h>
#include <SFML/Window/Keyboard.hpp>

using namespace std;
using namespace sf;
using namespace Physics;


void PlatformPhysicsComponent::update(double dt) {

	const auto pos = _parent->getPosition();
	impulse({ (float)(dt * 100), 0 });
		


	// Clamp velocity.
	auto v = getVelocity();
	v.x = copysign(min(abs(v.x), _maxVelocity.x), v.x);
	v.y = copysign(min(abs(v.y), _maxVelocity.y), v.y);
	setVelocity(v);

	PhysicsComponent::update(dt);
}

PlatformPhysicsComponent::PlatformPhysicsComponent(Entity* p,
	const Vector2f& size)
	: PhysicsComponent(p, true, size) {
	_size = sv2_to_bv2(size, true);
	_maxVelocity = Vector2f(200.f, 400.f);
	_body->SetSleepingAllowed(false);
	_body->SetFixedRotation(true);
	//Bullet items have higher-res collision detection
	_body->SetBullet(true);
}
