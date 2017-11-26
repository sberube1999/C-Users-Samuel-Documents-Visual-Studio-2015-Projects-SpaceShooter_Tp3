#pragma once
#include <SFML\Graphics.hpp>
#include "Observer.h"

using namespace sf;

namespace spaceShooter
{
    class Spaceship :public Observer
    {
    public:
        Spaceship();
        ~Spaceship();
        bool Init(char path[]);
        virtual void Hit(int points);
        virtual bool Update();
        virtual void Notify(Subject* subject)=0;
        static enum Direction
        {
            NONE,
            LEFT,
            RIGHT,
            UP,
            DOWN
        };
        void Move(Direction dir);
        void SetPosition(float x, float y);
        void SetPosition(Vector2f pos);
        virtual void Die();
        void Draw(RenderWindow& mainWin);
        bool IsEnable();
    protected:
        Texture texture;
        Shape* shape; //Pointeur, car pas de constructeur par défaut
        float speed, maxHealth, curHealth;
        Vector2f* moveIdle;
        bool enable;
    };
}