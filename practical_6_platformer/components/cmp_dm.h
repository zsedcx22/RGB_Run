#pragma once
#pragma once
#include <ecm.h>

class DMComponent : public Component {
private:
	int _frameCount= 0;
	int _generateSpeed = 1500;

protected:

  float _speed=0.f;
 
public:
	
  void update(double dt) override;
  void render() override {}
  void loadEntites();

   DMComponent(Entity* p);
  DMComponent() = delete;
};
