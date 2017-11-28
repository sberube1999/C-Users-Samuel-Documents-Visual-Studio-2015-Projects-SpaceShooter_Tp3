#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Background.h"
#include <string>
#include "Observer.h"
#include "Player.h"
#include "BasicEnemy.h"
#include "DQueue.h"
using namespace sf;

namespace spaceShooter
{ 
    class GameScene :public Scene, public Observer
	{
	public:
		GameScene();
        ~GameScene();
        scenes run();
        bool init(RenderWindow * const window);
        void getInputs();
        void update();
        void draw();
        void Notify(Subject* subject);

	private:

        //<smasson>
        void UpdateHUD();

        const int LBL_SPACEMENT = 150;

        Font font;

        int interfaceCommande;

        int default = 0;
        //Labels de statistiques
        Text scoreMultiplicatorLabel;
        Text currentScoreLabel;
        Text lifesLabel;
        Text shieldLabel;
        Text curWeaponLabel;
        Text munitionsLabel;
        Text nextEnemyLabel;
        
        Player* player;
        Shape* testShape;

        //</smasson>

		//<sberube>

		Background background;
		BasicEnemy enem;
		BasicEnemy enem2;
		BasicEnemy enem3;

		//</sberube>
	};
}