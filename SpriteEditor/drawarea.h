#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QPen>
#include <QWidget>

class DrawArea : public QWidget
{
    Q_OBJECT

private:
    int pixelSize;
public:
    DrawArea(QWidget *parent = 0);

protected:
    // Overrides QWidget's paint event to implement our own
    void paintEvent(QPaintEvent *event) override;
};

#endif // DRAWAREA_H
