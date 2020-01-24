#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include "cocos2d.h"
#include "World.h"

#include <vector>

class GameScene : public cocos2d::Scene {
public:
    CREATE_FUNC(GameScene);
    static GameScene* createScene();
    bool init();

private:
    World* _world;
};

#endif // GAMESCENE_H_INCLUDED
