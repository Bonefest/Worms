#include "Pixel.h"

bool Pixel::init() {
    if(!cocos2d::Node::init()) return false;

    return true;
}

Pixel* Pixel::createPixel(const cocos2d::Size& size, const cocos2d::Color4F& color) {
    Pixel* pixel = Pixel::create();

    pixel->setPixelSize(size);
    pixel->setPixelColor(color);

    return pixel;
}


void Pixel::setPixelSize(const cocos2d::Size& size) {
    _pixelSize = size;
}

const cocos2d::Size& Pixel::getPixelSize() const {
    return _pixelSize;
}

void Pixel::setPixelColor(const cocos2d::Color4F& color) {
    _pixelColor = color;
}

const cocos2d::Color4F& Pixel::getPixelColor() const {
    return _pixelColor;
}
