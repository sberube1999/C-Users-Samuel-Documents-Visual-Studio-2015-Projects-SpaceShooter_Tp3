#include "Player.h"

using namespace spaceShooter;

Player* Player::instance = nullptr;


Player::Player() :Spaceship()
{
}

Player::~Player()
{
}

Player * Player::GetInstance()
{
    if (instance == nullptr)
        instance = new Player();
    return instance;
}

void spaceShooter::Player::Notify(Subject * subject)
{

}

bool spaceShooter::Player::Update(int commands)
{
    bool res = Spaceship::Update();

    if (commands |= 1)
    {
        Move(LEFT);
    }
    if (commands |= 2)
    {
        Move(RIGHT);
    }

    return res;
}
