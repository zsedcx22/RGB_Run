#include "cmp_physics.h"

class PlatformPhysicsComponent : public PhysicsComponent {
protected:
	b2Vec2 _size;
	sf::Vector2f _maxVelocity;

public:
	void update(double dt) override;

	explicit PlatformPhysicsComponent(Entity* p, const sf::Vector2f& size);

	PlatformPhysicsComponent() = delete;
};
