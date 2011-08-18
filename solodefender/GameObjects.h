#pragma once

#include <SFML/System.hpp>
#include "Planet.h"
#include "Turret.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Image.h"
#include "boost/smart_ptr.hpp"

class Turret;
class Bullet;
class Enemy;
class Image;
class Planet;

class GameObjects
{
	public:
		GameObjects(void);
		~GameObjects(void);

		static boost::shared_ptr<Planet> planet;
		
		static std::vector< boost::shared_ptr <Bullet> > *bullets;
		static std::vector< boost::shared_ptr <Turret> > *turrets;
		static std::vector< boost::shared_ptr <Enemy> > *enemies;
		static std::vector< boost::shared_ptr <Image> > *images;
};
