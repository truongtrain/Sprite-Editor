#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"

#include <QGridLayout>


SpriteEditorWindow::SpriteEditorWindow(QWidget *parent, SpriteModel *model) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    // Setting up the color picker color
    penColor = Qt::black;

    ui->setupUi(this);
    ui->removeFrameButton->setDisabled(true);

   QObject::connect(ui->addFrameButton, &QPushButton::pressed,
                    model, &SpriteModel::addFrame);
   // Lambda to send an integer to our slot
   QObject::connect(ui->removeFrameButton, &QPushButton::pressed,
                    [=]() {model->removeFrame(ui->frameList->currentRow());});
   QObject::connect(this, &SpriteEditorWindow::updateCurrentFrameIndex,
                    model, &SpriteModel::setCurrentFrameIndex);

   // Listen for signals from model
   QObject::connect(model, &SpriteModel::frameAdded,
                    this, &SpriteEditorWindow::handleAddedFrame);
   QObject::connect(model, &SpriteModel::frameRemoved,
                    this, &SpriteEditorWindow::handleRemovedFrame);
   QObject::connect(model, &SpriteModel::currentFrameUpdated,
                    this, &SpriteEditorWindow::updateFrame);

   // We do this here instead of the model constructor because it executes
   // before the signals are connected.

   model->addFrame();
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
    // Current frame points to a frame from model, so to avoid double deletion, we just set ours to nullptr
    // and let the parent handle deletion.
    currentFrame = nullptr;
}

void SpriteEditorWindow::handleAddedFrame(int framesMade)
{
    // The syntax for interpolating an int in a QString
    QString frameName = QString("Frame %1").arg(framesMade);

    // Add new blank frame and switch focus to it
    ui->frameList->addItem(frameName);
    int lastRow = ui->frameList->count() - 1;
    ui->frameList->setCurrentRow(lastRow);
    updateRemoveButton();
}

void SpriteEditorWindow::handleRemovedFrame()
{
    // Removes the currently selected item
    int selectionIndex = ui->frameList->currentRow();
    ui->frameList->takeItem(selectionIndex);

    emit updateCurrentFrameIndex(ui->frameList->currentRow());
    updateRemoveButton();
}

void SpriteEditorWindow::updateRemoveButton()
{
    bool isLastFrame = (ui->frameList->count() == 1);
    ui->removeFrameButton->setDisabled(isLastFrame);
}

void SpriteEditorWindow::updateFrame(Frame* current)
{
    ui->frameLayout->takeAt(0);
    ui->frameLayout->addWidget(current);
    currentFrame = current;
    currentFrame->update();
}

void SpriteEditorWindow::on_chooseColorBox_clicked()
{
    // Opening the QColorDialog
    penColor = QColorDialog::getColor(penColor, this);

    if(penColor.isValid())
    {
        // Changing the label background color to the selected color
        QString currentColor = QString("background-color:" + penColor.name());
        ui->colorLabel->setStyleSheet(currentColor);
    }
}


void SpriteEditorWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (mousePressed)
    {
        currentFrame->drawPixel(event->x(),event->y(),penColor);
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

    currentFrame->drawPixel(event->x(),event->y(),penColor);
}

void SpriteEditorWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mousePressed = false;
}
