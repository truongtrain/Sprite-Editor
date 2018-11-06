#include "frame.h"
#include <QDebug>
#include <vector>
Frame::Frame()
{
    image= QImage(350,350,QImage::Format_RGB32);
    currentPixelSize=30;
//    painter = QPainter(&image);

}

//QPainter Frame::getPainter()
//{
//    return this->painter;
//}

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

int* Frame::getPixelOfCoordinates(int x, int y)
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
void Frame::drawGrid()
{

    QPainter painter(&image);

    QRgb white;
    white = qRgb(255,255,255);
    QBrush brush(white);

    painter.setBrush(brush);
    std::vector<QRect> rectangles;

    for(int y = 0; y < 350; y += currentPixelSize + 5) {
            for(int x = 0; x < 350; x += currentPixelSize + 5) {
                QRect rect(x, y, currentPixelSize, currentPixelSize);
                //rectangles.push_back(rect);
                painter.fillRect(rect, brush);
                rectangles.push_back(rect);
            }
    }
    QRgb gold;
    gold = qRgb(189, 149, 39);
    QBrush goldBrush(gold);
    painter.fillRect(rectangles[25], goldBrush);

}
