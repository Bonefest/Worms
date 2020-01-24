#include "Player.h"
#include "MiscMath.h"

Player* Player::createPlayer() {
    return Player::create();
}

bool Player::init() {
    if(!cocos2d::Sprite::initWithFile("vehicle.png")) return false;

    setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);

    if(!initTower()) return false;

    cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createBox(getContentSize(),
                                                                 cocos2d::PhysicsMaterial(1000.0f, 0.0f, 1.0f));
    body->setAngularVelocityLimit(0.0f);
    body->setVelocityLimit(100.0f);
    addComponent(body);

    return true;
}


bool Player::initTower() {
    _tower = cocos2d::Sprite::create("tower.png");
    _tower->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    _tower->setPosition(cocos2d::Vec2(getContentSize().width * 0.5f, getContentSize().height * 0.7f));
    addChild(_tower);

    return true;
}

void Player::setTowerAngle(float angle) {
    _tower->setRotation(angle);
}

float Player::getTowerAngle() const {
    _tower->getRotation();
}

cocos2d::Vec2 Player::getTowerEnd() const {
    cocos2d::Size towerSize = _tower->getContentSize();
    float towerAngle = getTowerAngle();
    return getPosition() +
           _tower->getPosition() +
           cocos2d::Vec2( (towerSize.width + towerSize.height) * std::cos(toRad(-towerAngle)),
                          (towerSize.width + towerSize.height) * std::sin(toRad(-towerAngle)));

}

cocos2d::Vec2 Player::getTowerDirection() const {
    return cocos2d::Vec2(std::cos(toRad(-getTowerAngle())), std::sin(toRad(-getTowerAngle())));
}
