#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"

#include <QGridLayout>
#include <iostream>

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent, SpriteModel *model) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    // Setting up the color picker color
    penColor = Qt::black;
    currentFrame = nullptr;

    ui->setupUi(this);

   QObject::connect(ui->addFrameButton, &QPushButton::pressed,
                    model, &SpriteModel::addFrame);
   // Lambda to send an integer to our slot
   QObject::connect(ui->removeFrameButton, &QPushButton::pressed,
                    this, &SpriteEditorWindow::handleRemovedFrame);
   QObject::connect(this, &SpriteEditorWindow::frameRemoved,
                    model, &SpriteModel::removeFrame);
   QObject::connect(ui->duplicateButton, &QPushButton::pressed,
                    [=]() {model->duplicateFrame(ui->framesList->currentRow());});
   QObject::connect(this, &SpriteEditorWindow::updateCurrentFrameIndex,
                    model, &SpriteModel::setCurrentFrame);
   QObject::connect(ui->framesList, &QListWidget::itemPressed,
                    this, &SpriteEditorWindow::handleItemClicked);
   QObject::connect(this, &SpriteEditorWindow::resolutionSliderMovedSignal,
                    model, &SpriteModel::changeResolutionOfAllFrames);
   QObject::connect(this, &SpriteEditorWindow::drawMirroredBoxChangedSignal,
                    model, &SpriteModel::setDrawMirrored);
   QObject::connect(ui->itemUpButton, &QPushButton::pressed,
                    [=]() {swapItem(false);});
   QObject::connect(ui->itemDownButton, &QPushButton::pressed,
                    [=]() {swapItem(true);});
   QObject::connect(this, &SpriteEditorWindow::itemSwapped,
                    model, &SpriteModel::swapItem);


   // Listen for signals from model
   QObject::connect(model, &SpriteModel::frameAdded,
                    this, &SpriteEditorWindow::handleAddedFrame);
   QObject::connect(model, &SpriteModel::frameDuplicated,
                    this, &SpriteEditorWindow::handleDuplicatedFrame);
   QObject::connect(model, &SpriteModel::currentFrameUpdated,
                    this, &SpriteEditorWindow::updateFrame);

   // We do this here instead of the model constructor because the constructor
   // executes before the signals are connected.

   model->addFrame();
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    // Current frame points to a frame from model, so to avoid double deletion, we just set ours to nullptr
    // and let the parent handle deletion.
    currentFrame = nullptr;
    delete ui;
}

void SpriteEditorWindow::handleAddedFrame(int framesMade)
{
    // The syntax for interpolating an int in a QString
    QString frameName = QString("Frame %1").arg(framesMade);

    // Add new blank frame and switch focus to it
    ui->framesList->addItem(frameName);

    int lastRow = ui->framesList->count() - 1;
    ui->framesList->setCurrentRow(lastRow);

    emit updateCurrentFrameIndex(lastRow);
    updateButtonsToDisable();
}

void SpriteEditorWindow::handleRemovedFrame()
{
    // Removes the currently selected item
    int removedIndex = ui->framesList->currentRow();
    ui->framesList->takeItem(removedIndex);
    int newIndex = ui->framesList->currentRow();
    emit frameRemoved(removedIndex, newIndex);

    updateButtonsToDisable();
}

void SpriteEditorWindow::handleDuplicatedFrame()
{
     QString originalName = ui->framesList->currentItem()->text();
     QString copyName = QString(originalName + " Copy");

     int copyIndex = ui->framesList->currentRow() + 1;
     ui->framesList->insertItem(copyIndex, copyName);
     ui->framesList->setCurrentRow(copyIndex);

     emit updateCurrentFrameIndex(copyIndex);

     updateButtonsToDisable();
}

void SpriteEditorWindow::updateButtonsToDisable()
{
    bool isLastFrame = (ui->framesList->count() == 1);
    bool isFirstRow = (ui->framesList->currentRow() == 0);
    bool isLastRow = (ui->framesList->currentRow() == ui->framesList->count() - 1);

    ui->removeFrameButton->setDisabled(isLastFrame);
    ui->itemUpButton->setDisabled(isFirstRow);
    ui->itemDownButton->setDisabled(isLastRow);
}

void SpriteEditorWindow::updateFrame(Frame* newCurrent)
{
    if(currentFrame)
    {
        currentFrame->hide();
        ui->frameLayout->removeWidget(currentFrame);
    }
    currentFrame = newCurrent;
    newCurrent->show();
    ui->frameLayout->addWidget(newCurrent, 0 , 0);
}

void SpriteEditorWindow::swapItem(bool isMoveDown)
{
    // Remove the currently selected item and readd it 1 up or 1 down
    int currentIndex = ui->framesList->currentRow();
    QListWidgetItem* currentItem = ui->framesList->takeItem(currentIndex);
    int nextIndex = currentIndex;

    if(isMoveDown)
    {
        nextIndex = currentIndex + 1;
    }
    else
    {
        nextIndex = currentIndex - 1;
    }

    ui->framesList->insertItem(nextIndex, currentItem);
    emit itemSwapped(currentIndex, nextIndex);

    // Focus on the item after we readd it
    ui->framesList->setCurrentRow(nextIndex);
    updateButtonsToDisable();
}

void SpriteEditorWindow::handleItemClicked()
{
    emit updateCurrentFrameIndex(ui->framesList->currentRow());
    updateButtonsToDisable();
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
    // 10 is the x offset of the frame and 26 is the y offset
    bool isMouseInFrame = (event->x() >= 10 && event->x() <= 810 && event->y() >= 26 && event->x() <= 826);
    if(isMouseInFrame)
    {
        mousePressed = true;
        qDebug() << "x: " << event->x();
        qDebug() << "y: " << event->y();
        qDebug() << "Color: " << penColor;
        currentFrame->drawPixel(event->x(),event->y(),penColor);
    }
}


void SpriteEditorWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mousePressed = false;
}

void SpriteEditorWindow::on_resolutionSlider_sliderMoved(int position)
{
    std::cout << "resolution slider moved to " << position << std::endl;
    emit resolutionSliderMovedSignal(position);
}

void SpriteEditorWindow::on_drawMirrorCheckBox_toggled(bool checked)
{
    emit drawMirroredBoxChangedSignal(checked);
}
