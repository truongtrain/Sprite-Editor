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
#include <QSignalMapper>
#include <QKeyEvent>

namespace Ui {
class SpriteEditorWindow;
}

class SpriteEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpriteEditorWindow(QWidget *parent = nullptr, SpriteModel *model = new SpriteModel());
    ~SpriteEditorWindow() override;
    QList<QImage> images;

signals:
    void updateCurrentFrameIndex(int index);
    void frameRemoved(int removedIndex, int newIndex);
    void resolutionSliderMovedSignal(int value);
    void drawMirroredBoxChangedSignal(bool checked);

    void updateAnimation(int index, QImage& image);
    void frameRateSliderMoved(int newFps);

    void itemSwapped(int index, bool isDown);


public slots:
    void on_chooseColorBox_clicked();
    void handleAddedFrame(int framesMade);

    //void handleDuplicatedFrame(int originalIndex);
    //void updateFrame(Frame& current);

    void updatePreviewImage();
    void receiveImages(QList<QImage> images);

    void handleDuplicatedFrame();
    void updateFrame(Frame* current);

    void on_resolutionSlider_sliderMoved(int position);
    void on_drawMirrorCheckBox_toggled(bool checked);

private:
    Ui::SpriteEditorWindow *ui;
    QColor penColor;
    Frame* currentFrame;
    int lastXPosition;
    int lastYPostion;
    int currentFrameIndex;
    int imageIndex;
    bool mousePressed;

    Popup popup;
    int fps;
    void updateRemoveButton();
    void incrementImageIndex();
    QTimer *previewTimer;

    void updateButtonsToDisable();


protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void handleRemovedFrame();
    void handleItemClicked();
    void on_popOutButton_clicked();
    void on_frameRateSlider_sliderMoved(int position);
    void swapItem(bool isDown);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

};

#endif // SPRITEEDITORWINDOW_H
