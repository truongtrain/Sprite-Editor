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


void SpriteModel::changeResolution(int res)
{
    res++;
}

void SpriteModel::addNewFrameFromButton()
{
   // Frame newFrame;
    frames.push_back(new Frame);

<<<<<<< HEAD
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
=======
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
>>>>>>> master
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
