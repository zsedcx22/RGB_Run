#include "system_renderer.h";
#include <queue>

using namespace sf;
using namespace std;
//Renderer stuff page 4.2.2
//Comments are of what I think this stuff does, no explanation provided in the workbook


static queue<const Drawable *> drawable;

//renderWindow is used to call the .draw() command
static RenderWindow *rw;

//set the renderer to point to the specified window
void Renderer::initialise(sf::RenderWindow &r) { rw = &r; }

sf::RenderWindow &Renderer::getWindow() { return *rw; }

void Renderer::shutdown() {
	while (!drawable.empty())
		drawable.pop();
}

void Renderer::update(const double &) {}

//actual rendering, here we can control which things are drawn first ect.
void Renderer::render() {
	if (rw == nullptr) {
		throw("No render window set! ");
	}
	//for now there is only a simple while loop that iterates throuh the list of all drawable objects.
	while (!drawable.empty()) {
		rw->draw(*drawable.front());
		drawable.pop();
	}
}

//add new item to the list of rendering objects. 
void Renderer::queue(const sf::Drawable *s) { drawable.push(s); }
