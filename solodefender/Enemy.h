#pragma once

#include <SFML/Graphics.hpp>
#include "Functions.h"
#include "Constants.h"
#include "GameObjects.h"
#include "Collision.h"
#include "Image.h"

#include "boost/smart_ptr.hpp"


class Enemy : public boost::enable_shared_from_this<Enemy>
{
	public:
		Enemy(void);
		Enemy(float x, float y);
		~Enemy(void);
		void update();
		void remove();

		sf::Sprite getSprite();

		float getAngle();

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
		float targetX;
		float targetY;

		bool isActive;

		void initialize(float x, float y);			
		void updatePosition();
		void checkCollision();
		void updateSpriteDirection();		
		
};
