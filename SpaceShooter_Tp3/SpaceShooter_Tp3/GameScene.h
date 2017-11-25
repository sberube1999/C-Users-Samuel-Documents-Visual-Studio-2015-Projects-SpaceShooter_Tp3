#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Background.h"
#include <string>
#include "Observer.h"

using namespace sf;

namespace spaceShooter
{ 
    class GameScene :public Scene, public Observer
	{
	public:
		GameScene();
        ~GameScene();
        scenes run();
        bool init(RenderWindow * const window);
        void getInputs();
        void update();
        void draw();
        void Notify(Subject* subject);

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