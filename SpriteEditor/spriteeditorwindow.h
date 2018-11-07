#ifndef SPRITEEDITORWINDOW_H
#define SPRITEEDITORWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QMouseEvent>
#include <QDebug>
#include "frame.h"

namespace Ui {
class SpriteEditorWindow;
}

class SpriteEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpriteEditorWindow(QWidget *parent = nullptr);
    ~SpriteEditorWindow();

private slots:
    void on_chooseColorBox_clicked();

private:
    Ui::SpriteEditorWindow *ui;
    QColor penColor;
    Frame* myFrame;
    int lastXPosition;
    int lastYPostion;

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

};

#endif // SPRITEEDITORWINDOW_H
