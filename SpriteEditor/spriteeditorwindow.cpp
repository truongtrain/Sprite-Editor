#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"
#include "frame.h"
#include <QDebug>
#include <QMouseEvent>
SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    ui->setupUi(this);

    Frame myFrame= Frame();
    //QImage image = myFrame.getImage();
    QRgb gold;
    gold = qRgb(189, 149, 39);
    int* points  = myFrame.getPixelOfCoordinates(100,100);
//    qDebug() << points[0];
//    qDebug() << points[1];
//    qDebug() << points[2];
//    qDebug() << points[3];

//    QPainter painter(&image);
//    QBrush brush(gold);
//    painter.setBrush(brush);
//    painter.drawRect(100,100,32,32);
    myFrame.drawGrid();



    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(myFrame.getImage()));
    ui->graphicsView->setScene(graphic);
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}

void SpriteEditorWindow::mouseMoveEvent(QMouseEvent *event){

}

void SpriteEditorWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "x: " << event->x();
    qDebug() << "y: " << event->y();
}

void SpriteEditorWindow::mouseReleaseEvent(QMouseEvent *event)
{

}
