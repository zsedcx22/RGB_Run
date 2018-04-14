#include "controls.h"
#include <stdexcept>

using namespace std;
using namespace sf;


map<std::string, Keyboard::Key> Controls::_keyTable;

void Controls::initialise()
{
	Controls::SetKey("Left", Keyboard::Left);
	Controls::SetKey("Right", Keyboard::Right);
	Controls::SetKey("Jump", Keyboard::Up);
	Controls::SetKey("Shoot", Keyboard::Space);

	Controls::SetKey("Red", Keyboard::Q);
	Controls::SetKey("Green", Keyboard::W);
	Controls::SetKey("Blue", Keyboard::E);

	Controls::SetKey("Pause", Keyboard::P);
	Controls::SetKey("Return", Keyboard::Escape);
}

Keyboard::Key Controls::GetKey(std::string action)
{
	auto k = _keyTable.find(action);
	if (k != _keyTable.end())
	{
		return k->second;
	}
	else
	{
		throw invalid_argument("Unknown Action ");
	}
}

void Controls::SetKey(string action, Keyboard::Key key)
{
	_keyTable[action] = key;
}