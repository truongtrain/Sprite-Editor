#include "popup.h"
#include "ui_popup.h"
#include "frame.h"

Popup::Popup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
    //QImage image = currentFrame->getImage();

    //QTimer *timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(updateImage()));
    //timer->start(2000);



    //QTimer::singleShot(3000, this, SLOT(updateImage()));
    //QTimer::singleShot(6000, this, SLOT(updateImage2()));
}

void Popup::updateImage()
{
    QImage image;
    image= QImage(800,800,QImage::Format_RGB32);
    image.fill(qRgba(255 , 5, 5, 10));

    QImage image2;
    image2= QImage(800,800,QImage::Format_RGB32);
    image2.fill(qRgba(5 , 255, 5, 10));

    QList<QImage> images;
    images.append(image);
    images.append(image2);

    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    ui->imageLabel->show();
    QTimer::singleShot(3000, this, SLOT(updateImage2()));

}

void Popup::updateImage2()
{
    QImage image;
    image= QImage(800,800,QImage::Format_RGB32);
    image.fill(qRgba(255 , 5, 5, 10));

    QImage image2;
    image2= QImage(800,800,QImage::Format_RGB32);
    image2.fill(qRgba(5 , 255, 5, 10));

    QList<QImage> images;
    images.append(image);
    images.append(image2);

    ui->imageLabel->setPixmap(QPixmap::fromImage(image2));
    ui->imageLabel->show();
    QTimer::singleShot(3000, this, SLOT(updateImage()));

}

Popup::~Popup()
{
    delete ui;
}
