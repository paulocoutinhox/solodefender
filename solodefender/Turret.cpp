#include "Turret.h"

Turret::Turret(void)
{

}

Turret::~Turret(void)
{
}

void Turret::initialize( float angle )
{
	image = Image::getImageByName("turret");
	sprite.SetTexture(image);

	radarImage = Image::getImageByName("radar");
	radarSprite.SetTexture(radarImage);

	shared_from_this()->angle = angle;

	speed   = Constants::ROTATION_SPEED;
	radius  = 170;
	width   = sprite.GetSize().x;
	height  = sprite.GetSize().y;
	originX = Constants::SCREEN_WIDTH / 2;
	originY = Constants::SCREEN_HEIGHT / 2;
	canFire = true;

	timeToFireWeapon        = 10;
	timeElapsedToFireWeapon = 0;
	
	sprite.SetOrigin(sprite.GetSize().x / 2, sprite.GetSize().y / 2); 
	radarSprite.SetOrigin(radarSprite.GetSize().x / 2, (radarSprite.GetSize().y / 2) - 100); 
}

void Turret::update()
{
	angle = Functions::calculateRotation(sprite, originX, originY, radius, speed, angle, 0);
	Functions::calculateRotation(radarSprite, originX, originY, radius, speed, angle, 0);
	
	if (canFire == false)
	{
		timeElapsedToFireWeapon += 0.1;

		if (timeElapsedToFireWeapon >= timeToFireWeapon)
		{
			canFire = true;
		}
	}

	if (canFire == true)
	{
		for (long x = 0; x < (long)GameObjects::enemies->size(); ++x)
		{
			
			boost::shared_ptr<Enemy> enemy = GameObjects::enemies->at(x);

			if (Collision::PixelPerfectTest(radarSprite, enemy->getSprite()))
			{
				canFire = false;
				timeElapsedToFireWeapon = 0;

				GameObjects::bullets->push_back(boost::shared_ptr<Bullet>(new Bullet(shared_from_this(), enemy)));

				break;
			}
			
		}
	}
}

sf::Sprite Turret::getSprite()
{
	return sprite;
}

sf::Sprite Turret::getRadarSprite()
{
	return radarSprite;
}

float Turret::getAngle()
{
	return angle;
}
