#include "popup.h"
#include "ui_popup.h"
#include "frame.h"

Popup::Popup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
    imageIndex = 0;

}

void Popup::setImages(QList<QImage> imageList)
{
    images = imageList;
}

void Popup::updateImage()
{
    ui->imageLabel->setPixmap(QPixmap::fromImage(images[imageIndex]));
    ui->imageLabel->show();
    QTimer::singleShot(1000, this, SLOT(updateImage2()));
    incrementImageIndex();
}

void Popup::updateImage2()
{
    ui->imageLabel->setPixmap(QPixmap::fromImage(images[imageIndex]));
    ui->imageLabel->show();
    QTimer::singleShot(1000, this, SLOT(updateImage()));
    incrementImageIndex();
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

Popup::~Popup()
{
    delete ui;
}