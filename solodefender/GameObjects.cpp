#include "GameObjects.h"

boost::shared_ptr<Planet> GameObjects::planet;

std::vector< boost::shared_ptr<Bullet> > *GameObjects::bullets = new std::vector<boost::shared_ptr<Bullet> >();
std::vector< boost::shared_ptr<Turret> > *GameObjects::turrets = new std::vector<boost::shared_ptr<Turret> >();
std::vector< boost::shared_ptr<Enemy> >  *GameObjects::enemies = new std::vector<boost::shared_ptr<Enemy> >();
std::vector< boost::shared_ptr<Image> >  *GameObjects::images  = new std::vector< boost::shared_ptr<Image> >();

GameObjects::GameObjects(void)
{

}

GameObjects::~GameObjects(void)
{
}

;
