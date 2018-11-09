#include "spritemodel.h"
#include <QDebug>
#include <iostream>

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

void SpriteModel::addNewFrameFromButton()
{

    //add image
    QImage image;
    image= QImage(960,960,QImage::Format_RGB32);

    image.fill(qRgba(160 , 160, 160, 10));
    images.append(image);
    int frameCount = int(images.size());
    currentFrameIndex = frameCount - 1;
    emit frameChanged(frameCount);

}

void SpriteModel::addFrame(Frame* frame)
{
    std::cout << "frame added" << std::endl;
    frames.push_back(frame);

}

void SpriteModel::removeFrame(int selectedIndex)
{
    int frameCount = int(images.size());

    // Adjust index since we have to add this to the begin() iterator
    selectedIndex = selectedIndex - 1;
    images.removeAt(selectedIndex);
    emit frameChanged(frameCount);

}

void SpriteModel::setCurrentFrameIndex(int selectedIndex)
{

    currentFrameIndex = selectedIndex;

}

void SpriteModel::changeResolutionOfAllFrames(int value)
{
    std::cout << "frames.size() = " << frames.size() << std::endl;

    int newPixelSize;

    if (value == 0)
        newPixelSize = 200;
    else if (value == 1)
        newPixelSize = 100;
    else if (value == 2)
        newPixelSize = 50;
    else
        newPixelSize = 25;

    for (unsigned long i = 0; i < frames.size(); i++)
    {
        frames[i]->changeResolution(newPixelSize);
        std::cout << "telling frame " << i << " to update res" << std::endl;
    }
}
