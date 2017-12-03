//<sberube>
#include "Enemy.h"
using namespace spaceShooter;

Enemy::Enemy() : Spaceship::Spaceship()
{
	isSlave = false;
	type = Enemies::BASIC;
}

bool Enemy::Update(Vector2f target)
{
	return curHealth > 0;
}

void Enemy::SetColor(Color color)
{
	sprite->setColor(color);
}
//</sberube>