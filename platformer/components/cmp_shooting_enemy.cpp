#include "cmp_shooting_enemy.h"
#include "cmp_sprite.h"
#include "../helper_code/Loader.h"
#include "system_resources.h"
#include <engine.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

void ShootingEnemy::update(double dt) {
	if (_counter >= _freq) {
		createEnemyBullet(_parent->getPosition(), _parent->GetCompatibleComponent<ShapeComponent>()[0]->getShape().getFillColor());
		_sndFire.play();
		_counter = 0;
	}
	else _counter += 1;
}

ShootingEnemy::ShootingEnemy(Entity* p)
	: Component(p) {
	_freq = 50;

	_loadFire = *(Resources::get<SoundBuffer>("fire.wav"));
	_sndFire.setBuffer(_loadFire);
}
