#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"
#include "drawarea.h"

#include <QtWidgets>

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    // QPainter is best used to draw on widgets so we create our own
    drawArea = new DrawArea;
    ui->setupUi(this);

    // Parameters are (widgetToAdd, row, column, alignment) alignment defaults to filling whole layout.
    ui->drawLayout->addWidget(drawArea, 0, 0);
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete drawArea;
    delete ui;
}
