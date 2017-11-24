// <sberube>
#include "Background.h"
using namespace spaceShooter;

Background::Background()
{

}
bool Background::Init(RenderWindow &win)
{
	srand(time(NULL));
	// l'image de fond
	if (!bgTexture.loadFromFile(bgTexturePath))
	{
		return false;
	}
	background.setTexture(bgTexture);
	background.setOrigin(bgTexture.getSize().x / 2, bgTexture.getSize().y / 2);
	background.setPosition(win.getSize().x / 2, 0);


	// les étoiles
	for (size_t i = 0; i < nbStars; i++)
	{
		Star star;
		star.SetPosition(rand() % (int)(background.getPosition().x + bgTexture.getSize().x / 10) + (background.getPosition().x - bgTexture.getSize().x / 2),
					     rand() % win.getSize().y);
		stars.push_back(star);
	}


	// Les côtés
	if (!leftTexture.loadFromFile(leftTexturePath))
	{
		return false;
	}
	left.setTexture(leftTexture);
	left.setOrigin(leftTexture.getSize().x / 2, leftTexture.getSize().y / 2);
	left.setPosition(leftTexture.getSize().x / 2, leftTexture.getSize().y / 2);

	if (!rightTexture.loadFromFile(rightTexturePath))
	{
		return false;
	}
	right.setTexture(rightTexture);
	right.setOrigin(rightTexture.getSize().x / 2, rightTexture.getSize().y / 2);
	right.setPosition(win.getSize().x - rightTexture.getSize().x / 2, rightTexture.getSize().y / 2);


	return true;
}
void Background::Update(RenderWindow &win)
{
	// l'image de fond
	background.setPosition(background.getPosition().x, background.getPosition().y + bgSpeed);
	if (background.getPosition().y - bgTexture.getSize().y / 2 > 0)
	{
		background.setPosition(win.getSize().x / 2, 0);
	}
	// les étoiles
	for (size_t i = 0; i < stars.size(); i++)
	{
		stars.at(i).Update();
		if (stars.at(i).GetPosition().y > win.getSize().y)
		{
			stars.at(i).SetPosition(rand() % (int)(background.getPosition().x + bgTexture.getSize().x / 10) + (background.getPosition().x - bgTexture.getSize().x / 2), 0);
		}
	}
}
void Background::Draw(RenderWindow &win)
{
	// Les côtés
	win.draw(left);
	win.draw(right);
	// l'image de fond
	win.draw(background);
	// les étoiles
	for (size_t i = 0; i < stars.size(); i++)
	{
		stars.at(i).Draw(win);
	}
}
// </sberube>