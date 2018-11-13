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
    ui->removeFrameButton->setDisabled(true);

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
                    model, &SpriteModel::setCurrentFrameIndex);
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

   // Listen for signals from model
   QObject::connect(model, &SpriteModel::frameAdded,
                    this, &SpriteEditorWindow::handleAddedFrame);
   QObject::connect(model, &SpriteModel::frameDuplicated,
                    this, &SpriteEditorWindow::handleDuplicatedFrame);
   QObject::connect(model, &SpriteModel::currentFrameUpdated,
                    this, &SpriteEditorWindow::updateFrame);
   QObject::connect(model, &SpriteModel::sendImages,
                    this, &SpriteEditorWindow::receiveImages);


   // send signal from view to model
   QObject::connect(ui->actionExport,&QAction::triggered, model, &SpriteModel::exportGif);

   // We do this here instead of the model constructor because it executes
   // before the signals are connected.

   model->addFrame();
   currentFrameIndex = 0;
   imageIndex = 0;
   fps = 1;

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
    updateRemoveButton();
}

void SpriteEditorWindow::handleRemovedFrame()
{
    // Removes the currently selected item
    int removedIndex = ui->framesList->currentRow();
    ui->framesList->takeItem(removedIndex);
    int newIndex = ui->framesList->currentRow();
    emit frameRemoved(removedIndex, newIndex);

    updateRemoveButton();
}

void SpriteEditorWindow::handleDuplicatedFrame(int originalIndex)
{
     QString originalName = ui->framesList->currentItem()->text();
     QString copyName = QString(originalName + " Copy");

     int copyIndex = ui->framesList->currentRow() + 1;
     ui->framesList->insertItem(copyIndex, copyName);
     ui->framesList->setCurrentRow(copyIndex);

     emit updateCurrentFrameIndex(copyIndex);

     updateRemoveButton();
}

void SpriteEditorWindow::updateRemoveButton()
{
    bool isLastFrame = (ui->framesList->count() == 1);
    ui->removeFrameButton->setDisabled(isLastFrame);
}

void SpriteEditorWindow::updateFrame(Frame& newCurrent)
{
    ui->frameLayout->removeWidget(currentFrame);
    ui->frameLayout->addWidget(&newCurrent, 0 , 0);
    currentFrame = &newCurrent;

    currentFrame->update();
    qDebug() << currentFrame;
}

void SpriteEditorWindow::handleItemClicked()
{
    updatePreviewImage();
    emit updateCurrentFrameIndex(ui->framesList->currentRow());

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
    QImage& image = currentFrame->getImage();
    emit updateAnimation(currentFrameIndex, image);

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
}


void SpriteEditorWindow::on_actionExport_triggered()
{

}
