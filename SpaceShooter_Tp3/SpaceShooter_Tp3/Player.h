#pragma once
#include "Spaceship.h"

namespace spaceShooter
{
    class Player :public Spaceship
    {
    public:
        static Player* GetInstance();
        void SetLimits(const Vector2f point1, const Vector2f point2);
        void Notify(Subject* subject);
        bool Update(int commands);
    private:
        Player();
        ~Player();
        static Player* instance;
        Vector2f limitMin;
        Vector2f limitMax;
    };
}