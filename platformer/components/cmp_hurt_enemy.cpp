#include "cmp_hurt_enemy.h"
#include <engine.h>
#include "cmp_sprite.h"
using namespace std;
using namespace sf;

void HurtEnemyComponent::update(double dt) {
	//get shape
	auto shape = _parent->GetCompatibleComponent<ShapeComponent>()[0]->getShape().getGlobalBounds();
	//get bullets and check their collision with parent
	auto plyBlt = this->_parent->scene->ents.find("bullet_player");
	for (auto i = plyBlt.begin(); i != plyBlt.end(); i++) {
		auto bullet = *i;
		auto shapeBullet = bullet->GetCompatibleComponent<ShapeComponent>()[0]->getShape().getGlobalBounds();
		if (shape.intersects(shapeBullet)) {
			//collision = true; delete enemy
			_sndExplode.play();
			_parent->setForDelete();
		}
	}
}

HurtEnemyComponent::HurtEnemyComponent(Entity* p)
	: Component(p) {
	_loadExplode = *(Resources::get<SoundBuffer>("enemyExplode.wav"));
	_sndExplode.setBuffer(_loadExplode);
}
