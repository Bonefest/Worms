#ifndef _PIXELDRAWER_H_
#define _PIXELDRAWER_H_

#include "cocos2d.h"
#include "Pixel.h"

#include <vector>

class PixelDrawer : public cocos2d::DrawNode {
public:
    CREATE_FUNC(PixelDrawer);
    static PixelDrawer* createPixelDrawer();
    bool init();


    void drawPixels(const std::vector<Pixel*> pixels);
};

#endif // _PIXELDRAWER_H_
