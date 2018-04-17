#include "cmp_hurt_player.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_movement_player.h"
#include <engine.h>

using namespace std;
using namespace sf;

void HurtComponent::update(double dt) {
  if (auto pl = _player.lock()) {
	  auto pShape = pl->GetCompatibleComponent<ShapeComponent>()[0]->getShape().getGlobalBounds();

	  auto en = _parent->scene->ents.find("enemy");
	  for (auto e : en) {
		  auto eShape = e->GetCompatibleComponent<ShapeComponent>()[0]->getShape().getGlobalBounds();
		  if (pShape.intersects(eShape)) {
			  //move player out of the screen, movement component will do the rest.
			  pl->setPosition(Vector2f(Vector2f(250, Engine::getWindowSize().y + 120)));	  
		  }
	  }
  }
}

HurtComponent::HurtComponent(Entity* p)
    : Component(p), _player(_parent->scene->ents.find("player")[0]) {}
