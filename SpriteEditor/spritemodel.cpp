#include "spritemodel.h"

SpriteModel::SpriteModel()
{

}

SpriteModel::~SpriteModel()
{

}

void SpriteModel::changeResolution(int res)
{
    res++;
}

void SpriteModel::addFrame()
{
    // Add a new blank frame to our list and switch focus to it
    Frame newFrame;
    frames.push_back(newFrame);
    int frameCount = int(frames.size());

    currentFrameIndex = frameCount - 1;

    emit frameChanged(frameCount);
}

void SpriteModel::removeFrame(int selectedIndex)
{
    int frameCount = int(frames.size());

    // Adjust index since we have to add this to the begin() iterator
    selectedIndex = selectedIndex - 1;
    frames.erase(frames.begin() + selectedIndex);

    emit frameChanged(frameCount);
}

void SpriteModel::setCurrentFrameIndex(int selectedIndex)
{
    currentFrameIndex = selectedIndex;
}
