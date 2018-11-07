#ifndef SPRITEMODEL_H
#define SPRITEMODEL_H

#include <vector>
#include "frame.h"

class SpriteModel
{

private:
    std::vector<frame> frames;
    int currentFrameIndex;
    int frameRate;

public:
    SpriteModel();
    void changeResolution(int res);
};

#endif // SPRITEMODEL_H
