#pragma once

#include <SFML/Graphics.hpp>
#include "Functions.h"
#include "Constants.h"
#include "GameObjects.h"
#include "Turret.h"
#include "Enemy.h"
#include "Image.h"

#include "boost/smart_ptr.hpp"
#include "boost/enable_shared_from_this.hpp"

class Turret;
class Enemy;

class Bullet : public boost::enable_shared_from_this<Bullet>
{
	public:
		Bullet(boost::shared_ptr<Turret> turret, boost::shared_ptr<Enemy> enemy);
		~Bullet(void);

		void update();	

		void updatePosition();

		sf::Sprite getSprite();

	private:
		sf::Texture image;
		sf::Sprite sprite;

		float speedX;
		float speedY;
		float radius;
		float angle;
		float width;
		float height;
		float originX;
		float originY;
		float targetX;
		float targetY;
		
		//boost::shared_ptr<Turret> turret;
		//boost::shared_ptr<Enemy> enemy;
		
		void initialize();			
		void remove();
		void updateSpriteDirection();
		void checkCollision();
		void updateSpeed();
};
