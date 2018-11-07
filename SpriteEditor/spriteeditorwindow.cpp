#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"
#include "frame.h"


SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{

    // Setting up the color picker color
    penColor = Qt::black;

    ui->setupUi(this);

    myFrame = new Frame();

    myFrame->drawGrid();


    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(myFrame->getImage()));
    ui->graphicsView->setScene(graphic);
    ui->graphicsView->setMouseTracking(true);
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}

void SpriteEditorWindow::on_chooseColorBox_clicked()
{
        // Opening the QColorDialog
        penColor = QColorDialog::getColor(penColor, this);

        if(penColor.isValid())
        {
            // changing the label background color to the selected color

            QString currentColor = QString("background-color:" + penColor.name());
            ui->colorLabel->setStyleSheet(currentColor);
        }
}


void SpriteEditorWindow::mouseMoveEvent(QMouseEvent *event){

}

void SpriteEditorWindow::mousePressEvent(QMouseEvent *event)
{
    //qDebug() << "x: " << event->x();
    //qDebug() << "y: " << event->y();

    //  lastXPosition = event->x();
    //  lastYPostion = event->y();

    myFrame->drawPixel(event->x(),event->y(),penColor);

}

void SpriteEditorWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "x: " << event->x();
    qDebug() << "y: " << event->y();

   // myFrame->drawPixel(lastXPosition,lastYPostion,penColor);
}
