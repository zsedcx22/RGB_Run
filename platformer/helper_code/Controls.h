#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class Controls {
private: 
	static std::map<std::string, sf::Keyboard::Key> _keyTable;

public:
	static void initialise();
	static sf::Keyboard::Key GetKey(std::string action);
	static void SetKey(std::string action, sf::Keyboard::Key key); 
	};