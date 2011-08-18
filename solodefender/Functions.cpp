#include "Functions.h"

const float Functions::DEG = (float)(180 / 3.141592653589793);

Functions::Functions(void)
{
}

Functions::~Functions(void)
{
}

float Functions::calculateRotation(sf::Sprite &sprite, float posX, float posY, float radius, float speed, float angle, float angleOffset)
{
	float rad = (float)(angle * (3.1415 / -180));
			
	sprite.SetPosition(posX + radius * sin(rad), posY + radius * cos(rad));
	
	angle -= speed;	
	angle = fmod(angle, 360);
	
	if (angle == 0) 
	{
		angle = 360;
	}
	
	sprite.SetRotation(angle + angleOffset);

	return angle;
}

float Functions::angle( float x1, float y1, float x2, float y2 )
{
	float angle = atan2(y2 - y1, x2 - x1) * DEG;
	return angle < 0 ? angle + 360 : angle;
}

float Functions::angleBetweenVectors(sf::Vector2f a, sf::Vector2f b){
	return 57.3065f * atan2(b.y - a.y, b.x - a.x);
}
