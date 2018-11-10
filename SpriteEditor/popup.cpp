#include "popup.h"
#include "ui_popup.h"
#include "frame.h"

Popup::Popup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
    //QImage image = currentFrame->getImage();

    QImage image;
    image= QImage(800,800,QImage::Format_RGB32);
    image.fill(qRgba(255 , 5, 5, 10));

    QImage image2;
    image2= QImage(800,800,QImage::Format_RGB32);
    image2.fill(qRgba(5 , 255, 5, 10));

    images.append(image);
    images.append(image2);

    imageIndex = 0;

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
