#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    ui->setupUi(this);

    QImage image(300, 300, QImage::Format_RGB32);

    QRgb gold;

    gold = qRgb(189, 149, 39);

    for (int x = 0; x < 100; x++)
    {
        for (int y = 0; y < 100; y++)
        {
            image.setPixel(x, y, gold);
        }
    }

    QRgb green = qRgb(122, 163, 39);

    for (int x = 0; x < 100; x++)
    {
        for (int y = 200; y < 300; y++)
        {
            image.setPixel(x, y, green);
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
