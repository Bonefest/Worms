#include "InputController.h"

InputController::InputController(): _parent(nullptr) { }

bool InputController::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event) {
    _keyManager.setKey(key);
}

void InputController::onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event) {
    _keyManager.removeKey(key);
}

bool InputController::onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event) {
    return true;
}

void InputController::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {

}

void InputController::onMousePressed(cocos2d::EventMouse* event) {
    _keyManager.setMousebutton(event->getMouseButton());
}


void InputController::onMouseReleased(cocos2d::EventMouse* event) {
    _keyManager.removeMouseButton(event->getMouseButton());
}



void InputControllerImpl::setWorld(World* world) {
    _gameWorld = world;
}

bool InputControllerImpl::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event) {
    InputController::onKeyPressed(key, event);
//    if(key == cocos2d::EventKeyboard::KeyCode::KEY_D) {
//        cocos2d::PhysicsBody* playerBody = _gameWorld->getPlayer()->getPhysicsBody();
//        playerBody->setVelocity(playerBody->getVelocity() + cocos2d::Vec2(100.0f, 0.0f));
//    } else if(key == cocos2d::EventKeyboard::KeyCode::KEY_A) {
//        cocos2d::PhysicsBody* playerBody = _gameWorld->getPlayer()->getPhysicsBody();
//        playerBody->setVelocity(playerBody->getVelocity() + cocos2d::Vec2(-100.0f, 0.0f));
//    }
}

void InputControllerImpl::onKeyReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event) {
    InputController::onKeyReleased(key, event);
//    if(key == cocos2d::EventKeyboard::KeyCode::KEY_D || key == cocos2d::EventKeyboard::KeyCode::KEY_A) {
//        cocos2d::PhysicsBody* playerBody = _gameWorld->getPlayer()->getPhysicsBody();
//        playerBody->setVelocity(cocos2d::Vec2(0.0f, playerBody->getVelocity().y));
//    }
}

void InputControllerImpl::onMouseReleased(cocos2d::EventMouse* event) {
    double pressedTime = _keyManager.getPressedMouseTime(event->getMouseButton()) / 1000.0f;

    cocos2d::PhysicsBody* bulletBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(4, 4),
                                                                       cocos2d::PhysicsMaterial(10.0f, 0.0f, 0.0f));

    cocos2d::Sprite* bullet = cocos2d::Sprite::create("HelloWorld.png");
    bullet->setContentSize(cocos2d::Size(4, 4));
    bullet->addComponent(bulletBody);

    bullet->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    bullet->setPosition(_gameWorld->getPlayer()->getTowerEnd());

    float k = std::min(100.0f * pressedTime, 1000.0);

    bulletBody->setVelocity(k * _gameWorld->getPlayer()->getTowerDirection());
    _gameWorld->addChild(bullet);

    _gameWorld->getPlayer()->getPhysicsBody()->setVelocity(0.5 * -k * _gameWorld->getPlayer()->getTowerDirection());


    InputController::onMouseReleased(event);
}


void InputControllerImpl::update(float delta) {
    if(_keyManager.isKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_W)) {
        Player* player = _gameWorld->getPlayer();
        cocos2d::log("%f", player->getTowerAngle());
        player->setTowerAngle(std::max(-180.0f, player->getTowerAngle() - 1.0f));
    } else if(_keyManager.isKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_S)) {
        Player* player = _gameWorld->getPlayer();
        cocos2d::log("%f", player->getTowerAngle());
        player->setTowerAngle(std::min(0.0f, player->getTowerAngle() + 1.0f));
    }

    if(_keyManager.isKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_A)) {
        Player* player = _gameWorld->getPlayer();
        player->getPhysicsBody()->setVelocity(player->getPhysicsBody()->getVelocity() - cocos2d::Vec2(2.0f, 0.0f));
    }
    if(_keyManager.isKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_D)) {
        Player* player = _gameWorld->getPlayer();
        player->getPhysicsBody()->setVelocity(player->getPhysicsBody()->getVelocity() + cocos2d::Vec2(2.0f, 0.0f));
    }
}
