#include "Planet.h"

Planet::Planet(void)
{
	initialize();
}

Planet::~Planet(void)
{
}

void Planet::initialize()
{
	image = Image::getImageByName("planet");
	sprite.SetTexture(image);

	speed   = Constants::ROTATION_SPEED;
	radius  = 0;
	angle   = 0;
	width   = sprite.GetSize().x;
	height  = sprite.GetSize().y;
	originX = Constants::SCREEN_WIDTH / 2;
	originY = Constants::SCREEN_HEIGHT / 2;
	
	sprite.SetOrigin(sprite.GetSize().x / 2, sprite.GetSize().y / 2); 
}

void Planet::update()
{
	angle = Functions::calculateRotation(sprite, originX, originY, radius, speed, angle, 14);
}

sf::Sprite Planet::getSprite()
{
	return sprite;
}