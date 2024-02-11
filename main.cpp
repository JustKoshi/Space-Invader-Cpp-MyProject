#include "SFML/Graphics.hpp"
#include "Headers/Player.hpp"
#include "Headers/Enemy.hpp"
#include "Headers/Laser.hpp"

sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");
sf::Event event;


int main() {
	sf::Texture texture;
	if(!texture.loadFromFile("Resources/background.png"))
	{
		return 1;
	}
	Player player;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		window.clear();
        window.draw(sf::Sprite(texture));
		player.Update();
		player.Draw(window);
		
		window.display();
	}
	return 0;
}
