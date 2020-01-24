#include "KeyManager.h"

void KeyManager::setMousebutton(cocos2d::EventMouse::MouseButton button) {
    if(!isMousebuttonPressed(button)) {
        pressedMousebuttons[button] = std::chrono::system_clock::now();
    }
}

void KeyManager::removeMouseButton(cocos2d::EventMouse::MouseButton button) {
    pressedMousebuttons.erase(button);
}

double KeyManager::getPressedMouseTime(cocos2d::EventMouse::MouseButton button) {
    if(isMousebuttonPressed(button)) {
        return getElapsedTimeFor(pressedMousebuttons[button]);
    }
    return 0.0;
}

void KeyManager::setKey(cocos2d::EventKeyboard::KeyCode key) {
    if(!isKeyPressed(key)) {
        pressedKeys[key] = std::chrono::system_clock::now();
    }
}

void KeyManager::removeKey(cocos2d::EventKeyboard::KeyCode key) {
    pressedKeys.erase(key);
}

double KeyManager::getPressedKeyTime(cocos2d::EventKeyboard::KeyCode key) {
    if(isKeyPressed(key)) {
        return getElapsedTimeFor(pressedKeys[key]);
    }
    return 0.0;
}

bool KeyManager::isMousebuttonPressed(cocos2d::EventMouse::MouseButton button) const {
    return (pressedMousebuttons.find(button) != pressedMousebuttons.end());
}

bool KeyManager::isKeyPressed(cocos2d::EventKeyboard::KeyCode key) const {
    return (pressedKeys.find(key) != pressedKeys.end());
}

double KeyManager::getElapsedTimeFor(std::chrono::system_clock::time_point time) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - time).count();
}
