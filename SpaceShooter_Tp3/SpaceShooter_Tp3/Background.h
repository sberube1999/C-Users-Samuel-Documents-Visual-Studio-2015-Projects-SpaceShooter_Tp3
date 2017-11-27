#pragma once
// <sberube>
#include "Star.h"
#include <vector>
namespace spaceShooter
{ 
	class Background
	{
	public:

		Background();

		bool Init(RenderWindow &win);
		void Update(RenderWindow &win);
		void Draw(RenderWindow &win);

	private:

		const float bgSpeed = 1;

		Sprite background;
		Texture bgTexture;
		const std::string bgTexturePath = "Ressources\\Background\\Background.jpg";

		Sprite left;
		Texture leftTexture;
		const std::string leftTexturePath = "Ressources\\Background\\LeftHUD.png";

		Sprite right;
		Texture rightTexture;
		const std::string rightTexturePath = "Ressources\\Background\\RightHUD.png";

		// Pour l'instant on y va avec un tableau.
		std::vector<Star> stars;
		const int nbStars = 200;
		const float starSpeed = 2;
	};
}
// </sberube>