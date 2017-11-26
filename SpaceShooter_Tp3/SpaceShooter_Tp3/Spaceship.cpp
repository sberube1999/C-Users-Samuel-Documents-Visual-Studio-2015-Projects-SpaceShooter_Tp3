#include "Spaceship.h"

spaceShooter::Spaceship::Spaceship()
{
    speed = 2.5f;
    maxHealth = 1;
    curHealth = maxHealth;
    shape = new ConvexShape(6);
    shape->setScale(20, 20);
    enable = true;
}

spaceShooter::Spaceship::~Spaceship()
{
    delete shape;
    shape = nullptr;
    delete moveIdle;
    moveIdle = nullptr;
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

bool spaceShooter::Spaceship::Update()
{
    //Retourner si le vaisseau est en vie ou ne l'est pas
    return curHealth > 0;
}

void spaceShooter::Spaceship::Move(Direction dir)
{
    switch (dir)
    {
    case NONE:
        //Rien à faire
        break;
    case LEFT:
        //On bouge à gauche
        shape->move(-1, 0);
        break;
    case RIGHT:
        //On bouge à droite
        shape->move(1, 0);
        break;
    case UP:
        //On bouge en haut
        shape->move(0, 1);
        break;
    case DOWN:
        //On bouge en bas
        shape->move(0, -1);
        break;
    }
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
