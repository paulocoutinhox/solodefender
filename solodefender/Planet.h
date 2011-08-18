#pragma once

#include <SFML/Graphics.hpp>
#include "Functions.h"
#include "Constants.h"
#include "Image.h"

class Planet
{
	public:
		Planet(void);
		~Planet(void);
		
		void update();	
		sf::Sprite getSprite();

	private:
		sf::Texture image;
		sf::Sprite sprite;

		float speed;
		float radius;
		float angle;
		float width;
		float height;
		float originX;
		float originY;

		void initialize();			
};
