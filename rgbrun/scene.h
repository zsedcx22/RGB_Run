#pragma once 
#include "Entity.h"
#include "ecm.h"
#include <memory>
//scenes are created in the rgbRun.cpp

class Scene {
public: 
	Scene() = default; 

	virtual ~Scene() = default;
	virtual void update(double dt);
	virtual void render();
	virtual void load() = 0;
	std::vector<std::shared_ptr<Entity>> &getEnts();

protected:
	EntityManager _ents;
};