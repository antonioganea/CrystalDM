#include <SFML/Graphics.hpp>

#include "Display.h"
#include "GameRegistry.h"
#include "StageManager.h"

#include "SyncManager.h"
#include "Config.h"

#include "Emeraldo.h"
#include "Rubie.h"
#include "Sapheer.h"
#include "Particle.h"

#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    GameRegistry::init();
    Display::init();
    StageManager::init();

    Stage * stage = StageManager::getStage();

    //Emeraldo * champion = new Emeraldo();
    //Rubie * champion = new Rubie();
    //Sapheer * champion = new Sapheer();

    //champion->setSyncable(true);
    //stage->addEntity(champion);

    //SyncManager::myCrystal = champion;

    SyncManager::init();
    //SyncManager::connectToServer( sf::IpAddress(127,0,0,1) );

    sf::View view;

    view.setSize( WINDOW_WIDTH, WINDOW_HEIGHT );

    while (Display::window->isOpen()){

        StageManager::updateCurrentStage();

        sf::Event event;
        while (Display::window->pollEvent(event)){

            if (event.type == sf::Event::Closed)
                Display::window->close();
            if (event.type == sf::Event::KeyPressed ){
                if ( event.key.code == sf::Keyboard::Escape )
                    Display::window->close();
            }
            StageManager::input(event);
            //champion->input(event);
        }

        SyncManager::receivePackets();
        StageManager::update(10.f);

        //Display::focusOn(champion);

        Display::window->clear();
        StageManager::draw();
        Display::window->display();
    }

    return 0;
}
