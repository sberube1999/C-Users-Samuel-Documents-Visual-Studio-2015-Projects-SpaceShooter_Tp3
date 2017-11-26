#include "Bonus.h"
using namespace spaceShooter;

bool Bonus::Init()
{
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}
	sprite.setTexture(texture);
	return true;
}
void Bonus::Update(float speed)
{
	sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + speed);
}
void Bonus::Draw(RenderWindow &win)
{
	win.draw(sprite);
}