#include "ProjectileGenerator.h"

Projectile * spaceShooter::ProjectileGenerator::GetProjectile(Projectile::ProjectileType type)
{
    Projectile* res = nullptr;

    switch (type)
    {
    case Projectile::ProjectileType::BASIC:
        res = new Projectile(4.5f, 15, Player::GetInstance()->GetShape().getFillColor(), 6.5f, Player::GetInstance());
        break;
    }

    return res;
}
