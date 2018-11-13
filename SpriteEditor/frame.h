#ifndef FRAME_H
#define FRAME_H
#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <QRgba64>
#include <QWidget>

class Frame : public QWidget
{
    Q_OBJECT

struct PixelCoordinates
{
public:
    int xStarting, xEnding, yStarting, yEnding;
    PixelCoordinates(int xStarting, int xEnding, int yStarting, int yEnding);
};

private:
    QImage image;
    int currentPixelSize;
    bool isDrawingMirrored;
    const int GRID_RESOLUTION = 800;
    QColor colorGrid[32][32];
    int currentXCoord;
    int currentYCoord;
    QColor currentColor;

    void saveColor(int x, int y, QColor color);
    //const QRgba64 BACKGROUND_COLOR = qRgba64(160 , 160, 160, 10);

public:
    Frame(QWidget *parent = nullptr, bool isDrawingMirroredChecked = false);
    Frame(const Frame &other, bool isDrawingMirroredChecked = false);
    ~Frame() override;
    Frame &operator= (Frame other);
    QImage& getImage();
    void setCurrentPixelSize(int newSize);
    int getCurrentPixelSize();
    void drawPixel(int x, int y, QColor color);
    /**
     *  Returns an object with the boundaries of whatever pixel x, y are inside of.
     */
    PixelCoordinates getPixelAtCoordinates(int x, int y);


public slots:
    void changeResolution(int newPixelSize);
    void setDrawMirrored(bool checked);

protected:
    void paintEvent (QPaintEvent *event) override;
};

#endif // FRAME_H
