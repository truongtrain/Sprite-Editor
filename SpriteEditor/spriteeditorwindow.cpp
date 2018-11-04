#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"
#include "frame.h"
#include <QDebug>
SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    ui->setupUi(this);

    Frame myFrame= Frame();
    QImage image = myFrame.getImage();
    QRgb gold;
    gold = qRgb(189, 149, 39);
    int* points  = myFrame.getPixelOfCoordinates(10,10);
    qDebug() << points[0];
    qDebug() << points[1];
    qDebug() << points[2];
    qDebug() << points[3];
    for (int x = points[0]; x < points[1]; x++)
    {

        for (int y = points[2]; y < points[3]; y++)
        {
            image.setPixel(x, y, gold);
        }
    }


    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(graphic);
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}
