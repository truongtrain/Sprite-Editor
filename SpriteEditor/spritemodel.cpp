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
    //delete frames.at(removedIndex);
    //frames.erase(frames.begin() + removedIndex);
    //setCurrentFrameIndex(newIndex);
    images.removeAt(removedIndex);
    emit sendImages(images);
    delete frames[removedIndex];
    frames.removeAt(removedIndex);
    setCurrentFrame(newIndex);
}

void SpriteModel::duplicateFrame(int index)
{
    //Frame* original = frames.at(index);

    //int newIndex = index + 1;
    //frames.insert(frames.begin() + newIndex, copy);

    //emit frameDuplicated(index);
    Frame* original = frames[index];
    //Frame* copy = new Frame(*original);
    Frame* copy = new Frame(*original,isDrawMirroredChecked);

    int newIndex = index + 1;
    images.insert(newIndex, copy->getImage());
    frames.insert(newIndex, copy);

    framesMade++;

    emit sendImages(images);
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

    int scaleFactor = std::pow(2, value);
    int newPixelSize = 200/scaleFactor;

    currentPixelSize = newPixelSize;

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
    isDrawMirroredChecked = checked;
    //for (unsigned long i = 0; i < frames.size(); i++)

    for (int i = 0; i < frames.size(); i++)
        frames[i]->setDrawMirrored(checked);
}

void SpriteModel::getImages()
{
    qDebug() << "images sent";
    //updateImages(currentFrameIndex, images[currentFrameIndex]);
    qDebug() << "line 109";
    emit sendImages(images);
}

void SpriteModel::updateImages(int index, QImage& image)
{
    qDebug() << "image " << index << " updated";
    images[index] = image;
    emit sendImages(images);
}
