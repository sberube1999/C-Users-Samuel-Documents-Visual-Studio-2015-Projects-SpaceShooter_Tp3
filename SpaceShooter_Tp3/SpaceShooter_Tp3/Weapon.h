#pragma once
#include <SFML\Graphics.hpp>
#include "Projectile.h"

using namespace sf;

namespace spaceShooter
{
    class Weapon
    {
    public:
        Weapon(const float cadency, const int nbProjs, const Projectile::ProjectileType type);
        ~Weapon();
        bool CanShoot();
        void Shoot();
        Projectile::ProjectileType GetProjType() const;
    private:
        int nbProjs;
        float cadency;
        Clock clock;
        Time timerDur;
        Projectile::ProjectileType projType;
    };
}