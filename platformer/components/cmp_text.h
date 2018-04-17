#pragma once

#include <SFML/Graphics/Text.hpp>
#include <ecm.h>

class TextComponent : public Component {
public:
  TextComponent() = delete;
  explicit TextComponent(Entity* p, const std::string& str = "", bool mov = false);
  void update(double dt) override;

  void render() override;

  ~TextComponent() override = default;
  void ReplaceText(sf::Text newTxt);
  void SetText(const std::string& str);
  void SetColour(sf::Color col);
  void SetPosition(sf::Vector2f pos);
  void SetSize(int i);
  sf::Text GetText();

protected:
	bool _movable;
	float _speed;
  std::shared_ptr<sf::Font> _font;
  std::string _string;
  sf::Text _text;
};
