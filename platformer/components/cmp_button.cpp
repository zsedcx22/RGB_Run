#include "cmp_button.h"
#include <SFML/Window/Mouse.hpp>

void ButtonComponent::update(double dt) {
	
	auto mousePos = Engine::GetWindow().mapPixelToCoords(sf::Mouse::getPosition(Engine::GetWindow()));
	if (_shapeComp->getShape().getGlobalBounds().contains(mousePos)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			pressed = true;
		}
	}
	else {
		pressed = false;
	}

}

void ButtonComponent::render()
{}

ButtonComponent::ButtonComponent(Entity* const p, std::shared_ptr<TextComponent> t,
	std::shared_ptr<ShapeComponent> s)
	: Component(p), _textComp(t), _shapeComp(s)  {
	pressed = false;
	
}

bool ButtonComponent::isPressed()
{
	return pressed;
}


