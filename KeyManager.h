#ifndef KEYMANAGER_H_INCLUDED
#define KEYMANAGER_H_INCLUDED

#include "cocos2d.h"

#include <map>
#include <chrono>

class KeyManager {
public:
    void setMousebutton(cocos2d::EventMouse::MouseButton button);
    void removeMouseButton(cocos2d::EventMouse::MouseButton button);

    void setKey(cocos2d::EventKeyboard::KeyCode key);
    void removeKey(cocos2d::EventKeyboard::KeyCode key);

    bool isMousebuttonPressed(cocos2d::EventMouse::MouseButton button) const;
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode key) const;

    double getPressedKeyTime(cocos2d::EventKeyboard::KeyCode key);
    double getPressedMouseTime(cocos2d::EventMouse::MouseButton button);

private:
    double getElapsedTimeFor(std::chrono::system_clock::time_point);

    std::map<cocos2d::EventKeyboard::KeyCode,std::chrono::system_clock::time_point> pressedKeys;
    std::map<cocos2d::EventMouse::MouseButton,std::chrono::system_clock::time_point> pressedMousebuttons;
};

#endif // KEYMANAGER_H_INCLUDED
