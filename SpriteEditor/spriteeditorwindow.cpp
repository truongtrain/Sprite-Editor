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
                    [=]() {model->removeFrame(ui->framesList->currentRow());});
   QObject::connect(this, &SpriteEditorWindow::updateCurrentFrameIndex,
                    model, &SpriteModel::setCurrentFrameIndex);
   QObject::connect(ui->framesList, &QListWidget::itemPressed,
                    this, &SpriteEditorWindow::handleFrameSelection);
   QObject::connect(ui->popOutButton, &QPushButton::pressed,
                    model, &SpriteModel::getImages);
   //QObject::connect(this, &SpriteEditorWindow::mouseReleaseEvent,
                    //model, &SpriteModel::getImages);
   QObject::connect(this, &SpriteEditorWindow::updateAnimation,
                    model, &SpriteModel::updateImages);

   // Listen for signals from model
   QObject::connect(model, &SpriteModel::frameAdded,
                    this, &SpriteEditorWindow::handleAddedFrame);
   QObject::connect(model, &SpriteModel::frameRemoved,
                    this, &SpriteEditorWindow::handleRemovedFrame);
   QObject::connect(model, &SpriteModel::currentFrameUpdated,
                    this, &SpriteEditorWindow::updateFrame);
   QObject::connect(model, &SpriteModel::sendImages,
                    this, &SpriteEditorWindow::receiveImages);



   // We do this here instead of the model constructor because it executes
   // before the signals are connected.

   model->addFrame();
   currentFrameIndex = 0;
   imageIndex = 0;
   fps = 1;
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
    int selectionIndex = ui->framesList->currentRow();
    ui->framesList->takeItem(selectionIndex);

    int newRow = ui->framesList->currentRow();
    emit updateCurrentFrameIndex(newRow);
    updateRemoveButton();
}

void SpriteEditorWindow::updateRemoveButton()
{
    bool isLastFrame = (ui->framesList->count() == 1);
    ui->removeFrameButton->setDisabled(isLastFrame);
}

void SpriteEditorWindow::updateFrame(Frame* newCurrent)
{
    ui->frameLayout->removeWidget(currentFrame);
    ui->frameLayout->addWidget(newCurrent, 0 , 0);
    currentFrame = newCurrent;

    currentFrame->update();
}

void SpriteEditorWindow::handleFrameSelection()
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
    qDebug() << "begin mouse pressed";
    mousePressed = true;
    currentFrame->drawPixel(event->x(),event->y(),penColor);
    //updatePreviewImage();
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

void SpriteEditorWindow::setFps(int newFps)
{
    fps = newFps;
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


    if (popup.images.size() > 1)
    {
        QTimer::singleShot(1000/fps, this, SLOT(updatePreviewImage2()));
    }

    incrementImageIndex();
    qDebug()<<"updatePreviewImage1 end";
}

void SpriteEditorWindow::updatePreviewImage2()
{
    qDebug()<<"updatePreviewImage2 start";
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

    QTimer::singleShot(1000/fps, this, SLOT(updatePreviewImage()));
    incrementImageIndex();
    qDebug()<<"updatePreviewImage2 end";
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




void SpriteEditorWindow::on_popOutButton_clicked()
{
    popup.setFps(fps);
    popup.popupOpen = true;
    popup.show();
    popup.updateImage();

}

void SpriteEditorWindow::receiveImages(QList<QImage> imageList)
{
    qDebug()<<"images received and sent to popup";
    images = imageList;
    popup.setImages(imageList);
}

void SpriteEditorWindow::on_frameRateSlider_sliderMoved(int position)
{
    if (position == 0)
    {
        fps = 1;
    }
    else if (position == 1)
    {
        fps = 2;
    }
    else if (position == 2)
    {
        fps = 4;
    }
    else
    {
        fps = 8;
    }
    emit frameRateSliderMoved(fps);
}
