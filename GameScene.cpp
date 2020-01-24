#include "GameScene.h"

GameScene* GameScene::createScene() {
    return GameScene::create();
}

bool GameScene::init() {
    if(!GameScene::initWithPhysics()) return false;

    _world = World::createWorld();
    addChild(_world);

    getPhysicsWorld()->setDebugDrawMask(0xffff);
    getPhysicsWorld()->setFixedUpdateRate(180);
    return true;
}
