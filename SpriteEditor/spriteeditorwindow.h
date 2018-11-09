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

public slots:
    void on_chooseColorBox_clicked();
    void handleRemovedFrame();
    void handleAddedFrame();

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
