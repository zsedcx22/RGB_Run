#pragma once
#pragma once
#include <ecm.h>

class DMComponent : public Component {
private:
	int _frameCount= 0;
	int _generateSpeed = 110;
	int _gameState = 2;
	int _lastColour = 0;
	int _genCounter = 0;
	int _platHGen = 250.f;
	int _platLGen = 1280.f;

protected:
  float _speed;
 
public:
  void update(double dt) override;
  void render() override {}
  void loadEntites();
  int getRandom(int min, int max);

   DMComponent(Entity* p);
  DMComponent() = delete;
};
