#pragma once

class Constants
{
	public:
		Constants(void);
		~Constants(void);

		static const int SCREEN_WIDTH     = 800;
		static const int SCREEN_HEIGHT    = 600;
		static const int SCREEN_FRAMERATE = 60;
		static const int SCREEN_COLOR     = 32;
		static float ROTATION_SPEED;
		static float BULLET_SPEED;
		static bool  SHOW_RADAR;
		static float ENEMY_SPEED;
};
