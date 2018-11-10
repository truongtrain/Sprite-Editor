#ifndef SPRITEEDITORWINDOW_H
#define SPRITEEDITORWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QMouseEvent>
#include <QDebug>
#include <QListWidget>
#include "frame.h"
#include "spritemodel.h"


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
    void frameRemoved(int removedIndex, int newIndex);
    void resolutionSliderMovedSignal(int value);
    void drawMirroredBoxChangedSignal(bool checked);

public slots:
    void on_chooseColorBox_clicked();
    void handleAddedFrame(int framesMade);
    void handleDuplicatedFrame(int originalIndex);
    void updateFrame(Frame& current);

void on_resolutionSlider_sliderMoved(int position);
void on_drawMirrorCheckBox_toggled(bool checked);

private:
    Ui::SpriteEditorWindow *ui;
    QColor penColor;
    Frame* currentFrame;
    int lastXPosition;
    int lastYPostion;
    bool mousePressed;

    void updateRemoveButton();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void handleRemovedFrame();
    void handleItemClicked();
};

#endif // SPRITEEDITORWINDOW_H
