#pragma once

#include <ecm.h>
#include "cmp_text.h"
#include "cmp_sprite.h"
#include <SFML/Graphics/Text.hpp>

#include "engine.h"

class ButtonComponent : public Component {
protected:
	bool pressed;
	std::shared_ptr<ShapeComponent> _shapeComp;
	std::shared_ptr<TextComponent> _textComp;

public:
  ButtonComponent() = delete;
  explicit ButtonComponent(Entity* p, std::shared_ptr<TextComponent> t, 
	  std::shared_ptr<ShapeComponent> s);
  bool isPressed();

  void update(double dt) override;

  void render() override;

  ~ButtonComponent() override = default;


};
