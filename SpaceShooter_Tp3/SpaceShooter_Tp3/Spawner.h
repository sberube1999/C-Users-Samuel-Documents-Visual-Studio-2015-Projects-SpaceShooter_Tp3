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
	//enum Weapons
	//{
	//	LASER_GUN,
	//	DEATH_RAY,
	//	STAR_GUN,
	//	CANON
	//};
	static class Spawner
	{
	public:
		static void SpawnMob(Enemies type);
		static void SpawnBonus(Bonus type);
	private:
		float posX;
		float posY;
	};
}
//</sberube>