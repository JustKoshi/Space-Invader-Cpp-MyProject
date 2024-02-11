#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

class Laser {
	sf::Vector2f position;
	float speed;
	bool isAlive;
public:
	Laser();
	Laser(sf::Vector2f position, float speed);
	void Update();
    void Draw(sf::RenderWindow& window);
	bool IsAlive();
};