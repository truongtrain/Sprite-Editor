#include "spriteeditorwindow.h"
#include "spritemodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD
    SpriteModel *m = new SpriteModel();
    SpriteEditorWindow w(nullptr, m);
    w.show();
=======
    SpriteEditorWindow* w = new SpriteEditorWindow(nullptr, new SpriteModel());
    w->show();
>>>>>>> master

    return a.exec();
}
