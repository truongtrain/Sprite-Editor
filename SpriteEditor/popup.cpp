#include "popup.h"
#include "ui_popup.h"
#include "frame.h"

Popup::Popup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
    imageIndex = 0;
    popupOpen = false;
    fpsTimer = new QTimer(this);

    QObject::connect(fpsTimer, &QTimer::timeout,
                    this, &Popup::updateImage);
}

void Popup::start()
{
    fpsTimer->start(1000/fps);
}

void Popup::setImages(QList<QImage> imageList)
{
    images = imageList;
}

void Popup::setFps(int newFps)
{
    fps = newFps;

    if(fpsTimer->isActive())
    {
        fpsTimer->stop();
        fpsTimer->start(1000/fps);
    }
}

void Popup::updateImage()
{
    if (popupOpen == true)
    {
        ui->imageLabel->setPixmap(QPixmap::fromImage(images[imageIndex]));
        ui->imageLabel->show();
	// QTimer::singleShot(1000/fps, this, SLOT(updateImage2()));
        incrementImageIndex();
    }
}

/*
void Popup::updateImage2()
{
    if (popupOpen == true)
    {
        ui->imageLabel->setPixmap(QPixmap::fromImage(images[imageIndex]));
        ui->imageLabel->show();
        QTimer::singleShot(1000/fps, this, SLOT(updateImage()));
        incrementImageIndex();
    }
}
*/

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
    fpsTimer->stop();
    images.clear();
   
}

Popup::~Popup()
{
    delete ui;
}
