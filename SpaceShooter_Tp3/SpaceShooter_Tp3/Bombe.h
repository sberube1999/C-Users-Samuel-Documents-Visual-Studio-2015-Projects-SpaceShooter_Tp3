#pragma once
#include "Projectile.h"


namespace spaceShooter
{
	class Bombe : Projectile
	{
	public:
		Bombe(const float x, const float y, const Color color, const float speed, Spaceship* owner);
		bool Update(Vector2f target);
	private:
		float radius;
	};
}