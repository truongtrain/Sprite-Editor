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
    QList<QImage> images;
    bool popupOpen;
    explicit Popup(QWidget *parent = nullptr);
    ~Popup();
    void setImages(QList<QImage> imageList);
    void start();

public slots:
    void updateImage();
    void updateImage2();
    void setFps(int newFps);

private:
    Ui::Popup *ui;
    int fps;
    int imageIndex;
    void incrementImageIndex();
    QTimer *fpsTimer;


protected:
    void closeEvent(QCloseEvent *event) override;

};

#endif // POPUP_H
