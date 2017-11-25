#include "GameScene.h"

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
    // </smasson>

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
    background.Update(*mainWin);
}

void GameScene::draw()
{
    //Toujours important d'effacer l'écran précédent
    mainWin->clear();
    //Dessiner background
    background.Draw(*mainWin);
    //Dessiner contenu

    //Afficher la nouvelle écran
    mainWin->display();
}

void spaceShooter::GameScene::Notify(Subject * subject)
{
}
