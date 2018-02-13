#pragma once 

#include "scene.h"
#include <memory>
//this header contains some globaly accesible variables

//scene management code. workbook 4.2.3
//each individual scene will hold all global variables related to this scene. 
extern std::shared_ptr<Scene> gameScene;
extern std::shared_ptr<Scene> menuScene;
extern std::shared_ptr<Scene> activeScene;

//game scene. store all global variables here. 
class GameScene : public Scene {
private: 
	sf::Text text;
	sf::Clock scoreClock; 
	void respawn();

public: 
	GameScene() = default;
	void update(double dt) override;
	void render() override;
	void load() override; 
};

class MenuScene : public Scene {
private:
	sf::Text text;

public:
	MenuScene() = default;
	void update(double dt) override;
	void render() override;
	void load() override;
};
