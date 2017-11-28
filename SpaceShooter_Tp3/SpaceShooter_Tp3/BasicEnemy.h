#pragma once
#include "Enemy.h"
//<sberube>
namespace spaceShooter
{
	class BasicEnemy : public Enemy
	{
	public:
		BasicEnemy();
		bool Update(Vector2f target);
	private:
		bool goingRight;
		int idlePosition = rand() % 10 + 1;
	};
}
//</sberube>