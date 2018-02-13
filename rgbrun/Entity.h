#pragma once
#include <SFML/Graphics.hpp>
#include "rgbRun.h"
#include "ecm.h"
#include <memory>

struct EntityManager {
	std::vector<std::shared_ptr<Entity>> list;
	void update(double dt);
	void render(sf::RenderWindow &window);
};
