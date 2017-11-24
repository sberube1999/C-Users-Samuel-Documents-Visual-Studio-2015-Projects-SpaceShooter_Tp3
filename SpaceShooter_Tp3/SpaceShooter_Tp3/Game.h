#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <string>

using namespace sf;

namespace spaceShooter
{ 
	class Game
	{
	public:
		Game();
		int run();
		int testTest();

	private:
		const int LARGEUR = 1280;
		const int HAUTEUR = 720;

		bool init();
		void getInputs();
		void update();
		void draw();

		RenderWindow mainWin;
		View view;
		Event event;

		//<sberube>
		Sprite background;
		Texture bgTexture;
		const std::string bgTexturePath = "Ressources\\Background.jpg";

		float leftLimit = 20;
		float rightLimit = mainWin.getSize().x - 20;
		//</sberube>
	};
}