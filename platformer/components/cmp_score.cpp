#include "cmp_score.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;

void Score::update(double dt) {
	if (_parent->isAlive() == true) {
		scoreValue += 1;
	}
	
}

int Score::returnScore() {
	return scoreValue;
}

Score::Score(Entity* p)
    : scoreValue(0), Component(p) {}
