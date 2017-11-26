#pragma once
#include <SFML\Graphics.hpp>
#include <string>
using namespace sf;

namespace spaceShooter
{
	class Bonus
	{
	public:
		bool Init();
		virtual void Update(float speed);
		void Draw(RenderWindow &win);
		virtual void ApplyEffect() = 0;
	private:

		Sprite sprite;
		Texture texture;
		std::string texturePath;
	};
}