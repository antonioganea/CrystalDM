#include <SFML/Graphics.hpp>

#include "Display.h"
#include "GameRegistry.h"
#include "StageManager.h"

#include "Emeraldo.h"

int main()
{
    GameRegistry::queueResource("emeraldo.png",ResourceType::Texture);
    GameRegistry::loadResource();

    sf::Texture * tex;
    tex = GameRegistry::getResource("emeraldo.png",ResourceType::Texture).texture;

    sf::Sprite spr;
    spr.setTexture(*tex,true);

    Display::init();

    StageManager::init();

    Stage * stage = StageManager::getStage();

    Emeraldo * emeraldo = new Emeraldo();

    stage->addEntity(emeraldo);

    while (Display::window->isOpen())
    {
        sf::Event event;
        while (Display::window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Display::window->close();
        }

        Display::window->clear();
        StageManager::input();
        StageManager::update(1);
        StageManager::draw();
        Display::window->display();
    }

    return 0;
}
