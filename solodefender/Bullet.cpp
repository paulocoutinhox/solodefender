#include "Bullet.h"

Bullet::Bullet(boost::shared_ptr<Turret> turret, boost::shared_ptr<Enemy> enemy)
{
	angle   = - turret->getAngle();
	targetX = enemy->getSprite().GetPosition().x;
	targetY = enemy->getSprite().GetPosition().y;
	initialize();
}

Bullet::~Bullet(void)
{

}

void Bullet::initialize()
{
	image = Image::getImageByName("bullet");
	sprite.SetTexture(image);

	speedX  = 3;
	speedY  = 3;
	radius  = 205;
	width   = sprite.GetSize().x;
	height  = sprite.GetSize().y;
	originX = Constants::SCREEN_WIDTH / 2;
	originY = Constants::SCREEN_HEIGHT / 2;
	sprite.SetOrigin(sprite.GetSize().x / 2, sprite.GetSize().y / 2); 

	angle = Functions::calculateRotation(sprite, originX, originY, radius, Constants::BULLET_SPEED, angle, 0);
	angle = Functions::angleBetweenVectors(sprite.GetPosition(), sf::Vector2<float>(targetX, targetY));

	updateSpeed();
}

void Bullet::update()
{
	checkCollision();	
	updatePosition();
}

sf::Sprite Bullet::getSprite()
{
	return sprite;
}

void Bullet::remove()
{
	GameObjects::bullets->erase(std::find(GameObjects::bullets->begin(), GameObjects::bullets->end(), shared_from_this()));
}

void Bullet::updateSpriteDirection() 
{
	sprite.SetRotation( Functions::angle(sprite.GetPosition().x, sprite.GetPosition().y, targetX, targetY) );
}

void Bullet::checkCollision()
{
	if (sprite.GetPosition().x + sprite.GetSize().x < 0)
	{
		remove();
	}
	else if (sprite.GetPosition().y + sprite.GetSize().y < 0)
	{
		remove();
	}
	else if (sprite.GetPosition().x > Constants::SCREEN_WIDTH)
	{
		remove();
	}
	else if (sprite.GetPosition().y > Constants::SCREEN_HEIGHT)
	{
		remove();
	}
}

void Bullet::updatePosition()
{
	float nx = Constants::BULLET_SPEED * cos(angle * 0.01745);
	float ny = Constants::BULLET_SPEED * sin(angle * 0.01745);
	sprite.Move(nx, ny);
	sprite.SetRotation(360 - angle); 
}

void Bullet::updateSpeed()
{
	if (sprite.GetPosition().x < targetX)
	{
		speedX = Constants::BULLET_SPEED;
	}

	if (sprite.GetPosition().x > targetX)
	{
		speedX = (Constants::BULLET_SPEED * -1);
	}

	if (sprite.GetPosition().y < targetY)
	{
		speedY = Constants::BULLET_SPEED;
	}

	if (sprite.GetPosition().y > targetY)
	{
		speedY = (Constants::BULLET_SPEED * -1);
	}
}