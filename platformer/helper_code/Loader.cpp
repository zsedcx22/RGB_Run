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
#include "../components/cmp_dm.h"
#include "../components/cmp_hurt_player.h"




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
	auto h = player->addComponent<HurtComponent>();
	return player;
}

std::shared_ptr<Entity> createPlatform(sf::Vector2f position, float speed, sf::Color color)
{
	auto wall = Engine::GetActiveScene()->makeEntity();
	wall->setPosition(position);
	wall->addTag("floor");

	//shape component 
	auto s = wall->addComponent<ShapeComponent>();
	s->setShape<sf::RectangleShape>(Vector2f(150.f, 30.f));
	s->getShape().setFillColor(color);

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
	enemyPlatform->addTag("enemy");
	auto s = enemyPlatform->addComponent<ShapeComponent>();
	s->setShape<sf::RectangleShape>(Vector2f(150.f, 30.f));
	s->getShape().setFillColor(Color::Yellow);

	auto hrt = enemyPlatform->addComponent<HurtEnemyComponent>();
	auto m = enemyPlatform->addComponent<ActorMovementComponent>();
	m->setSpeed(speed);

	return enemyPlatform;
}

std::shared_ptr<Entity> createShootingEnemy()
{
	auto shootingEnemy = Engine::GetActiveScene()->makeEntity();
	shootingEnemy->setPosition(Vector2f(Engine::getWindowSize().x - 30, Engine::getWindowSize().y + 100));
	shootingEnemy->addTag("enemy");

	auto s = shootingEnemy->addComponent<ShapeComponent>();
	s->setShape<sf::RectangleShape>(Vector2f(150.f, 80.f));
	s->getShape().setFillColor(Color::Yellow);

	auto mv = shootingEnemy->addComponent<EnemyAIComponent>();
	auto hrt = shootingEnemy->addComponent<HurtEnemyComponent>();
	auto sht = shootingEnemy->addComponent<ShootingEnemy>();

	return shootingEnemy;
}

std::shared_ptr<Entity> createText(sf::Vector2f position, float speed, sf::Color color, std::string text)
{
	auto txt = Engine::GetActiveScene()->makeEntity();
	txt->setPosition(position);

	auto c = txt->addComponent<TextComponent>(text,true);
	c->SetColour(color);
	c->SetPosition(position);

	auto m = txt->addComponent<ActorMovementComponent>();
	m->setSpeed(speed);


	return txt;

}

std::shared_ptr<Entity> createGameOver()
{
	//game over text
	auto txt = Engine::GetActiveScene()->makeEntity();
	txt->setPosition(Vector2f(Engine::getWindowSize().x / 2, Engine::getWindowSize().y / 2));

	int score;
	auto temp = Engine::GetActiveScene()->ents.find("player");
	for (auto ply : temp) {
		score = ply->GetCompatibleComponent<Score>()[0]->returnScore();
	}
	auto c = txt->addComponent<TextComponent>("Game Over", false);
	c->SetColour(Color::White);
	c->SetPosition(Vector2f(Engine::getWindowSize().x / 2, Engine::getWindowSize().y - (Engine::getWindowSize().y * 0.2)));
	c->SetSize(100);

	auto m = txt->addComponent<ActorMovementComponent>();
	m->setSpeed(0);

	createText(Vector2f(Engine::getWindowSize().x + 140, 50), -150, Color::White, "Press RETURN to go to menu");
	createText(Vector2f(Engine::getWindowSize().x + 140, 150), -150, Color::White, "Press FIRE to try again");
	
	//score text
	auto txt2 = Engine::GetActiveScene()->makeEntity();
	txt2->setPosition(Vector2f(Engine::getWindowSize().x +250, Engine::getWindowSize().y / 2));
	auto m2 = txt2->addComponent<ActorMovementComponent>();
	m->setSpeed(100);
	auto c2 = txt2->addComponent<TextComponent>(std::to_string(score) + 'm', true);
	c2->SetColour(Color::White);
	c2->SetPosition(Vector2f(Engine::getWindowSize().x + 250, Engine::getWindowSize().y / 2));
	c2->SetSize(200);


	return txt;



}

std::shared_ptr<Entity> createDungeonMaster()
{
	auto dm = Engine::GetActiveScene()->makeEntity();
	auto x = dm->addComponent<DMComponent>();

	return dm;
}

std::shared_ptr<Entity> createEnemyBullet(sf::Vector2f position, sf::Color color)
{
	auto bullet = Engine::GetActiveScene()->makeEntity();
	bullet->setPosition(position);
	bullet->addTag("enemy");
	auto s = bullet->addComponent<BulletComponent>();
	s->setDirection(-1);
	auto p = bullet->addComponent<ShapeComponent>();
	p->setShape<sf::RectangleShape>(Vector2f(5.f, 5.f));
	p->getShape().setFillColor(color);
	p->getShape().setOrigin(-40, 0);

	return bullet;
}

std::shared_ptr<Entity> createPlayerBullet(sf::Vector2f position, sf::Color color)
{
	auto bullet = Engine::GetActiveScene()->makeEntity();
	bullet->setPosition(position);
	bullet->addTag("bullet_player");
	auto s = bullet->addComponent<BulletComponent>();
	s->setDirection(1);
	auto p = bullet->addComponent<ShapeComponent>();
	p->setShape<sf::RectangleShape>(Vector2f(5.f, 5.f));
	p->getShape().setFillColor(color);
	p->getShape().setOrigin(-40, 0);
	
	return bullet;
}

