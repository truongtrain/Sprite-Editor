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
    if (mousePressed)
    {
        myFrame->drawPixel(event->x(),event->y(),penColor);
    }
}

void SpriteEditorWindow::mousePressEvent(QMouseEvent *event)
{
    mousePressed = true;

      qDebug() << "x: " << event->x();
      qDebug() << "y: " << event->y();
      qDebug() << "Color: " << penColor;

    //  lastXPosition = event->x();
    //  lastYPostion = event->y();

    myFrame->drawPixel(event->x(),event->y(),penColor);
}

void SpriteEditorWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mousePressed = false;
}
