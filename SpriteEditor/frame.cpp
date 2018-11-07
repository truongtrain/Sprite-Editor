#include "frame.h"
#include <QDebug>
#include <QRgba64>


Frame::Frame(QWidget *parent)
    : QWidget(parent)
{
    image= QImage(GRID_RESOLUTION,GRID_RESOLUTION,QImage::Format_RGB32);

    image.fill(qRgba(160 , 160, 160, 10));
    currentPixelSize= 30;

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
    qDebug() << "Paint event is being called";
    //int* points = getPixelAtCoordinates(currentXCoord,currentYCoord);

    QPainter painter(this);
    QBrush brush(currentColor);

    painter.setBrush(brush);

    QRect rectangle(currentXCoord, currentYCoord, this->currentPixelSize,this->currentPixelSize);

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

    for (int row = 0; row < 32; row++)
    {
        for (int column = 0; column < 32; column++)
        {
            QColor color = colorGrid[row][column];
            QBrush brush(color);
            painter.setBrush(brush);
            QRect rectangle(row*currentPixelSize, column*currentPixelSize, this->currentPixelSize,this->currentPixelSize);
            painter.fillRect(rectangle, brush);

        }
    }
    qDebug()<<"row: " << 0 << " column: " << 0 << " color: " << colorGrid[0][0];


//    for (int row = 0; row < 32; row++)
//    {
//        for (int column = 0; column < 32; column++)
//        {

//        }
//    }
}

void Frame::drawPixel(int x, int y, QColor color) {

    qDebug() << x;
    qDebug() << y;

    currentXCoord = x;
    currentYCoord = y;
    currentColor = color;
    saveColor(x, y, color);
    update();
    }

void Frame::drawGrid()
{

    QPainter painter(this);


}
