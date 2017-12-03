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
        static bool Init(char path[]);
        void AdjustVisual();
	private:
		bool goingRight;
		int idlePosition = rand() % 10 + 1;
        static Texture texture;
	};
}
//</sberube>