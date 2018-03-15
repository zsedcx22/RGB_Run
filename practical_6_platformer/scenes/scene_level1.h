#pragma once

#include "engine.h"

class Level1Scene : public Scene {
private:
	int _frameCount;
	int _generateSpeed = 1000;

public:
  void Load() override;

  void UnLoad() override;

  void Update(const double& dt) override;

  void Render() override;

  void GenerateBlocks();
};
