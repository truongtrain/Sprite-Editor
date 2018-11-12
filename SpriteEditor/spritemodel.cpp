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
    frames.push_back(new Frame(nullptr,isDrawMirroredChecked));

    // Adding a frame switches focus to that new frame
    framesMade++;
    images.append(QPixmap().toImage());
    emit sendImages(images);
    emit frameAdded(framesMade);

    frames[frames.size()-1]->changeResolution(currentPixelSize);
}

void SpriteModel::removeFrame(int removedIndex, int newIndex)
{
    delete frames.at(removedIndex);
    frames.erase(frames.begin() + removedIndex);
    setCurrentFrameIndex(newIndex);
    images.removeAt(removedIndex);
    emit sendImages(images);
}

void SpriteModel::duplicateFrame(int index)
{
    Frame* original = frames.at(index);
    Frame* copy = new Frame(*original);

    int newIndex = index + 1;
    frames.insert(frames.begin() + newIndex, copy);
    images.insert(newIndex, copy->getImage());
    framesMade++;

    emit frameDuplicated(index);
    emit sendImages(images);
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

    currentPixelSize = newPixelSize;

    for (unsigned long i = 0; i < frames.size(); i++)
    {
        frames[i]->changeResolution(newPixelSize);
        std::cout << "telling frame " << i << " to update res" << std::endl;
    }
}

void SpriteModel::setDrawMirrored(bool checked)
{
    isDrawMirroredChecked = checked;
    for (unsigned long i = 0; i < frames.size(); i++)
        frames[i]->setDrawMirrored(checked);
}

void SpriteModel::getImages()
{
    qDebug() << "images sent";
    updateImages(currentFrameIndex, images[currentFrameIndex]);
    emit sendImages(images);
}

void SpriteModel::updateImages(int index, QImage& image)
{
    qDebug() << "image " << index << " updated";
    images[index] = image;
    emit sendImages(images);
}
