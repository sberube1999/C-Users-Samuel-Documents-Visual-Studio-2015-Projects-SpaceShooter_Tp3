#include "GameScene.h"
#include "GameStyle.h"

using namespace spaceShooter;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
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
    currentScoreLabel.setPosition(window->getSize().x - 265, window->getSize().y -700 + LBL_SPACEMENT);

    //Le prochain ennemi à apparaître:
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
    shieldLabel.setPosition(10, window->getSize().y -700 + LBL_SPACEMENT);

    //L'arme courante du joueur
    curWeaponLabel.setFont(font);
    curWeaponLabel.setCharacterSize(GameStyle::inGameFontSize);
    curWeaponLabel.setFillColor(GameStyle::gameRedColor);
    curWeaponLabel.setPosition(10, window->getSize().y -700 + LBL_SPACEMENT * 2);

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

    //Initialisation du random time
    srand(time(NULL));

    // </smasson>
    this->mainWin = window;
    isRunning = true;

    return true;
}

void GameScene::getInputs()
{
    while (mainWin->pollEvent(event))
    {
        //x sur la fenêtre
        if (event.type == Event::Closed)
        {
            //Attention, ici simplement fermer la fenêtre ne mettrait pas nécessairement 
            //fin à l'application
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
    //Méthode binaire: appuyer à gauche et à droite sumultanément va donner 3, et le personnage ne se dépalcera alors pas.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        interfaceCommande |= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        interfaceCommande |= 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        interfaceCommande |= 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        interfaceCommande |= 6;
    }
    //</smasson>
}

void GameScene::update()
{
    //Updater le background
    background.Update(*mainWin);

    //Updater le HUD
    UpdateHUD();
}

void GameScene::draw()
{
    //Toujours important d'effacer l'écran précédent
    mainWin->clear();
    //Dessiner background
    background.Draw(*mainWin);
    //Dessiner contenu

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
    //Afficher la nouvelle écran
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
    lifesLabel.setString("Health Points: \n" + std::to_string(default));
    shieldLabel.setString("Shield Lifes: \n" + std::to_string(default));
    curWeaponLabel.setString("Weapon: \n" + std::to_string(default));
    munitionsLabel.setString("Shoots Left: \n" + std::to_string(default));
    nextEnemyLabel.setString("Next Enemy: \n" + std::to_string(default));
    //</smasson>
}
