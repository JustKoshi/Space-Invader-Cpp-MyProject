#include "Headers/Laser.hpp"
#include <iostream>

Laser::Laser(sf::Vector2f pos, float speed2) {
	speed = speed2;
	position = pos;
	isAlive = true;
}

void Laser::Update() {
	if(isAlive && position.y >0)
		position.y -= speed;
	else {
		isAlive = false;
		std::cout<<"Laser is dead"<<std::endl;
	}
}

void Laser::Draw(sf::RenderWindow &window) {
	if (isAlive) {
		sf::RectangleShape laser(sf::Vector2f(5, 20));
		laser.setFillColor(sf::Color::Red);
		laser.setPosition(position);
		window.draw(laser);
	}
}

bool Laser::IsAlive() {
	return isAlive;
}