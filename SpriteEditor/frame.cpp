#include "frame.h"
#include <QDebug>
#include <QRgba64>
#include <iostream>


Frame::Frame(QWidget *parent)
    : QWidget(parent)
{
    image= QImage(GRID_RESOLUTION,GRID_RESOLUTION,QImage::Format_RGB32);
    isDrawingMirrored = false;

    image.fill(qRgba(160 , 160, 160, 10));
    currentPixelSize= 25;
    currentColor = Qt::gray;
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
//    qDebug() << xStarting;
//    qDebug() << xEnding;
//    qDebug() << yStarting;
//    qDebug() << yEnding;
    result[1] = xEnding;
    result[2] = yStarting;
    result[3] = yEnding;
    return result;
}

void Frame::saveColor(int x, int y, QColor color)
{
    int xOffset = 10;
    int yOffset = 26;
    int xIndex = (x - xOffset)/currentPixelSize;
    int yIndex = (y - yOffset)/currentPixelSize;
    colorGrid[xIndex][yIndex] = color;
}
void Frame::paintEvent(QPaintEvent *)
{
    int* points = getPixelAtCoordinates(currentXCoord-10,currentYCoord-26);

    QPainter painter(this);
    QPainter imagePainter(&image);
    QBrush brush(currentColor);

    painter.setBrush(brush);
    imagePainter.setBrush(brush);
    QPen pen(Qt::white);
    painter.setPen(pen);


    QRect rectangle(points[0], points[2], this->currentPixelSize,this->currentPixelSize);
    imagePainter.setBrush(brush);


    imagePainter.fillRect(rectangle,brush);

    if (isDrawingMirrored)
    {
        //441
        int mirroredXCoord = 0;
        int mirroredYCoord = 0;

        if (currentXCoord <= 410)
            currentXCoord = 819 - currentXCoord;
        else if (currentXCoord > 410)
            currentXCoord = 819 - currentXCoord;

        int* points = getPixelAtCoordinates(currentXCoord-10,currentYCoord-26);

        QRect rectangle(points[0], points[2], this->currentPixelSize,this->currentPixelSize);
        imagePainter.setBrush(brush);

        imagePainter.fillRect(rectangle,brush);
    }

    painter.drawImage(QPoint(),image);

    //display grid lines
    for(int row = 0; row<=(image.height()/this->getCurrentPixelSize()); row++)
    {
        painter.drawLine(0, row*this->getCurrentPixelSize(), GRID_RESOLUTION, row*this->getCurrentPixelSize());
    }
    for(int column = 0; column<=(image.width()/this->getCurrentPixelSize()); column++)
    {
        painter.drawLine(column*this->getCurrentPixelSize(), 0, column*this->getCurrentPixelSize(), image.height());
    }

    //send image to model

}

void Frame::drawPixel(int x, int y, QColor color) {


    currentXCoord = x;
    currentYCoord = y;
    currentColor = color;
    //saveColor(x, y, color);
    update();
}

void Frame::changeResolution(int newPixelSize)
{

    if (newPixelSize > currentPixelSize)
    {
        image.fill(qRgba(160 , 160, 160, 10));
        currentColor = Qt::transparent;
    }

    this->currentPixelSize = newPixelSize;

    update();

    std::cout << "PixelSize changed to " << newPixelSize << std::endl;
}

void Frame::setDrawMirrored(bool checked)
{
    std::cout << "changing isDrawimgMirrored" << std::endl;

    isDrawingMirrored = checked;
}
