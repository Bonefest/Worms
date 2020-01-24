#include "WorldGenerator.h"

void WorldGenerator::addPhysicsToPixel(Pixel* pixel) {
    cocos2d::Size pixelSize = pixel->getPixelSize();
    cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createBox(pixelSize,
                                                                 cocos2d::PhysicsMaterial(1.0f, 0.0f, 1.0f),
                                                                 cocos2d::Vec2(pixelSize * 0.5f));


    pixel->addComponent(body);
}

FlatGenerator::FlatGenerator(cocos2d::Node* parent,
                             int width,
                             int height,
                             const cocos2d::Size& size,
                             const cocos2d::Color4F& gradient): _parent(parent),
                                                                _width(width),
                                                                _height(height),
                                                                _pixelSize(size),
                                                                _startGradient(cocos2d::Color4F::BLACK),
                                                                _endGradient(gradient) { }



void FlatGenerator::generateWorld(std::vector<Pixel*>& pixelContainer, bool addPhysics) {
    for(int y = 0; y < _height; ++y) {
        for(int x = 0; x < _width; ++x) {
            float t = float(x) / _width;
            cocos2d::Color4F pixColor(cocos2d::MathUtil::lerp(_startGradient.r, _endGradient.r, t),
                                      cocos2d::MathUtil::lerp(_startGradient.g, _endGradient.g, t),
                                      cocos2d::MathUtil::lerp(_startGradient.b, _endGradient.b, t),
                                      1.0f);

            Pixel* pixel = Pixel::createPixel(_pixelSize, pixColor);
            if(addPhysics) {
                addPhysicsToPixel(pixel);
                pixel->getPhysicsBody()->setDynamic(false);
            }
            pixel->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
            pixel->setPosition(cocos2d::Vec2( (x + 1) * (_pixelSize.width - 1), (y + 1) * _pixelSize.height));

            pixelContainer.push_back(pixel);
            _parent->addChild(pixel);
        }
    }
}
