#include "Player.h"
#include "GlobalMath.h"

using namespace spaceShooter;

Player* Player::instance = nullptr;


Player::Player() :Spaceship()
{
	shape = new ConvexShape(6);
	ConvexShape* temp = (ConvexShape*)shape;
	temp->setPoint(0, Vector2f(0, 0));
	temp->setPoint(1, Vector2f(45, 100));
	temp->setPoint(2, Vector2f(-45, 100));
	temp->setScale(0.5f, 0.5f);
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

void spaceShooter::Player::SetLimits(const Vector2f point1, const Vector2f point2)
{
    limitMin = point1;
    limitMax = point2;
}

void spaceShooter::Player::Notify(Subject * subject)
{

}

bool spaceShooter::Player::Update(int commands)
{
    Vector2f dir(0, 0);

    //gauche
    if (commands & 1)
    {
        dir.x = -1;
    }
    //droite
    else if (commands & 2)
    {
        dir.x = 1;
    }
    //haut
    if (commands & 4)
    {
        dir.y = -1;
    }
    //bas
    else if (commands & 8)
    {
        dir.y = 1;
    }

    //Bouger
    Move(dir.x, dir.y);
    //Vérifier limites
    shape->setPosition(GlobalMath::InspectPos(shape->getPosition(), limitMin, limitMax));

    if (commands == 8)
    {
        //espace, pour les bombes
    }
    if (commands == 10)
    {
        //q, pour les changements d'armes
    }

    return curHealth > 0;
}
