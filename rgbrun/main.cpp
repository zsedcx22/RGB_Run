#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Resource_Handler.h"
#include "rgbRun.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;

void Reset() {
	
}

void Load(RenderWindow &window) {
	//load scenes from rgbRun.h
	gameScene.reset(new GameScene());
	menuScene.reset(new MenuScene());
	gameScene->load();
	menuScene->load();

	//in the future we will use menu scene as a start
	activeScene = gameScene;
}

void Update(RenderWindow &window) {

	static Clock clock;
	float dt = clock.restart().asSeconds();

	//all updates go through the active scene
	activeScene->update(dt);


	//check and consume events
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}

	//quit via esc key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
}

void Render(RenderWindow &window) {
	//render() calls all drawable objects and stacks their sprites/shapes/text into a list
	activeScene->render();
	
	//take the list produced above and draw everything using the renderer
	Renderer::render();
}

int main() {
	RenderWindow window(VideoMode(800, 600), "engine");
	Load(window);
	Reset();

	while(window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}

