#ifndef WORLDGENERATOR_H_INCLUDED
#define WORLDGENERATOR_H_INCLUDED

#include <vector>
#include "Pixel.h"
class WorldGenerator {
public:
    virtual void generateWorld(std::vector<Pixel*>& pixelContainer, bool addPhysics) = 0;

protected:
    void addPhysicsToPixel(Pixel* pixel);
};


#include "cocos2d.h"
class FlatGenerator: public WorldGenerator {
public:
    FlatGenerator(cocos2d::Node* parent,
                  int width,
                  int height,
                  const cocos2d::Size& pixelSize,
                  const cocos2d::Color4F& gradient);
    virtual void generateWorld(std::vector<Pixel*>& pixelContainer, bool addPhysics);
private:
    cocos2d::Node* _parent;

    int _width;
    int _height;
    cocos2d::Size _pixelSize;
    cocos2d::Color4F _startGradient;
    cocos2d::Color4F _endGradient;
};

class MiddleDisplacementGenerator: public WorldGenerator {
public:
    MiddleDisplacementGenerator(cocos2d::Node* parent,
                                int maxWidth,
                                int maxHeight,
                                const cocos2d::Vec2& gradient);
};

//ImageGenerator

#endif // WORLDGENERATOR_H_INCLUDED
