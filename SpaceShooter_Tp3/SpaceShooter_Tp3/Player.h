#pragma once
#include "Spaceship.h"
#include "Weapon.h"

namespace spaceShooter
{
    class Player :public Spaceship
    {
    public:
        static Player* GetInstance();
        static void KillInstance();
        void SetLimits(const Vector2f point1, const Vector2f point2);
        void Notify(Subject* subject);
        bool Update(int commands);
        bool CanShoot();
        void Shoot();
        Vector2f GetDirection();
        Weapon::WeaponType GetWeaponType();
        int GetNbMunitions();
    private:
        Player();
        ~Player();
        static Player* instance;
        Vector2f limitMin;
        Vector2f limitMax;
        int curWepIndex;
        //temp
        vector<Weapon*> weapons;
        //
    };
}