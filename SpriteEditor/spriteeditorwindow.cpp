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

    previewTimer = new QTimer(this);
   QObject::connect(previewTimer, SIGNAL(timeout()),this,SLOT(updatePreviewImage()));


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
   QObject::connect(ui->popOutButton, &QPushButton::pressed,
                    model, &SpriteModel::getImages);
   QObject::connect(this, &SpriteEditorWindow::updateAnimation,
                    model, &SpriteModel::updateImages);
   QObject::connect(ui->itemUpButton, &QPushButton::pressed,
                    [=]() {swapItem(false);});
   QObject::connect(ui->itemDownButton, &QPushButton::pressed,
                    [=]() {swapItem(true);});
   QObject::connect(this, &SpriteEditorWindow::itemSwapped,
                    model, &SpriteModel::swapItem);
   QObject::connect(this, &SpriteEditorWindow::saveFrame,
                      model, &SpriteModel::save);
   QObject::connect(this, &SpriteEditorWindow::loadFrame,
                      model, &SpriteModel::load);


   // Listen for signals from model
   QObject::connect(model, &SpriteModel::frameAdded,
                    this, &SpriteEditorWindow::handleAddedFrame);
   QObject::connect(model, &SpriteModel::frameDuplicated,
                    this, &SpriteEditorWindow::handleDuplicatedFrame);
   QObject::connect(model, &SpriteModel::currentFrameUpdated,
                    this, &SpriteEditorWindow::updateFrame);
   QObject::connect(model, &SpriteModel::sendImages,
                    this, &SpriteEditorWindow::receiveImages);



   // We do this here instead of the model constructor because the constructor
   // executes before the signals are connected.

   model->addFrame();
   currentFrameIndex = 0;
   imageIndex = 0;
   fps = 1;
   ui->selectionButton->setAttribute(Qt::WA_KeyCompression);


   previewTimer->start(1000/fps);
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

    currentFrameIndex = lastRow;
    qDebug()<<"frame index" << currentFrameIndex;
    emit updateCurrentFrameIndex(lastRow);
    updateButtonsToDisable();
}

void SpriteEditorWindow::handleRemovedFrame()
{
    // Removes the currently selected item
    int removedIndex = ui->framesList->currentRow();
    ui->framesList->takeItem(removedIndex);
    int newIndex = ui->framesList->currentRow();
    currentFrame->hide();
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
    ui->frameLayout->removeWidget(currentFrame);
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
    currentFrame->hide();
    updatePreviewImage();
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
    if (ui->penButton->isChecked() && mousePressed)
    {
        currentFrame->drawPixel(event->x(),event->y(),penColor);
    }

    if(ui->eraserButton->isChecked()){
        currentFrame->drawPixel(event->x(),event->y(),qRgba(160 , 160, 160, 10));
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
    QImage& image = currentFrame->getImage();
    emit updateAnimation(currentFrameIndex, image);

    if(ui->penButton->isChecked())
    {
        mousePressed = true;
          qDebug() << "x: " << event->x();
         qDebug() << "y: " << event->y();
//          qDebug() << "Color: " << penColor;

        //  lastXPosition = event->x();
        //  lastYPostion = event->y();

        currentFrame->drawPixel(event->x(),event->y(),penColor);
        currentFrame->setIsPixelSelected(false);
        return;
    }

    if(ui->eraserButton->isChecked())
    {
        currentFrame->drawPixel(event->x(),event->y(),qRgba(160 , 160, 160, 10));
        currentFrame->setIsPixelSelected(false);
        return;
    }

    if(ui->selectionButton->isChecked())
    {
        if(event->x() >= 12 && event->x() <= 812 && event->y() >=29 && event->y() <=829)
        {
            currentFrame->setIsPixelSelected(true);
            qDebug() << "event x was" << event->x() ;
            currentFrame->setCurrentSelectedX(event->x());
            currentFrame->setCurrentSelectedY(event->y());
            qDebug() << "selected color was" << QColor(currentFrame->getImage().pixel(event->x(), event->y())) ;
            currentFrame->setSelectedColor(currentFrame->getImage().pixelColor(event->x()-12, event->y()-29));
        }
    }
}


void SpriteEditorWindow::mouseReleaseEvent(QMouseEvent *event)
{

    qDebug()<<"begin mouse release";
    mousePressed = false;
    updatePreviewImage();
    QImage& image = currentFrame->getImage();
    qDebug()<<"mouse release event popup images size" << popup.images.size();
    emit updateAnimation(currentFrameIndex, image);

}


void SpriteEditorWindow::updatePreviewImage()
{
     qDebug()<<"updatePreviewImage1 begin";

    QImage image;

    if (currentFrameIndex == 0)
    {
        image = currentFrame->getImage();
    }
    else
    {
        image = images[imageIndex];
    }

    int height = image.height()/5;
    int width = image.width()/5;
    QImage previewImage = image.scaled(width, height, Qt::KeepAspectRatio);
    ui->previewLabel->setPixmap(QPixmap::fromImage(previewImage));
    ui->previewLabel->show();

    incrementImageIndex();
    qDebug()<<"updatePreviewImage1 end";
}

void SpriteEditorWindow::incrementImageIndex()
{

    if (imageIndex < images.size() - 1) // if this is not the last image in the sequence
    {
        imageIndex++;
    }
    else
    {
        imageIndex = 0; //otherwise, go back to the first image in the sequence
    }
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


void SpriteEditorWindow::on_popOutButton_clicked()
{
    popup.setFps(fps);
    popup.popupOpen = true;
    popup.show();
    popup.start();

}

void SpriteEditorWindow::receiveImages(QList<QImage> imageList)
{
    qDebug()<<"images received and sent to popup";
    images = imageList;
    popup.setImages(imageList);
}

void SpriteEditorWindow::on_frameRateSlider_sliderMoved(int position)
{
    int fps = position * 2;

    //change the timer to the new fps
    previewTimer->stop();
    previewTimer->start(1000/fps);

    // Update the popup to have the same fps
    popup.setFps(fps);

    emit frameRateSliderMoved(fps);

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
        if(currentFrame->getCurrentSelectedY() < 35 + currentFrame->getCurrentPixelSize()/2)
        {
            return;
        }
        if(currentFrame->getIsPixelSelected())
        {
            //create  the setter for this variable
            currentFrame->whichArrow = 0;
            currentFrame->shiftPixel(currentFrame->getCurrentSelectedX(),currentFrame->getCurrentSelectedY(), currentFrame->getSelectedColor());
            currentFrame->update();
            currentFrame->setCurrentSelectedY(currentFrame->getCurrentSelectedY()-currentFrame->getCurrentPixelSize());

        }
    }

    if(event->key() == Qt::Key_Down)
    {
        if(currentFrame->getCurrentSelectedY() > 815 - currentFrame->getCurrentPixelSize()/2)
        {
            return;
        }
        if(currentFrame->getIsPixelSelected())
        {
            currentFrame->whichArrow = 1;
            currentFrame->shiftPixel(currentFrame->getCurrentSelectedX(),currentFrame->getCurrentSelectedY(), currentFrame->getSelectedColor());
            currentFrame->update();
            currentFrame->setCurrentSelectedY(currentFrame->getCurrentSelectedY()+currentFrame->getCurrentPixelSize());

        }
    }

    if(event->key() == Qt::Key_Left)
    {
        if(currentFrame->getCurrentSelectedX() < 25+ currentFrame->getCurrentPixelSize()/2)
        {
            return;
        }
        if(currentFrame->getIsPixelSelected())
        {
            currentFrame->whichArrow = 2;
            currentFrame->shiftPixel(currentFrame->getCurrentSelectedX(),currentFrame->getCurrentSelectedY(), currentFrame->getSelectedColor());
            currentFrame->update();
            currentFrame->setCurrentSelectedX(currentFrame->getCurrentSelectedX()-currentFrame->getCurrentPixelSize());

        }
    }

    if(event->key() == Qt::Key_Right)
    {
        if(currentFrame->getCurrentSelectedX() > 800 - currentFrame->getCurrentPixelSize()/2)
        {
            return;
        }
        if(currentFrame->getIsPixelSelected())
        {
            currentFrame->whichArrow = 3;
            currentFrame->shiftPixel(currentFrame->getCurrentSelectedX(),currentFrame->getCurrentSelectedY(), currentFrame->getSelectedColor());
            currentFrame->update();
            currentFrame->setCurrentSelectedX(currentFrame->getCurrentSelectedX()+currentFrame->getCurrentPixelSize());

        }
    }

    updatePreviewImage();
}

void SpriteEditorWindow::on_actionSave_triggered()
{
    //QFileDialog dialog(this);
     QString fileName = QFileDialog::getSaveFileName(this,tr("Save Sprite Sheet Project"), "", tr("Sprite Sheet Project (*.ssp)"));
     if (!fileName.endsWith(".ssp"))
         fileName += ".ssp";
    emit saveFrame(fileName);
}

void SpriteEditorWindow::on_actionOpen_triggered()
{
    //QFileDialog dialog(this);
    currentFrame->hide();
    //previewTimer->stop();
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Sprite Sheet Project"), "",
            tr("Sprite Sheet Project (*.ssp)"));
    emit loadFrame(fileName);
}
