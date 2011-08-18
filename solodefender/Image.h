#pragma once

#include <SFML/Graphics.hpp>
#include "GameObjects.h"
#include "ResourcePath.hpp"

#include "boost/smart_ptr.hpp"

class Image
{
	public:
		Image(std::string name, std::string imagePath);
		~Image(void);
		
		static sf::Texture getImageByName(std::string name);
		
		std::string getName() { return name; }
		std::string setName(std::string value) { this->name = value; }

		sf::Texture getImage() { return image; }

	private:
		std::string name;
		sf::Texture image;
};
