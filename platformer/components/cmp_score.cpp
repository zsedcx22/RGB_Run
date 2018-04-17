#include "cmp_score.h"
#include "../helper_code/Loader.h"
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;

void Score::update(double dt) {
	if (_parent->isAlive() == true) {
		_scoreValue += 1;
	}

}

int Score::returnScore() {
	//distace traveled
	return _scoreValue * 0.3;
}

Score::Score(Entity* p)
    : _scoreValue(0), Component(p) {
	_scoreValue = 0;
}
