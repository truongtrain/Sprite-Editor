#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    // copied from Alan branch
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

    ui->graphicsView->setInteractive(true);
    ui->graphicsView->setScene(graphic);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "x: " << event->x();
    qDebug() << "y: " << event->y();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}

void MainWindow::on_pushButton_clicked()
{

    //Opening the QColorDialog

    color = QColorDialog::getColor(Qt::red,this);

    if(color.isValid())
    {
        qDebug() << "Color Choosen: " << color.name();

        //changing the button background color from the selected color

        QString currentColor = QString("background-color:" + color.name());
        ui->currentColorButtonDisplay->setStyleSheet(currentColor);
    }
}
