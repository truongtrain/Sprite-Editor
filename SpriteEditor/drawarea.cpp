#include "drawarea.h"

#include <QPainter>

DrawArea::DrawArea(QWidget *parent)
    : QWidget(parent)
{
    pixelSize = 60;
}

// Gets called when update() is called
void DrawArea::paintEvent(QPaintEvent *) {
    // Create a painter
    QPainter painter(this);
    QBrush brush(Qt::red);
    painter.setBrush(brush);

    // The +5 is to separate squares for demonstration purposes.
    for(int y = 20; y < 150; y += pixelSize + 5) {
        for(int x = 10; x < 150; x += pixelSize + 5) {
            QRect rect(x, y, pixelSize, pixelSize);
            painter.fillRect(rect, brush);
        }
    }

}
