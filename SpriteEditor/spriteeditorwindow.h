#ifndef SPRITEEDITORWINDOW_H
#define SPRITEEDITORWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QMouseEvent>
#include <QDebug>
#include <QListWidget>
#include "frame.h"
#include "spritemodel.h"
#include "popup.h"

namespace Ui {
class SpriteEditorWindow;
}

class SpriteEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpriteEditorWindow(QWidget *parent = nullptr, SpriteModel *model = new SpriteModel());
    ~SpriteEditorWindow() override;

signals:
    void updateCurrentFrameIndex(int index);
    void updateAnimation(int index, QImage& image);

public slots:
    void on_chooseColorBox_clicked();
    void handleRemovedFrame();
    void handleAddedFrame(int framesMade);
    void updateFrame(Frame* current);
    void updatePreviewImage();
    void sendImagesToPopup(QList<QImage> images);


private:
    Ui::SpriteEditorWindow *ui;
    QColor penColor;
    Frame* currentFrame;
    int lastXPosition;
    int lastYPostion;
    int currentFrameIndex;
    bool mousePressed;
    Popup popup;
    void updateRemoveButton();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void handleFrameSelection();
    void on_popOutButton_clicked();
};

#endif // SPRITEEDITORWINDOW_H
