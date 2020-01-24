#ifndef INPUTCONTROLLER_H_INCLUDED
#define INPUTCONTROLLER_H_INCLUDED

#include "cocos2d.h"
#include "KeyManager.h"

class InputController {
public:
    virtual ~InputController() { }
    InputController();

    virtual bool onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);

    virtual bool onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    virtual void onMousePressed(cocos2d::EventMouse* event);
    virtual void onMouseReleased(cocos2d::EventMouse* event);
    virtual void onMouseMoved(cocos2d::EventMouse* event) { }

    virtual void update(float delta) { }
    //std::vector<shared_ptr<Command>> update(float delta);

protected:
    KeyManager _keyManager;
private:
    cocos2d::Node* _parent;
    //World* _gameWorld;
};

#include "World.h"

class World;

class InputControllerImpl: public InputController {
public:
    virtual ~InputControllerImpl() { }

    void setWorld(World* world);

    virtual bool onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);

    virtual void onMouseReleased(cocos2d::EventMouse* event);

    virtual void update(float delta);
    //std::vector<shared_ptr<Command>> update(float delta);

private:
    World* _gameWorld;
};

#endif // INPUTCONTROLLER_H_INCLUDED
