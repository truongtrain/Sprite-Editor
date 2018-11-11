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
    Frame newFrame;
    frames.push_back(newFrame);

    // Adding a frame switches focus to that new frame
    framesMade++;
    images.append(QPixmap().toImage());
    emit frameAdded(framesMade);
}

void SpriteModel::removeFrame(int selectedIndex)
{
    qDebug() << "Removed: " << selectedIndex;
    frames.erase(frames.begin() + selectedIndex);
    emit frameRemoved();
}

void SpriteModel::setCurrentFrameIndex(int selectedIndex)
{
    qDebug() << "Row changed: " << selectedIndex;
    currentFrameIndex = selectedIndex;
    emit currentFrameUpdated(&frames.at(selectedIndex));
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
