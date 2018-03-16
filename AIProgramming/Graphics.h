#pragma once;

#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Node.h"

namespace ASnamespace
{
	class Graphics{
		public:
			Graphics(){};
			~Graphics(){};

			int Initialize(std::vector<Node> &result);
			void Draw(std::vector<Node> &result);
			void setTilePosition(std::vector<Node> &result, std::vector<sf::Sprite> &sprites);

			std::vector<sf::Sprite> getSprites() { return sprites; };

		private:
			sf::RenderWindow window;
			sf::Texture texture;
			sf::Sprite sprite;
			std::vector<sf::Sprite> sprites;
	};
}