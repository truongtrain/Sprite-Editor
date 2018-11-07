#include "frame.h"
#include <QDebug>
#include <QRgba64>


Frame::Frame()
{
    image= QImage(GRID_RESOLUTION,GRID_RESOLUTION,QImage::Format_RGB32);
    image.fill(qRgba(160 , 160, 160, 10));
    currentPixelSize= 240;

    for (int row = 0; row < 32; row++)
    {
        for (int column = 0; column < 32; column++)
        {
            colorGrid[row][column] = Qt::transparent;
        }
    }
}

QImage& Frame::getImage()
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

int* Frame::getPixelAtCoordinates(int x, int y)
{
    int xStarting = (x/currentPixelSize)*currentPixelSize;
    int xEnding = xStarting + currentPixelSize -1;
    int yStarting = (y/currentPixelSize)*currentPixelSize;
    int yEnding = yStarting + currentPixelSize -1;

    static int result [4];
    result[0] = xStarting;
    result[1] = xEnding;
    result[2] = yStarting;
    result[3] = yEnding;
    return result;
}

void Frame::drawPixel(int x, int y, QColor color) {

    qDebug() << x;
    qDebug() << y;

    //int* points = getPixelAtCoordinates(x,y);

    int xStarting = (x/currentPixelSize)*currentPixelSize;
    int xEnding = xStarting + currentPixelSize -1;
    int yStarting = (y/currentPixelSize)*currentPixelSize;
    int yEnding = yStarting + currentPixelSize -1;

    QPainter painter(&image);

    QBrush brush(color);

   // QRect rect(xStarting,xEnding,yStarting,yEnding);

    painter.setBrush(brush);

    painter.drawRect(xStarting,xEnding,yStarting,yEnding);
   // painter.fillRect(rect,brush);
}

void Frame::drawGrid()
{

    QPainter painter(&image);

    QPen pen(Qt::white);
    painter.setPen(pen);

    for(int row = 0; row<=(image.height()/this->getCurrentPixelSize()); row++)
    {
        painter.drawLine(0, row*this->getCurrentPixelSize(), GRID_RESOLUTION, row*this->getCurrentPixelSize());
    }
    for(int column = 0; column<=(image.width()/this->getCurrentPixelSize()); column++)
    {
        painter.drawLine(column*this->getCurrentPixelSize(), 0, column*this->getCurrentPixelSize(), image.height());
    }
}
