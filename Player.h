#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "cocos2d.h"

class Player: public cocos2d::Sprite {
public:
    CREATE_FUNC(Player);
    static Player* createPlayer();
    bool init();

    void setTowerAngle(float angle);
    float getTowerAngle() const;

    cocos2d::Vec2 getTowerEnd() const;
    cocos2d::Vec2 getTowerDirection() const;
private:
    bool initTower();

    cocos2d::Sprite* _tower;    //Сделать возможность оторвать башню
};

#endif // PLAYER_H_INCLUDED
