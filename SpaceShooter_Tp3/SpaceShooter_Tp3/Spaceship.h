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
       // virtual void Notify(Subject* subject)=0;
        void Move(float dirX, float dirY);
        void SetPosition(float x, float y);
        void SetPosition(Vector2f pos);
        virtual void Die();
        void Draw(RenderWindow& mainWin);
        bool IsEnable();
        void SetEnable(const bool enable);
        Shape& GetShape();
        int GetCurrentHealth();
    protected:
        Texture texture;
        Shape* shape; //Pointeur, car pas de constructeur par défaut
        float speed;
        int maxHealth, curHealth;
        bool enable;
    };
}