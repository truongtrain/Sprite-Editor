#include "spriteeditorwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpriteEditorWindow w;
    w.show();

    return a.exec();
}
