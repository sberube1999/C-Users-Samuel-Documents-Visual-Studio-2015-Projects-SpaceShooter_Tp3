#pragma once
#include "Enemy.h"
//<sberube>
namespace spaceShooter
{
	enum Bonus
	{
		WEAPON,
		SHIELD,
		BOMB,
		ELECTRO_BOMB,
		POINTS,
		PLAYER_SPEED,
		AMMO_SPEED,
		AMMO_SIZE,
		INVINCIBLE,
		SHIELD_COLOR
	};
	static class Spawner
	{
	public:
		static void SetPosition(float x, float y);
		static Enemy SpawnMob(Enemies type);
		static void SpawnBonus(Bonus type);
	private:
	};
}
//</sberube>