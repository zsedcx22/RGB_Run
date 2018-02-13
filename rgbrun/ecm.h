//entity component model 

#pragma once 

#include <SFML/Graphics.hpp>
#include <vector>
#include <typeindex>
#include <memory>
#include <algorithm>

using namespace std;
using namespace sf;


//class Component, Entity copied from 4.3.1
class Component;	//forward declare 
struct EntityManager;	//forward declare 

class Entity {
protected:
	std::vector<std::shared_ptr<Component>> _components;
	sf::Vector2f _position;
	float _rotation;
	bool _alive;	//should be updated
	bool _visible;	//should be rendered 
	bool _fordeletion;	//should be deleted

public:
	
	Entity();
	virtual ~Entity();
	virtual void update(const double dt);
	virtual void render(sf::RenderWindow &window) const = 0;

	const sf::Vector2f &getPosition() const;
	void setPosition(const sf::Vector2f &_position);
	bool is_fordeletion() const;
	bool isAlive() const;
	void setAlive(bool _alive);
	void setForDelete();
	bool isVisible() const;
	void setVisible(bool _visible);

	//dont even ask. chapter 4.3.4
	template <typename T, typename... Targs>
	std::shared_ptr<T> addComponent(Targs... params) {
		static_assert(std::is_base_of<Component, T>::value, "must be a component");
		std::shared_ptr<T> sp(std::make_shared<T>(this, params...));
		_components.push_back(sp);
		return sp;
	}
};

struct EntityManager {
	std::vector<std::shared_ptr<Entity>> list;
	void update(double dt);
	void render(sf::RenderWindow &window);
};

class Component {
protected:
	Entity * const _parent;
	bool _fordeletion;
	explicit Component(Entity *const p);

public:
	Component() = delete;
	//bool is_fordeletion() const;		//for later use
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual ~Component();
};

//Everything below are components and templates.

class ShapeComponent : public Component  {
protected:
	std::shared_ptr<sf::Shape> _shape;
public:
	ShapeComponent() = delete;
	explicit ShapeComponent(Entity *p);

	void update(double dt) override;
	void render() override;

	sf::Shape &getShape() const;

	template <typename T, typename... Targs>
	void setShape(Targs... params) {
		_shape.reset(new T(params...));
	}
};


