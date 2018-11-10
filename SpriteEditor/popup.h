#ifndef POPUP_H
#define POPUP_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Popup;
}

class Popup : public QWidget
{
    Q_OBJECT

public:
    explicit Popup(QWidget *parent = nullptr);
    ~Popup();
    void setImages(QList<QImage> imageList);

public slots:
    void updateImage();
    void updateImage2();

private:
    Ui::Popup *ui;
    QList<QImage> images;
    int imageIndex;
    void incrementImageIndex();

};

#endif // POPUP_H
