#include "Headers/Player.hpp"

Player::Player(): position(400.0f, 550.f) {
	texture.loadFromFile("Resources/rocket.png");
	sprite.setTexture(texture);
	speed = 0.06f;
	shootCooldown = 1.0f;
}

void Player::Draw(sf::RenderWindow& window) {
	sprite.setScale(2.5f, 2.5f);
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
	for (const auto& laser : lasers) {
		if (laser->IsAlive())
		laser->Draw(window);
	}
}

void Player::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		if (position.x < 0) {
			position.x = 0;
		}
		position.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		if (position.x + sprite.getLocalBounds().width > 780) {
			position.x = 780 - sprite.getLocalBounds().width;
		}
		position.x += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && (shootTimer.getElapsedTime().asSeconds() >= shootCooldown)) {
		sf::Vector2<float> temp = position;
		temp.x+=sprite.getLocalBounds().width;
		temp.y-=sprite.getLocalBounds().height;
		lasers.push_back(std::make_unique<Laser>(temp, speed));
		shootTimer.restart();
	}
	for (auto it = lasers.begin(); it != lasers.end();) {
		(*it)->Update();
		if ((*it)->IsAlive())
		{
			++it;
		}
		else
		{
			it = lasers.erase(it);
		}
	}
}

sf::Vector2f Player::GetPosition() {
	return position;
}


std::vector<std::unique_ptr<Laser>>& Player::GetLasers() {
	return lasers;
}