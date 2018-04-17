#include "engine.h"
#include "game.h"
#include "scenes/scene_menu.h"

using namespace std;

MenuScene menu;
Level1Scene level1;
OptionsScene options;

int main() {
  Engine::Start(1280, 720, "RgbRun",&menu);
}