#include "cmp_shooting_enemy.h"
#include "cmp_bullet.h"
#include <engine.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void ShootingEnemy::update(double dt) {
	if (_counter >= _freq) {
		//fire bullet 
		auto bullet = Component::_parent->scene->makeEntity();
		bullet->setPosition(_parent->getPosition());
		bullet->addTag("bullet");
		auto s = bullet->addComponent<BulletComponent>();
		s->setDirection(-1);
		auto p = bullet->addComponent<ShapeComponent>();
		p->setShape<sf::RectangleShape>(Vector2f(5.f, 5.f));
		p->getShape().setFillColor(_parent->GetCompatibleComponent<ShapeComponent>()[0]->getShape().getFillColor());
		p->getShape().setOrigin(-40, 0);

		_counter = 0;
	}
	else _counter+= 1;
}

ShootingEnemy::ShootingEnemy(Entity* p)
	: Component(p) {}
