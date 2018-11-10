#ifndef SPRITEEDITORWINDOW_H
#define SPRITEEDITORWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QMouseEvent>
#include <QDebug>
#include "frame.h"
#include "spritemodel.h"
#include <QSignalMapper>

namespace Ui {
class SpriteEditorWindow;
}

class SpriteEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpriteEditorWindow(QWidget *parent = nullptr, SpriteModel *model = new SpriteModel());
    ~SpriteEditorWindow();

signals:
    void updateCurrentFrameIndex(int index);
    void addInitialFrameSignal(Frame* frame);
    void resolutionSliderMovedSignal(int value);
    void drawMirroredBoxChangedSignal(bool checked);



private slots:
    void on_chooseColorBox_clicked();
    /**
     * Updates the frame list with the new frame and naming it
     * based on how many frames there are
     */
void updateFrameList(int frameIndex);

void on_resolutionSlider_sliderMoved(int position);

void on_drawMirrorCheckBox_toggled(bool checked);

private:
    Ui::SpriteEditorWindow *ui;
    QColor penColor;
    Frame* myFrame;
    int lastXPosition;
    int lastYPostion;
    bool mousePressed;

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

};

#endif // SPRITEEDITORWINDOW_H
