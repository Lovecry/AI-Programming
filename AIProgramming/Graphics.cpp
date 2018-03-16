#include "Graphics.h"

namespace ASnamespace
{


	void Graphics::setTilePosition(std::vector<Node> &result, std::vector<sf::Sprite> &sprites)
	{
		if (!result.empty())
		{
			Node config = result.back();
			result.pop_back();

			for (int index = 0; index < 16; ++index)
			if (config.getConfigurationIndexed(index) != 16)
				sprites.at(config.getConfigurationIndexed(index) - 1).setPosition((index % 4) * 100.0f, (index / 4) * 100.0f);
		}
	}

	int Graphics::Initialize(std::vector<Node> &result) {

		window.create(sf::VideoMode(400, 400), "15 Puzzle", sf::Style::Close);
		window.setVerticalSyncEnabled(true);

		if (!texture.loadFromFile("Sprites/15.png"))
			return -1;
		texture.setSmooth(true);

		sprite.setTexture(texture);

		for (int index = 0; index < 15; ++index)
		{
			sprite.setTextureRect(sf::IntRect((index % 4) * 100, (index / 4) * 100, 100, 100));
			sprites.push_back(sprite);
		}
		setTilePosition(result, sprites);
		return 0;
	}


	void Graphics::Draw(std::vector<Node> &result) {
		while (window.isOpen())
		{
			window.clear(sf::Color(33, 33, 33));

			for (int index = 0; index < 15; ++index)
				window.draw(sprites[index]);

			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				else if (event.type == sf::Event::KeyPressed){
					if (event.key.code == sf::Keyboard::Escape)
						window.close();
				}
			}
			setTilePosition(result, sprites);
			sleep(sf::milliseconds(500));

			window.display();
		}
	}
}