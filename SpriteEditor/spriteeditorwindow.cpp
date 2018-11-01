#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    ui->setupUi(this);
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}
