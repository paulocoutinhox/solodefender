#pragma once

#include <SFML/Graphics.hpp>

class Functions
{
	public:
		Functions(void);
		~Functions(void);
		
		static const float DEG;

		static float calculateRotation(sf::Sprite &sprite, float posX, float posY, float radius, float speed, float angle, float angleOffset);
		static float angle(float x1, float y1, float x2, float y2);
		static float angleBetweenVectors(sf::Vector2f a, sf::Vector2f b);
};
