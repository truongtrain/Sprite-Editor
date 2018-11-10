#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"
#include "frame.h"

#include <QGridLayout>


SpriteEditorWindow::SpriteEditorWindow(QWidget *parent, SpriteModel *model) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{

    // Setting up the color picker color
    penColor = Qt::black;

    ui->setupUi(this);

    myFrame = new Frame();

    ui->frameLayout->addWidget(myFrame, 0, 0);



   QObject::connect(ui->addFrameButton, &QPushButton::pressed,
                    model, &SpriteModel::addFrame);
   // Lambda to send an integer to our slot
   QObject::connect(ui->removeFrameButton, &QPushButton::pressed,
                    [=]() {model->removeFrame(ui->frameList->currentRow());});
   QObject::connect(this, &SpriteEditorWindow::updateCurrentFrameIndex,
                    model, &SpriteModel::setCurrentFrameIndex);

   // Listen for signals from model
   QObject::connect(model, &SpriteModel::frameChanged,
                    this, &SpriteEditorWindow::updateFrameList);

   // We do this here instead of the model constructor because it executes
   // before the signals are connected.

   model->addFrame();

   ui->selectionButton->setAttribute(Qt::WA_KeyCompression);

}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
    //delete myFrame;
}

void SpriteEditorWindow::updateFrameList(int frameCount)
{
    int totalItems = ui->frameList->count();

    // Check to see if frame was added or removed
    if(frameCount > totalItems)
    {
        // The syntax for interpolating an int in a QString
        QString frameName = QString("Frame %1").arg(frameCount);

        // Add new blank frame and switch focus to it
        ui->frameList->addItem(frameName);
        ui->frameList->setCurrentRow(frameCount - 1);

        emit updateCurrentFrameIndex(ui->frameList->currentRow());
    }
    else
    {
      // Removes the currently selected item
      int selectionIndex = ui->frameList->currentRow();
      ui->frameList->takeItem(selectionIndex);
    }

    bool isLastFrame = (ui->frameList->count() == 1);
    ui->removeFrameButton->setDisabled(isLastFrame);
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


void SpriteEditorWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (ui->penButton->isChecked() && mousePressed)
    {
        myFrame->drawPixel(event->x(),event->y(),penColor);
    }

    if(ui->eraserButton->isChecked()){
        myFrame->drawPixel(event->x(),event->y(),qRgba(160 , 160, 160, 10));
    }
}

void SpriteEditorWindow::mousePressEvent(QMouseEvent *event)
{
    if(ui->penButton->isChecked())
    {
        mousePressed = true;
//          qDebug() << "x: " << event->x();
//          qDebug() << "y: " << event->y();
//          qDebug() << "Color: " << penColor;

        //  lastXPosition = event->x();
        //  lastYPostion = event->y();

        myFrame->drawPixel(event->x(),event->y(),penColor);
        myFrame->setIsPixelSelected(false);
        return;
    }

    if(ui->eraserButton->isChecked())
    {
        myFrame->drawPixel(event->x(),event->y(),qRgba(160 , 160, 160, 10));
        myFrame->setIsPixelSelected(false);
        return;
    }

    if(ui->selectionButton->isChecked())
    {
        if(event->x() >= 10 && event->x() < 810 && event->y() >=26 && event->y() <826)
        {
            myFrame->setIsPixelSelected(true);
            qDebug() << "event x was" << event->x() ;
            myFrame->setCurrentSelectedX(event->x());
            myFrame->setCurrentSelectedY(event->y());
            qDebug() << "selected color was" << QColor(myFrame->getImage().pixel(event->x(), event->y())) ;
            myFrame->setSelectedColor(QColor(myFrame->getImage().pixel(event->x(), event->y())));
        }
    }
}

void SpriteEditorWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(ui->penButton->isChecked())
    {
        mousePressed = false;
    }

    if(ui->eraserButton->isChecked())
    {
        mousePressed = false;
    }


}

void SpriteEditorWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        qDebug() << "key up is press";
    }
}

void SpriteEditorWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up) // which arrow == 0
    {
        qDebug() << "Im here";
        if(myFrame->getIsPixelSelected())
        {

            qDebug() << "Im here 2";
//            qDebug() << "X is" <<myFrame->getCurrentSelectedX();
//            qDebug() << "Y is" <<myFrame->getCurrentSelectedY();
//            myFrame->drawPixel(myFrame->getCurrentSelectedX(),myFrame->getCurrentSelectedY(),Qt::gray);
//            myFrame->drawPixel(myFrame->getCurrentSelectedX(),myFrame->getCurrentSelectedY()-myFrame->getCurrentPixelSize(),myFrame->getSelectedColor());

//            myFrame->setCurrentSelectedY(myFrame->getCurrentSelectedY()-myFrame->getCurrentPixelSize());
            myFrame->movePixel(myFrame->getCurrentSelectedX(),myFrame->getCurrentSelectedY(), myFrame->getSelectedColor(),0);
            qDebug() << "Y is now" <<myFrame->getCurrentSelectedY();

        }
    }

    if(event->key() == Qt::Key_Down)
    {
        if(myFrame->getIsPixelSelected())
        {

        }
    }

    if(event->key() == Qt::Key_Left)
    {
        if(myFrame->getIsPixelSelected())
        {

        }
    }

    if(event->key() == Qt::Key_Right)
    {
        if(myFrame->getIsPixelSelected())
        {

        }
    }
}
