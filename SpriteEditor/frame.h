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
    Frame(const Frame &other);
    ~Frame() override;
    Frame &operator= (Frame other);
    //void drawGrid();
    QImage& getImage();
    void setCurrentPixelSize(int newSize);
    int getCurrentPixelSize();
    void drawPixel(int x, int y, QColor color);
    /**
     * @brief This function returns the current pixel (starting and ending pixel for both x and y of QImage)  that was clicked.
     *  For example, if current size of pixel is 8 and the coordinate (700,900) is clicked,
     * this function will return an array of size 4 looks like this: [696, 703, 896, 903]
     * @param x -x coordinate of the mouse clicked position
     * @param y -y coordinate of the mouse clicked position
     * @return an array - [xStarting, xEnding, yStarting, yEnding]
     */
    int* getPixelAtCoordinates(int x, int y);


public slots:
    void changeResolution(int newPixelSize);
    void setDrawMirrored(bool checked);

protected:
    void paintEvent (QPaintEvent *event) override;
};

#endif // FRAME_H
