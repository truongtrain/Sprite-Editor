#include "spritemodel.h"
#include <QDebug>

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


void SpriteModel::changeResolution(int res)
{
    res++;
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
    delete frames.at(removedIndex);
    frames.erase(frames.begin() + removedIndex);
    setCurrentFrameIndex(newIndex);
}

void SpriteModel::duplicateFrame(int index)
{
    Frame* original = frames.at(index);
    Frame* copy = new Frame(*original);

    int newIndex = index + 1;
    frames.insert(frames.begin() + newIndex, copy);

    framesMade++;

    emit frameDuplicated(index);
}

void SpriteModel::setCurrentFrameIndex(int selectedIndex)
{
    qDebug() << "Row changed: " << selectedIndex;
    currentFrameIndex = selectedIndex;
    Frame* currentFrame = frames.at(selectedIndex);
    emit currentFrameUpdated(*currentFrame);
}

void SpriteModel::setDrawMirrored(bool checked)
{
    for (unsigned long i = 0; i < frames.size(); i++)
        frames[i]->setDrawMirrored(checked);
}
