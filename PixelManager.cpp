#include "PixelManager.h"

PixelDrawer* PixelDrawer::createPixelDrawer() {
    return PixelDrawer::create();
}

bool PixelDrawer::init() {
    if(!cocos2d::DrawNode::init()) return false;

    return true;
}

void PixelDrawer::drawPixels(const std::vector<Pixel*> pixels) {
    clear();
    if(pixels.size() == 0) return;

    cocos2d::Vec2 pixelVecSize = cocos2d::Vec2(pixels.front()->getPixelSize());
    for(const Pixel* pixel : pixels) {
        drawSolidRect(pixel->getPosition(),
                      pixel->getPosition() + pixelVecSize,
                      pixel->getPixelColor());
    }
}
