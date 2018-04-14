#include "Loader.h"
#include "engine.h"
#include "../components/cmp_score.h"
#include "../components/cmp_actor_movement.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_bullet.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_movement_player.h"
#include "../components/cmp_text.h"
#include "../components/cmp_button.h"
#include "../components/cmp_enemy_ai.h"
#include "../components/cmp_shooting_enemy.h"
#include "../components/cmp_hurt_enemy.h"

using namespace std;
using namespace sf;

shared_ptr<Entity> createPlayer() {
	auto player = Engine::GetActiveScene()->makeEntity();
	player->addTag("player");
	auto d = player->addComponent<Score>();
	auto s = player->addComponent<ShapeComponent>();
	s->setShape<sf::RectangleShape>(Vector2f(20.f, 30.f));
	s->getShape().setFillColor(Color::Red);
	s->getShape().setOrigin(10.f, 15.f);
	auto q = player->addComponent<PlayerMovementComponent>();

	return player;
}

std::shared_ptr<Entity> createPlatform(sf::Vector2f position, float speed)
{
	auto wall = Engine::GetActiveScene()->makeEntity();
	wall->setPosition(position);
	wall->addTag("floor");

	//shape component 
	auto s = wall->addComponent<ShapeComponent>();
	s->setShape<sf::RectangleShape>(Vector2f(150.f, 30.f));
	s->getShape().setFillColor(Color::White);

	//movement 
	auto m = wall->addComponent<ActorMovementComponent>();
	m->setSpeed(speed);

	return wall;
}

shared_ptr<Entity> createButton(std::string text)
{
	auto button = Engine::GetActiveScene()->makeEntity();
	button->addTag("button");
	auto s = button->addComponent<ShapeComponent>();
	s->setShape<RectangleShape>(Vector2f(130.0f, 60.0f));

	//button text
	auto t = button->addComponent<TextComponent>(text);
	t->SetColour(Color::Blue);
	button->addComponent<ButtonComponent>(t, s);

	return button;
}

std::shared_ptr<Entity> createEnemyPlatform(sf::Vector2f position, float speed)
{
	auto enemyPlatform = Engine::GetActiveScene()->makeEntity();
	enemyPlatform->setPosition(position);

	auto s = enemyPlatform->addComponent<ShapeComponent>();
	s->setShape<sf::RectangleShape>(Vector2f(150.f, 40.f));
	s->getShape().setFillColor(Color::Yellow);
	auto hrt = enemyPlatform->addComponent<HurtEnemyComponent>();
	auto m = enemyPlatform->addComponent<ActorMovementComponent>();

	return enemyPlatform;
}

