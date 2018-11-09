#include "spritemodel.h"
#include <QDebug>

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



    //add image
    QImage image;
    image= QImage(960,960,QImage::Format_RGB32);

    image.fill(qRgba(160 , 160, 160, 10));
    images.append(image);
    int frameCount = int(images.size());
    currentFrameIndex = frameCount - 1;
    emit frameChanged(frameCount);

    /*
    Frame myFrame;
    frames->push_back(myFrame);
    */


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
