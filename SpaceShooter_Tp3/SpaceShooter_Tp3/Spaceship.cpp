#include "Spaceship.h"

spaceShooter::Spaceship::Spaceship()
{
    speed = 2.5f;
    maxHealth = 1;
    curHealth = maxHealth;
    enable = false;
}

spaceShooter::Spaceship::~Spaceship()
{
    delete shape;
    shape = nullptr;
}

bool spaceShooter::Spaceship::Init(char path[])
{
    //Loader la texture
    if (!texture.loadFromFile(path))
        return false;
    shape->setTexture(&texture);
    //Ici tout s'est bien passé
    return true;
}

void spaceShooter::Spaceship::Hit(int points)
{
    //Faire perdre de la vie au joueur
    curHealth -= points;
}

void spaceShooter::Spaceship::Move(float dirX, float dirY)
{
    shape->move(dirX*speed, dirY*speed);
}

void spaceShooter::Spaceship::SetPosition(float x, float y)
{
    shape->setPosition(x, y);
}

void spaceShooter::Spaceship::SetPosition(Vector2f pos)
{
    shape->setPosition(pos);
}

void spaceShooter::Spaceship::Die()
{
    curHealth = 0;
    enable = false;
}

void spaceShooter::Spaceship::Draw(RenderWindow & mainWin)
{
    mainWin.draw(*shape);
}

bool spaceShooter::Spaceship::IsEnable()
{
    return enable;
}

void spaceShooter::Spaceship::SetEnable(const bool enable)
{
    this->enable = enable;
}
