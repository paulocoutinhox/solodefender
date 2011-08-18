#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp> 

#include "Planet.h"
#include "Turret.h"
#include "GameObjects.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Timer.h"

#include "StringConverter.h"

#include "boost/shared_ptr.hpp"

int main()
{
	sf::RenderWindow App(sf::VideoMode(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, Constants::SCREEN_COLOR), "Solo Defender");
	App.SetFramerateLimit(Constants::SCREEN_FRAMERATE);
	
	sf::Clock Clock;
    
	boost::shared_ptr<Image> imageTurret(new Image("turret", "turret.png"));
	boost::shared_ptr<Image> imageRadar(new Image("radar", "radar.png"));
	boost::shared_ptr<Image> imageEnemy(new Image("enemy", "enemy.png"));
	boost::shared_ptr<Image> imagePlanet(new Image("planet", "planet.png"));
	boost::shared_ptr<Image> imageBullet(new Image("bullet", "bullet.png"));
	boost::shared_ptr<Image> imageBackground(new Image("background", "background.png"));

	GameObjects::images->push_back(imageTurret);
	GameObjects::images->push_back(imageRadar);
	GameObjects::images->push_back(imageEnemy);
	GameObjects::images->push_back(imagePlanet);
	GameObjects::images->push_back(imageBullet);
	GameObjects::images->push_back(imageBackground);

	GameObjects::planet = boost::shared_ptr<Planet>(new Planet());;
	
	boost::shared_ptr<Turret> turret1(new Turret());
	boost::shared_ptr<Turret> turret2(new Turret());
	boost::shared_ptr<Turret> turret3(new Turret());
	boost::shared_ptr<Turret> turret4(new Turret());
	boost::shared_ptr<Turret> turret5(new Turret());
	
	turret1->initialize(0);
	turret2->initialize(72);
	turret3->initialize(144);
	turret4->initialize(216);
	turret5->initialize(288);

	GameObjects::turrets->push_back(turret1);
	GameObjects::turrets->push_back(turret2);
	GameObjects::turrets->push_back(turret3);
	GameObjects::turrets->push_back(turret4);
	GameObjects::turrets->push_back(turret5);
	
	sf::Texture backgroundImage;
	backgroundImage = Image::getImageByName("background");
	
	sf::Sprite backgroundSprite(backgroundImage);

	Timer timer;	
	
	while (App.IsOpened())
	{
        float ElapsedTime = App.GetFrameTime();
		
		GameObjects::planet->update();	
		
		for (std::vector< boost::shared_ptr<Turret> >::iterator it = GameObjects::turrets->begin(); it!=GameObjects::turrets->end(); ++it) {
			((boost::shared_ptr<Turret>)*it)->update();
		}

		for (long x = 0; x < (long)GameObjects::enemies->size(); ++x)
		{
			boost::shared_ptr<Enemy> enemy = GameObjects::enemies->at(x);
			enemy->update();
		}

		for (long x = 0; x < (long)GameObjects::bullets->size(); ++x)
		{
			boost::shared_ptr<Bullet> bullet = GameObjects::bullets->at(x);
			bullet->update();
		}

        sf::Event Close;
        while (App.PollEvent(Close)) 
		{

            if (Close.Type == sf::Event::Closed)
			{
                App.Close();
			}
            if ((Close.Type == sf::Event::KeyPressed) && (Close.Key.Code == sf::Keyboard::Escape))
			{
                App.Close();
			}
			if ((Close.Type == sf::Event::KeyPressed) && (Close.Key.Code == sf::Keyboard::Space))
			{
				/*
				for (std::vector<Turret*>::iterator it = GameObjects::turrets->begin(); it!=GameObjects::turrets->end(); ++it) {
					Bullet *bullet = new Bullet(*it);
					GameObjects::bullets->push_back(bullet);
				}
				*/
			}
			if ((Close.Type == sf::Event::KeyPressed) && (Close.Key.Code == sf::Keyboard::R))
			{
				Constants::SHOW_RADAR = !Constants::SHOW_RADAR;
			}

        }

		if (timer.elasped(500000))
		{
			int random = (rand()%4)+1;
			float x = 0;
			float y = 0;

			if (random == 2)
			{
				x = Constants::SCREEN_WIDTH;
			}
			else if (random == 3)
			{
				x = Constants::SCREEN_WIDTH;
				y = Constants::SCREEN_HEIGHT;
			}
			else if (random == 4)
			{
				y = Constants::SCREEN_HEIGHT;
			}

			GameObjects::enemies->push_back(boost::shared_ptr<Enemy>(new Enemy(x, y)));
		}
		
		App.Draw(backgroundSprite);

		for (std::vector< boost::shared_ptr<Turret> >::iterator it = GameObjects::turrets->begin(); it!=GameObjects::turrets->end(); ++it) {
			App.Draw(((boost::shared_ptr<Turret>)*it)->getSprite());

			if (Constants::SHOW_RADAR == true)
			{
				App.Draw(((boost::shared_ptr<Turret>)*it)->getRadarSprite());
			}			
		}
		
		App.Draw(GameObjects::planet->getSprite());

		for (std::vector< boost::shared_ptr<Enemy> >::iterator it = GameObjects::enemies->begin(); it!=GameObjects::enemies->end(); ++it) {
			App.Draw(((boost::shared_ptr<Enemy>)*it)->getSprite());
		}
		
		for (long x = 0; x < (long)GameObjects::bullets->size(); ++x)
		{
			boost::shared_ptr<Bullet> bullet = GameObjects::bullets->at(x);
			App.Draw(bullet->getSprite());
		}
		
		sf::Text textEnemies( "Enemies: " + StringConverter::toString(GameObjects::enemies->size()) );
		textEnemies.SetPosition(5, 5);
		textEnemies.SetCharacterSize(13);

		sf::Text textBullets( "Bullets: " + StringConverter::toString(GameObjects::bullets->size()) );
		textBullets.SetPosition(5, 25);
		textBullets.SetCharacterSize(13);
		
		App.Draw(textEnemies);
		App.Draw(textBullets);

        App.Display();
        App.Clear(); 
    }

    return EXIT_SUCCESS;
}
