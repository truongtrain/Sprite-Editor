#ifndef SPRITEEDITORWINDOW_H
#define SPRITEEDITORWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

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
    QColor color;
};

#endif // SPRITEEDITORWINDOW_H
