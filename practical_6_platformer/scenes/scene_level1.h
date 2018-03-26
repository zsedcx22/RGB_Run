#pragma once

#include "engine.h"

class Level1Scene : public Scene {

private:
	

public:
	
  void Load() override;

  void UnLoad() override;

  void Update(const double& dt) override;

  void Render() override;

  void GenerateBlocks();
};
