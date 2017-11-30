//<sberube>
#include "BasicEnemy.h"
#include "Background.h"
using namespace spaceShooter;
static float leftLimit;
static float rightLimit;
BasicEnemy::BasicEnemy() : Enemy::Enemy()
{
	shape = new ConvexShape(6);
	ConvexShape* temp = (ConvexShape*)shape;
	temp->setPoint(0, Vector2f(0, 0));
	temp->setPoint(1, Vector2f(25, 60));
	temp->setPoint(2, Vector2f(-25, 60));
	temp->setScale(0.5f, 0.5f);

	speed = 3;
	SetColor(Color::Green);
	shape->setRotation(180);

	if ((rand() % 2 + 1) == 2)
	{
		goingRight = true;
	}
	else
	{
		goingRight = false;
	}
}
bool BasicEnemy::Update(Vector2f target)
{

	if (shape->getPosition().y < idlePosition * 10 + 20)
	{
		Move(0, 1);
	}
	else
	{
		if (goingRight)
		{
			Move(1, 0);
			if (shape->getPosition().x >= Background::RightLimit() - 20)
			{
				goingRight = false;
			}
		}
		else
		{
			Move(-1, 0);
			if (shape->getPosition().x <= Background::LeftLimit() + 20)
			{
				goingRight = true;
			}
		}
	}
	if (shape->getPosition().x > target.x - 20 && shape->getPosition().x < target.x + 20)
	{
		// Shoot
	}
	return true;
}
//</sberube>