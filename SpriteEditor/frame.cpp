#include "frame.h"
#include <QDebug>
#include <QRgba64>
#include <algorithm>

using namespace std;
Frame::Frame(QWidget *parent)
    : QWidget(parent)
{
    image= QImage(800, 800, QImage::Format_RGB32);

    image.fill(qRgba(160 , 160, 160, 10));
    currentPixelSize= 25;
    currentColor = Qt::gray;

//    for (int row = 0; row < 32; row++)
//    {
//        for (int column = 0; column < 32; column++)
//        {
//            colorGrid[row][column] = Qt::transparent;
//        }
//    }
}

Frame::Frame(const Frame& other)
{
    image = other.image.copy();
    currentPixelSize = other.currentPixelSize;
    gridResolution = other.gridResolution;
    currentXCoord = other.currentXCoord;
    currentYCoord = other.currentYCoord;
    currentColor = other.currentColor;
}

Frame& Frame::operator= (Frame other)
{
    swap(image, other.image);
    swap(currentPixelSize, other.currentPixelSize);
    swap(gridResolution, other.gridResolution);
    swap(currentXCoord, other.currentXCoord);
    swap(currentYCoord, other.currentYCoord);
    swap(currentColor, other.currentColor);
    return *this;
}

Frame::~Frame()
{

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
    //colorGrid[xIndex][yIndex] = color;
}
void Frame::paintEvent(QPaintEvent *)
{
    // Account for offset of our draw area within the window
    int* points = getPixelAtCoordinates(currentXCoord-10,currentYCoord-26);

    QPainter painter(this);
    QPainter imagePainter(&image);
    QBrush brush(currentColor);

    imagePainter.setBrush(brush);
    QRect rectangle(points[0], points[2], currentPixelSize, currentPixelSize);
    imagePainter.fillRect(rectangle,brush);

    QPen pen(Qt::white);
    painter.setPen(pen);
    painter.drawImage(QPoint(),image);

    //display grid lines
    for(int row = 0; row<=(image.height()/this->getCurrentPixelSize()); row++)
    {
        painter.drawLine(0, row*this->getCurrentPixelSize(), 800, row*this->getCurrentPixelSize());
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
