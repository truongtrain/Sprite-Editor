#include "spritemodel.h"
#include <QDebug>
#include <iostream>

SpriteModel::SpriteModel()
{
    framesMade = 0;
}

SpriteModel::~SpriteModel()
{
   for(int i = 0; i < frames.size(); i++)
   {
       delete frames[i];
   }
   frames.clear();
}

void SpriteModel::addFrame()
{
   // Frame newFrame;
    frames.push_back(new Frame);

    // Adding a frame switches focus to that new frame
    framesMade++;

    emit frameAdded(framesMade);
}

void SpriteModel::removeFrame(int removedIndex, int newIndex)
{
    delete frames[removedIndex];
    frames.removeAt(removedIndex);
    setCurrentFrame(newIndex);
}

void SpriteModel::duplicateFrame(int index)
{
    Frame* original = frames[index];
    Frame* copy = new Frame(*original);

    int newIndex = index + 1;
    frames.insert(newIndex, copy);

    framesMade++;

    emit frameDuplicated();
}

void SpriteModel::setCurrentFrame(int selectedIndex)
{
    qDebug() << "Frame Index: " << selectedIndex;
    emit currentFrameUpdated(frames[selectedIndex]);
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

    for (int i = 0; i < frames.size(); i++)
    {
        frames[i]->changeResolution(newPixelSize);
        std::cout << "telling frame " << i << " to update res" << std::endl;
    }
}

void SpriteModel::swapItem(int currentIndex, int newIndex)
{
    std::swap(frames[currentIndex], frames[newIndex]);

    setCurrentFrame(newIndex);
}

void SpriteModel::setDrawMirrored(bool checked)
{
    for (int i = 0; i < frames.size(); i++)
        frames[i]->setDrawMirrored(checked);
}
