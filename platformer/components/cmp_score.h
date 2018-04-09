
#pragma once
#include <ecm.h>

class Score : public Component {
protected:
  int scoreValue = 0;

public:
  void update(double dt) override;
  void render() override {}
  int returnScore();
   Score(Entity* p);
  Score() = delete;
};
