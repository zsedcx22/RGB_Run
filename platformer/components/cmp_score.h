#pragma once
#include <ecm.h>
#include "SFML\Graphics.hpp"

class Score : public Component {
protected:
	int _scoreValue;
	sf::Text score;

public:
  void update(double dt) override;
  void render() override {}
  int returnScore();
   Score(Entity* p);
  Score() = delete;
};
