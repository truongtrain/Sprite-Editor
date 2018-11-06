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
    int* points  = myFrame.getPixelOfCoordinates(100,100);
    qDebug() << points[0];
    qDebug() << points[1];
    qDebug() << points[2];
    qDebug() << points[3];

    QPainter painter(&image);
    QBrush brush(gold);
    painter.setBrush(brush);
    painter.drawRect(points[0],points[2],32,32);



    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(graphic);
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}
