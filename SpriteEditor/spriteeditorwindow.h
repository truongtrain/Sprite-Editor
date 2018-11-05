#ifndef SPRITEEDITORWINDOW_H
#define SPRITEEDITORWINDOW_H

#include <QMainWindow>

class DrawArea;

namespace Ui {
class SpriteEditorWindow;
}

class SpriteEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpriteEditorWindow(QWidget *parent = nullptr);
    ~SpriteEditorWindow();

private:
    Ui::SpriteEditorWindow *ui;
    DrawArea *drawArea;
};

#endif // SPRITEEDITORWINDOW_H
