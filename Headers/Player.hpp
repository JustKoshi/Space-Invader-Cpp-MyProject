#pragma once
#include "SFML/Graphics.hpp"
#include "Headers/Laser.hpp"

class Player {
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
	std::vector<std::unique_ptr<Laser>> lasers;
	sf::Clock shootTimer;
	float shootCooldown;

	public:
	Player();

	void Draw(sf::RenderWindow& window);
	void Update();
	sf::Vector2f GetPosition();
	std::vector<std::unique_ptr<Laser>>& GetLasers();

};