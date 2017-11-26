#pragma once
#include "Spaceship.h"

namespace spaceShooter
{
    class Player :public Spaceship
    {
    public:
        static Player* GetInstance();
        void Notify(Subject* subject);
        bool Update(int commands);
    private:
        Player();
        ~Player();
        static Player* instance;
    };
}