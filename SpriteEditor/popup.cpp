#include "popup.h"
#include "ui_popup.h"
#include "frame.h"
#include "QDebug"

Popup::Popup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
    imageIndex = 0;
    popupOpen = false;
}


void Popup::setImages(QList<QImage> imageList)
{

    images = imageList;
}

void Popup::setFps(int newFps)
{
    fps = newFps;
}

void Popup::updateImage()
{
    qDebug() << "popup updateImage() called";
    if (popupOpen == true)
    {
        ui->imageLabel->setPixmap(QPixmap::fromImage(images[imageIndex]));
        ui->imageLabel->show();
        QTimer::singleShot(1000/fps, this, SLOT(updateImage2()));
        incrementImageIndex();
    }
}

void Popup::updateImage2()
{
    qDebug() << "popup updateImage2() called";
    if (popupOpen == true)
    {
        ui->imageLabel->setPixmap(QPixmap::fromImage(images[imageIndex]));
        ui->imageLabel->show();
        QTimer::singleShot(1000/fps, this, SLOT(updateImage()));
        incrementImageIndex();
    }
}

void Popup::incrementImageIndex()
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

void Popup::closeEvent(QCloseEvent *event)
{
    popupOpen = false;
    qDebug()<<"closeEvent invoked";
    images.clear();
    qDebug()<<"closeEvent end";
    /*
    qDebug()<<"images size: " << images.size();
    images.clear();
    qDebug()<<"images size: " << images.size();
    */

}

Popup::~Popup()
{
    delete ui;
}
