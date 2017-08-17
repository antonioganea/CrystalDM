#ifndef EMERALDO_H
#define EMERALDO_H

#include "Crystal.h"
#include <SFML/Graphics/Sprite.hpp>
#include "EmeraldoShard.h"

class Emeraldo : public Crystal{
    public:
        Emeraldo();
        //virtual ~Emeraldo();
        void draw();
        void update( float dt );

        bool isDead();

        void input( const sf::Event & event );

        sf::Vector2f getPosition();

        void move();
        void attack();
        void ultimate();

    protected:
    private:
        EmeraldoShard * dispersionParticles;
        void disperse();
        sf::Sprite sprite;
        sf::Vector2f velocity;
        int w,a,s,d;
        bool inDispersion;
        bool visible;
        int cooldown;
        int animationTimer;
        int dispersionParticleNo = 0;
};

#endif // EMERALDO_H
