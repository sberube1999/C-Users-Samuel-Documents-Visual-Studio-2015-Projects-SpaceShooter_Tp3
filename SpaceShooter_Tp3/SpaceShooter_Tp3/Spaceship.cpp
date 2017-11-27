#include "Spaceship.h"

spaceShooter::Spaceship::Spaceship()
{
    speed = 2.5f;
    maxHealth = 1;
    curHealth = maxHealth;
    shape = new ConvexShape(6);
    ConvexShape* temp = (ConvexShape*)shape;
    temp->setPoint(0, Vector2f(0, 0));
    temp->setPoint(1, Vector2f(45, 145));
    temp->setPoint(2, Vector2f(-45, 145));
    temp->setScale(0.5f, 0.5f);
    enable = false;
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

Shape & spaceShooter::Spaceship::GetShape()
{
    return *shape;
}
