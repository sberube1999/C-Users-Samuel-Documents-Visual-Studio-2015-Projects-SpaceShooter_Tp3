#pragma once
#include <SFML\Graphics.hpp>
#include "StaticSubject.h"
#include "Spaceship.h"

using namespace sf;
using namespace spaceShooter;

namespace spaceShooter
{
    class Projectile :public StaticSubject
    {
    public:
        Projectile(const Color color, const float speed, Spaceship& owner);
        ~Projectile();
        static enum ProjectileType
        {
            UNDEFINED,
            LAZER_PROJ,
            BULLET,
            BASIC,
            ETOILE
        };
        void Start(const Vector2f dir, Vector2f position);
        void SetTexture(const Texture& texture);
        void Draw(RenderWindow& mainWin);
        void SetOwner(Spaceship& newOwner);
        Color GetColor();
        Spaceship& GetOwner();
        void Update();
        bool IsEnable();
        void SetEnable(bool enable);
    private:
        Spaceship* owner;
        Shape* shape;
        float speed;
        Vector2f dir;
        bool isEnable;
    };
}