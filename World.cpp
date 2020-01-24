#include "World.h"
#include "WorldGenerator.h"

World::~World() {
    delete _inputController;
}

World* World::createWorld() {
    return World::create();
}

bool World::init() {
    if(!cocos2d::Node::init()) return false;

    _visibleSize = cocos2d::Director::getInstance()->getVisibleSize();


    if(!initInputController()) return false;
    if(!initEventListeners()) return false;
    if(!initWorldBox()) return false;
    if(!initPixelManager()) return false;
    if(!initPlayers()) return false;


    initGameWorld();

    scheduleUpdate();
    return true;
}

bool World::initInputController() {
    _inputController = new InputControllerImpl;
    if(_inputController == nullptr) return false;

    _inputController->setWorld(this);

    return true;
}

bool World::initEventListeners() {
    cocos2d::EventListenerKeyboard* klistener = cocos2d::EventListenerKeyboard::create();
    if(klistener == nullptr) return false;

    klistener->onKeyPressed = CC_CALLBACK_2(InputControllerImpl::onKeyPressed, _inputController);
    klistener->onKeyReleased = CC_CALLBACK_2(InputControllerImpl::onKeyReleased, _inputController);

    cocos2d::EventListenerMouse* mlistener = cocos2d::EventListenerMouse::create();
    if(mlistener == nullptr) return false;

    mlistener->onMouseDown = CC_CALLBACK_1(InputControllerImpl::onMousePressed, _inputController);
    mlistener->onMouseUp = CC_CALLBACK_1(InputControllerImpl::onMouseReleased, _inputController);
    mlistener->onMouseMove = CC_CALLBACK_1(InputControllerImpl::onMouseMoved, _inputController);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(klistener, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mlistener, this);
    return true;
}

bool World::initWorldBox() {
    cocos2d::PhysicsBody* worldBoxBody = cocos2d::PhysicsBody::createEdgeBox(_visibleSize,
                                                                             cocos2d::PhysicsMaterial(1.0f, 0.0f, 0.0f),
                                                                             0.01f);
    if(worldBoxBody == nullptr) return false;

    worldBoxBody->setDynamic(false);
    worldBoxBody->setGravityEnable(false);

    cocos2d::Node* worldBox = cocos2d::Node::create();

    if(worldBox == nullptr) return false;

    worldBox->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
    worldBox->setPosition(_visibleSize * 0.5f);

    worldBox->addComponent(worldBoxBody);

    addChild(worldBox);

    return true;
}

bool World::initPixelManager() {
    _pixelDrawer = PixelDrawer::createPixelDrawer();
    if(_pixelDrawer == nullptr) return false;

    addChild(_pixelDrawer);

    return true;
}

bool World::initPlayers() {
    _player = Player::createPlayer();
    if(_player == nullptr) return false;
    _player->setPosition(cocos2d::Vec2(240, 200));
    addChild(_player);
    return true;
}


void World::initGameWorld() {
    FlatGenerator generator(this, 24, 8, cocos2d::Size(16, 16), cocos2d::Color4F(0.5f, 0.5f, 0.5f, 1.0f));
    generator.generateWorld(_pixels, true);
}

void World::update(float delta) {
    _inputController->update(delta);
    _pixelDrawer->drawPixels(_pixels);
}

Player* World::getPlayer() {
    return _player;
}
