#pragma once

#include <SFML/Graphics.hpp>
#include "Functions.h"
#include "Constants.h"
#include "GameObjects.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Image.h"

#include "boost/smart_ptr.hpp"

class Turret : public boost::enable_shared_from_this<Turret>
{
	public:
		Turret(void);
		~Turret(void);

		void update();	

		sf::Sprite getSprite();
		sf::Sprite getRadarSprite();
		float getAngle();
		void initialize(float angle);

	private:
		sf::Texture image;
		sf::Sprite sprite;

		sf::Texture radarImage;
		sf::Sprite radarSprite;

		float speed;
		float radius;
		float angle;
		float width;
		float height;
		float originX;
		float originY;

		float timeToFireWeapon;
		float timeElapsedToFireWeapon;
		bool canFire;
		
};
