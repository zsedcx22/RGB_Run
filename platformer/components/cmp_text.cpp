#include "cmp_text.h"
#include <system_renderer.h>
#include <system_resources.h>

void TextComponent::update(double dt) {
	if (_movable) {
		this->SetPosition(sf::Vector2f(_parent->getPosition().x + _speed, _parent->getPosition().y));
	}
}

void TextComponent::render() { Renderer::queue(&_text); }

TextComponent::TextComponent(Entity* const p, const std::string& str, bool mov)
    : Component(p), _string(str) {
  _text.setString(_string);
  _font = Resources::get<sf::Font>("RobotoMono-Regular.ttf");
  _text.setFont(*_font);
  _movable = mov;
  _speed = -150;
}

void TextComponent::ReplaceText(sf::Text newTxt)
{
	_text = newTxt;
}

void TextComponent::SetText(const std::string& str) {
  _string = str;
  _text.setString(_string);
}

void TextComponent::SetColour(sf::Color col)
{
	_text.setColor(col);
}

void TextComponent::SetPosition(sf::Vector2f pos)
{
	_text.setPosition(pos);
	
}

void TextComponent::SetSize(int i)
{
	_text.setCharacterSize(i);
}

sf::Text TextComponent::GetText()
{
	return _text;
}

