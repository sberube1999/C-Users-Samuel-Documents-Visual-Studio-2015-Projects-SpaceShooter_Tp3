#include "GameScene.h"
#include "GameStyle.h"
#include "ProjectileGenerator.h"
#include "GlobalMath.h"
//Debug
#include <iostream>
using namespace std;
//

using namespace spaceShooter;

GameScene::GameScene()
{
    player = Player::GetInstance();
}

GameScene::~GameScene()
{
    //Clean-up
    //Clear du vecteur
    for (Projectile* curProj : basicProjectiles)
        delete curProj;
    basicProjectiles.clear();
    //Destruction du joueur
    player->KillInstance();
    //Clean up adresses
    player = nullptr;
}

Scene::scenes GameScene::run()
{

    while (isRunning)
    {
        getInputs();
        update();
        draw();
    }

    return transitionVersScene;
}

bool GameScene::init(RenderWindow * const window)
{
    enem.SetPosition(500, 10);
    enem.Init("");
    enem2.SetPosition(400, 10);
    enem2.Init("");
    enem3.SetPosition(600, 10);
    enem3.Init("");
    if (!background.Init(*window))
    {
        return false;
    }
    // <smasson>
    /*if (!ambianceMusic.openFromFile("Ressources\\Sounds\\Music.ogg"))
    {
    return false;
    }*/
    //Init du font:
    if (!font.loadFromFile("Ressources\\Fonts\\STJEDISE.ttf"))
        return false;
    //</smasson>

#pragma region HUD
    //<smasson>
    //Initialisation du HUD
    //Le multiplicateur de score:
    scoreMultiplicatorLabel.setFont(font);
    scoreMultiplicatorLabel.setCharacterSize(GameStyle::inGameFontSize);
    scoreMultiplicatorLabel.setFillColor(GameStyle::gameFontColor);
    scoreMultiplicatorLabel.setPosition(window->getSize().x - 265, window->getSize().y - 700);

    //Le score courant:
    currentScoreLabel.setFont(font);
    currentScoreLabel.setCharacterSize(GameStyle::inGameFontSize);
    currentScoreLabel.setFillColor(GameStyle::gameFontColor);
    currentScoreLabel.setPosition(window->getSize().x - 265, window->getSize().y - 700 + LBL_SPACEMENT);

    //Le prochain ennemi � appara�tre:
    nextEnemyLabel.setFont(font);
    nextEnemyLabel.setCharacterSize(GameStyle::inGameFontSize);
    nextEnemyLabel.setFillColor(GameStyle::gameFontColor);
    nextEnemyLabel.setPosition(window->getSize().x - 265, window->getSize().y - 700 + LBL_SPACEMENT * 2);

    //Le nombre de points de vie du joueur
    lifesLabel.setFont(font);
    lifesLabel.setCharacterSize(GameStyle::inGameFontSize);
    lifesLabel.setFillColor(GameStyle::gameRedColor);
    lifesLabel.setPosition(10, window->getSize().y - 700);

    //Le nombre de points de vie du shield courant du joueur
    shieldLabel.setFont(font);
    shieldLabel.setCharacterSize(GameStyle::inGameFontSize);
    shieldLabel.setFillColor(GameStyle::gameRedColor);
    shieldLabel.setPosition(10, window->getSize().y - 700 + LBL_SPACEMENT);

    //L'arme courante du joueur
    curWeaponLabel.setFont(font);
    curWeaponLabel.setCharacterSize(GameStyle::inGameFontSize);
    curWeaponLabel.setFillColor(GameStyle::gameRedColor);
    curWeaponLabel.setPosition(10, window->getSize().y - 700 + LBL_SPACEMENT * 2);

    //Le nombre du munitions de l'arme du joueur
    munitionsLabel.setFont(font);
    munitionsLabel.setCharacterSize(GameStyle::inGameFontSize);
    munitionsLabel.setFillColor(GameStyle::gameRedColor);
    munitionsLabel.setPosition(10, window->getSize().y - 700 + LBL_SPACEMENT * 3);
    // </smasson>
#pragma endregion
    //ambianceMusic.setLoop(true);
    //ambianceMusic.setVolume(100);
    //ambianceMusic.play();

    //Initialisation des projectiles
#pragma region:ProjectileInit
    for (int i = 0; i < NB_BASIC_PROJECTILES; ++i)
    {
        basicProjectiles.push_back(ProjectileGenerator::GetProjectile(Projectile::ProjectileType::BASIC));
    }

#pragma endregion

    //Initialisation du random time
    srand(time(NULL));

    //<smasson>
    //Position initiale du joueur
    player->SetPosition(window->getSize().x / 2, window->getSize().y / 2);
    player->SetLimits(Vector2f(Background::LeftLimit(), 350),
        Vector2f(Background::RightLimit(), Background::WinHeight()));
    //</smasson>
    this->mainWin = window;
    isRunning = true;

    return true;
}

void GameScene::getInputs()
{
    while (mainWin->pollEvent(event))
    {
        //x sur la fen�tre
        if (event.type == Event::Closed)
        {
            //Attention, ici simplement fermer la fen�tre ne mettrait pas n�cessairement 
            //fin � l'application
            isRunning = false;
            transitionVersScene = Scene::scenes::EXIT;
        }

        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                isRunning = false;
                transitionVersScene = Scene::scenes::MAIN_MENU;
            }
        }
    }

    interfaceCommande = 0;
    //<smasson>
    //M�thode binaire: appuyer � gauche et � droite sumultan�ment va donner 3, et le personnage ne se d�palcera alors pas.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        interfaceCommande |= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        interfaceCommande |= 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        interfaceCommande |= 4;
        background.SetSpeed(4);
    }
    else
    {
        background.SetSpeed(2);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        interfaceCommande |= 8;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        interfaceCommande |= 16;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        interfaceCommande |= 32;
    }
    if (sf::Mouse::isButtonPressed(Mouse::Left))
    {
        //�n�nement direct de tirs du joueur
        //Si le joueur peut tirer
        if (player->CanShoot())
        {
            //Tirer
            player->Shoot();
            //Ajouter le projectile au jeu
            for (Projectile* curProj : basicProjectiles)
            {
                //Si le projectile est inactif
                if (!curProj->IsEnable())
                {
                    curProj->Start(player->GetDirection(), player->GetShape().getPosition());
                    //On break, car nous avons trouv� notre projectile
                    break;
                }
            }
        }
    }
    //</smasson>
}

void GameScene::update()
{
    //Updater le background
    background.Update(*mainWin);

    //Updater les projectiles
#pragma region:ProjectilesUpdate
    //Projectiles basiques
    for (Projectile* curProj : basicProjectiles)
    {
        //Si le projectile courant est actif, alors
        if (curProj->IsEnable())
        {
            //Updater ce projectile
            curProj->Update();
            //Si le projectile sort des limites de l'�cran
            if (GlobalMath::IsOutOfScreen(curProj->GetPosition()))
            {
                //Rendre le projectile disable
                curProj->SetEnable(false);
                cout << "Sortie d'un projectile." << endl;
            }
        }
    }
#pragma endregion
    //

    //Update du joueur
    player->Update(interfaceCommande);

    //Updater le HUD
    UpdateHUD();

    enem.Update(Vector2f(0, 0));
    enem2.Update(Vector2f(0, 0));
    enem3.Update(Vector2f(0, 0));
}

void GameScene::draw()
{
    //Toujours important d'effacer l'�cran pr�c�dent
    mainWin->clear();
    //Dessiner background
    background.Draw(*mainWin);
    //Dessiner contenu
    //Dessiner les projectiles
    //Projectiles basiques
    for (Projectile* curProj : basicProjectiles)
    {
        //Si le projectile est actif
        if (curProj->IsEnable())
        {
            //Dessiner le projectile
            curProj->Draw(*mainWin);
        }
    }
    //Dessiner les personnages
    enem.Draw(*mainWin);
    enem2.Draw(*mainWin);
    enem3.Draw(*mainWin);
    //Le joueur
    player->Draw(*mainWin);
    //<smasson>
    //Dessiner le HUD
    mainWin->draw(scoreMultiplicatorLabel);
    mainWin->draw(currentScoreLabel);
    mainWin->draw(lifesLabel);
    mainWin->draw(shieldLabel);
    mainWin->draw(curWeaponLabel);
    mainWin->draw(munitionsLabel);
    mainWin->draw(nextEnemyLabel);
    //</smasson>
    //Afficher la nouvelle �cran
    mainWin->display();
}

void GameScene::Notify(Subject * subject)
{
}

void spaceShooter::GameScene::UpdateHUD()
{
    //<smasson>
    scoreMultiplicatorLabel.setString("Score Bonus: \n" + std::to_string(default));
    currentScoreLabel.setString("Score: \n" + std::to_string(default));
    //Le nombre de points de vie restants
    int playerHealthPoints;
    lifesLabel.setString("Health Points: \n" + std::to_string(default));
    shieldLabel.setString("Shield Lifes: \n" + std::to_string(default));
    //L'arme courante du joueur
    string curWepName = "";
    switch (player->GetWeaponType())
    {
    case Weapon::BASIC_WEAPON:
        curWepName = "Lazers";
        break;
    default:
        curWepName = "default";
        break;
    }
    curWeaponLabel.setString("Weapon: \n" + curWepName);

    //Le nombre de munitions du joueur
    string munitions = "Unlimited";
    if (player->GetWeaponType() != Weapon::WeaponType::BASIC_WEAPON)
        munitions = std::to_string(player->GetNbMunitions());
    munitionsLabel.setString("Shoots Left: \n" + munitions);
    nextEnemyLabel.setString("Next Enemy: \n" + std::to_string(default));
    //</smasson>
}
