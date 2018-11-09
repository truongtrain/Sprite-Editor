#include "spriteeditorwindow.h"
#include "spritemodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpriteEditorWindow* w = new SpriteEditorWindow(nullptr, new SpriteModel());
    w->show();

    return a.exec();
}
