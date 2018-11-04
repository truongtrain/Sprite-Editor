#include "frame.h"
#include <QDebug>
Frame::Frame()
{
    image= QImage(1152,648,QImage::Format_RGB32);
    currentPixelSize=36;
}

QImage Frame::getImage()
{
    return this->image;
}

void Frame::setCurrentPixelSize(int newSize)
{
      this->currentPixelSize = newSize;
}

int Frame::getCurrentPixelSize()
{
    return this->currentPixelSize;
}

int* Frame::getPixelOfCoordinates(int x, int y)
{
    int xStarting = (x/currentPixelSize)*currentPixelSize;
    int xEnding = xStarting + currentPixelSize -1;
    qDebug() << currentPixelSize;
    qDebug() << xEnding;
    int yStarting = (y/currentPixelSize)*currentPixelSize;
    int yEnding = yStarting + currentPixelSize -1;

    static int result [4];
    result[0] = xStarting;
    result[1] = xEnding;
    result[2] = yStarting;
    result[3] = yEnding;
    return result;
}
