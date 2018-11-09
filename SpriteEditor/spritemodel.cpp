#include "spritemodel.h"
#include <QDebug>

SpriteModel::SpriteModel()
{
    framesMade = 0;

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
    Frame* newFrame = new Frame;
    frames.push_back(newFrame);

    // Adding a frame switches focus to that new frame
    currentFrameIndex = int(frames.size() - 1);
    framesMade++;

    emit frameAdded(framesMade);
    emit currentFrameUpdated(newFrame);
}

void SpriteModel::removeFrame(int selectedIndex)
{
    // Adjust index since we have to add this to the begin() iterator
    if(selectedIndex != 0)
    {
        selectedIndex = selectedIndex - 1;
    }
    //images.removeAt(selectedIndex);
    frames.erase(frames.begin() + selectedIndex);

    emit frameRemoved();
}

void SpriteModel::setCurrentFrameIndex(int selectedIndex)
{
    currentFrameIndex = selectedIndex;
    Frame* current = frames.at(currentFrameIndex);
    emit currentFrameUpdated(current);
}
