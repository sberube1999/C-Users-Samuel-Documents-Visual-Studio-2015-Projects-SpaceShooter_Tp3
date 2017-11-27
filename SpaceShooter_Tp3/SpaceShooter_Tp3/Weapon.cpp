#include "Weapon.h"

Weapon::Weapon(const float cadency, const int nbProjs, const Projectile::ProjectileType type) :nbProjs(nbProjs), cadency(cadency), projType(type)
{
    clock.restart();
    timerDur = seconds(cadency);
}

Weapon::~Weapon()
{

}

bool Weapon::CanShoot()
{
    return clock.getElapsedTime().asSeconds() > timerDur.asSeconds();
}

void Weapon::Shoot()
{
    clock.restart();
    --nbProjs;
}

Projectile::ProjectileType spaceShooter::Weapon::GetProjType() const
{
    return projType;
}


