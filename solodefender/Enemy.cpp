#include "Enemy.h"

Enemy::Enemy(void)
{
	initialize(0, 0);
}

Enemy::Enemy(float x, float y)
{
	initialize(x, y);
}

Enemy::~Enemy(void)
{
}

void Enemy::initialize(float x, float y)
{
	image = Image::getImageByName("enemy");
		
	speed    = Constants::ENEMY_SPEED;
	radius   = 0;
	width    = sprite.GetSize().x;
	height   = sprite.GetSize().y;
	originX  = x;
	originY  = y;
	angle    = 0;
	targetX  = Constants::SCREEN_WIDTH / 2;
	targetY  = Constants::SCREEN_HEIGHT / 2;
	isActive = true;

	sprite.SetOrigin(sprite.GetSize().x / 2, sprite.GetSize().y / 2); 
	sprite.Move(originX, originY);
	sprite.SetTexture(image);
	updateSpriteDirection();
}

void Enemy::update()
{
	updateSpriteDirection();
	updatePosition();
	checkCollision();
}

sf::Sprite Enemy::getSprite()
{
	return sprite;
}

void Enemy::updatePosition()
{
	if (sprite.GetPosition().x > GameObjects::planet->getSprite().GetPosition().x)
	{
		sprite.SetPosition(sprite.GetPosition().x - speed, sprite.GetPosition().y);
	}

	if (sprite.GetPosition().x < GameObjects::planet->getSprite().GetPosition().x)
	{
		sprite.SetPosition(sprite.GetPosition().x + speed, sprite.GetPosition().y);
	}

	if (sprite.GetPosition().y > GameObjects::planet->getSprite().GetPosition().y)
	{
		sprite.SetPosition(sprite.GetPosition().x, sprite.GetPosition().y - speed);
	}

	if (sprite.GetPosition().y < GameObjects::planet->getSprite().GetPosition().y)
	{
		sprite.SetPosition(sprite.GetPosition().x, sprite.GetPosition().y + speed);
	}
}

void Enemy::checkCollision()
{
	if (Collision::PixelPerfectTest(sprite, GameObjects::planet->getSprite()))
	{
		remove();		
	} 
	else
	{

		for (long x = 0; x < (long)GameObjects::bullets->size(); ++x)
		{
			boost::shared_ptr<Bullet> bullet = GameObjects::bullets->at(x);
			
			if (Collision::PixelPerfectTest(sprite, bullet->getSprite()))
			{
				remove();			
				break;
			}
		}

	}
}

void Enemy::remove()
{
	GameObjects::enemies->erase(std::find(GameObjects::enemies->begin(), GameObjects::enemies->end(), shared_from_this()));
}

void Enemy::updateSpriteDirection() 
{
	sprite.SetRotation( Functions::angle(sprite.GetPosition().x, sprite.GetPosition().y, targetX, targetY) );
}

float Enemy::getAngle()
{
	return angle;
}
