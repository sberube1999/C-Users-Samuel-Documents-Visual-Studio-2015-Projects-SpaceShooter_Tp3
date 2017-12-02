#pragma once
//<sberube>
#include "Spaceship.h"

namespace spaceShooter
{
	enum Enemies
	{
		BASIC,
		KAMIKAZE,
		QUEEN,
		REFLECTOR,
		BOSS_CANNON
	};
	class Enemy : public Spaceship
	{
	public:
		Enemy();
		virtual bool Update(Vector2f target);
		void SetColor(Color color);
	//virtual void Shoot() = 0;
	protected:
		Time lastFire;
		Time cadency;
		Clock fireClock;
		bool isSlave;
		Enemies type;
		Color color;
		int idlePosition = (rand() % 10 + 1) * 10 + 30;
	};
}
//</sberube>