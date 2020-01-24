#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

#include "cocos2d.h"

class Pixel : public cocos2d::Node {
public:
    CREATE_FUNC(Pixel);
    static Pixel* createPixel(const cocos2d::Size& pixelSize, const cocos2d::Color4F& color);
    bool init();

    void setPixelSize(const cocos2d::Size& size);
    const cocos2d::Size& getPixelSize() const;

    void setPixelColor(const cocos2d::Color4F& color);
    const cocos2d::Color4F& getPixelColor() const;

private:

    cocos2d::Size _pixelSize;
    cocos2d::Color4F _pixelColor;
};

#endif // PIXEL_H_INCLUDED
