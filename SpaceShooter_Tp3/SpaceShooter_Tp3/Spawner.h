#pragma once
//<sberube>
namespace spaceShooter
{
	enum Enemies
	{
		BASIC,
		KAMIKAZE,
		QUEEN,
		SHIELDER,
		CANNON
	};
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
		void SpawnMob(Enemies type, float posX, float posY);
		void SpawnBonus(Bonus type, float posX, float posY);
	};
}
//</sberube>