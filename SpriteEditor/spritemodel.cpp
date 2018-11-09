#include "spritemodel.h"
#include <QDebug>

SpriteModel::SpriteModel()
{
    framesMade = 1;
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
    //add image
    QImage image;
    image= QImage(GRID_RESOLUTION, GRID_RESOLUTION, QImage::Format_RGB32);
    image.fill(qRgba(160 , 160, 160, 10));

    Frame newFrame;
    frames.push_back(newFrame);
    images.append(image);
    framesMade++;

    emit frameAdded(framesMade);

}

void SpriteModel::removeFrame(int selectedIndex)
{
    // Adjust index since we have to add this to the begin() iterator
    selectedIndex = selectedIndex - 1;
    images.removeAt(selectedIndex);

    emit frameRemoved();

}

void SpriteModel::setCurrentFrameIndex(int selectedIndex)
{
    currentFrameIndex = selectedIndex;

    // Adjust index since we have to add this to the begin() iterator
    selectedIndex = selectedIndex - 1;
    frames.erase(frames.begin() + selectedIndex);

    emit frameChanged(framesMade);
}

void SpriteModel::setCurrentFrameIndex(int selectedIndex)
{
    currentFrameIndex = selectedIndex;
}
