#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Background.h"
#include <string>

using namespace sf;

namespace spaceShooter
{ 
	class GameScene:public Scene
	{
	public:
		GameScene();
        ~GameScene();

        scenes run();
        bool init(RenderWindow * const window);
        void getInputs();
        void update();
        void draw();

	private:

        //<smasson>

        int interfaceCommande;

        //</smasson>

		//<sberube>

		Background background;

		/*float leftLimit = 20;
		float rightLimit = mainWin.getSize().x - 20;*/
		//</sberube>
	};
}