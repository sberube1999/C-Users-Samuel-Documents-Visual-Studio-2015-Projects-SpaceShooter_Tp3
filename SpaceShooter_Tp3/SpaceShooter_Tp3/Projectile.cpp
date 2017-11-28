#include "Projectile.h"

spaceShooter::Projectile::Projectile(const Color color, const float speed, Spaceship & owner) :speed(speed), owner(&owner)
{
    shape->setFillColor(color);
    isEnable = false;
}

spaceShooter::Projectile::~Projectile()
{
    //Clean-up
    owner = nullptr;
    delete owner, shape;
    shape = nullptr;
}

void spaceShooter::Projectile::Start(const Vector2f dir, Vector2f position)
{
    this->dir = dir;
    shape->setPosition(position);
}

void spaceShooter::Projectile::SetTexture(const Texture& texture)
{
    shape->setTexture(&texture);
}

void spaceShooter::Projectile::Draw(RenderWindow & mainWin)
{
    mainWin.draw(*shape);
}

void spaceShooter::Projectile::SetOwner(Spaceship & newOwner)
{
    this->owner = &newOwner;
}

Color spaceShooter::Projectile::GetColor()
{
    return shape->getFillColor();
}

Spaceship & spaceShooter::Projectile::GetOwner()
{
    return *this->owner;
}

void spaceShooter::Projectile::Update()
{
    //Avancer le projectile dans la direction à sa vitesse
    shape->move(dir.x*speed, dir.y*speed);
    //Vérifier les collisions des projectiles ici avec ses observateurs
    //Pour chacun de mes observateurs
    for (Observer* curObserver : *GetCurObservers())
    {
        //Si mon observateur est un spaceship
        if (typeid(curObserver) == typeid(Spaceship))
        {
            //Conversion de mon observateur en spaceship
            Spaceship* curSpaceShip = (Spaceship*)curObserver;
            //Si mon observateur est enable et qu'il collide avec moi, alors
            if (curSpaceShip->IsEnable() && curSpaceShip->GetShape().getTextureRect().intersects(shape->getTextureRect()))
            {
                //Notifier l'observateur
                curObserver->Notify((Subject*)this);
            }
        }
    }
}

bool spaceShooter::Projectile::IsEnable()
{
    return this->isEnable;
}

void spaceShooter::Projectile::SetEnable(bool enable)
{
    this->isEnable = enable;
}
