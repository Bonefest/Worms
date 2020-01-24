#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "cocos2d.h"
#include "Player.h"
#include "Pixel.h"
#include "PixelManager.h"
#include "InputController.h"

class InputControllerImpl;

class World : public cocos2d::Node {
public:
    CREATE_FUNC(World);
    virtual ~World();
    static World* createWorld();
    bool init();
    void update(float delta);

    Player* getPlayer();
private:
    bool initInputController();
    bool initEventListeners();
    bool initWorldBox();
    bool initPixelManager();
    bool initPlayers();
    void initGameWorld();

    cocos2d::Size _visibleSize;

    InputControllerImpl* _inputController;
    PixelDrawer* _pixelDrawer;
    Player* _player;

    std::vector<Pixel*> _pixels;

};

#endif // WORLD_H_INCLUDED
