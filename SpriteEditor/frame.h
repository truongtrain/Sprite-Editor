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
    //Frame* nextFrame;
   // Frame* previousFrame;
    int currentPixelSize;
    const int GRID_RESOLUTION = 800;
    QColor colorGrid[32][32];

    int currentXCoord;
    int currentYCoord;
    QColor currentColor;
    void saveColor(int x, int y, QColor color);

    // Theses 4 variablies are for moving pixels
    bool isPixelSelected;
    int currentSelectedX;
    int currentSelectedY;

    QColor selectedColor;


public:
    int whichArrow;
    Frame(QWidget *parent = 0);
    //void drawGrid();
    QImage& getImage();
    // newSize must be one of these numbers: 1,2,3,4,6,8,9,12,18,24,36
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

    // These are for moving pixels


    void setIsPixelSelected(bool input);
    void setCurrentSelectedX(int input);
    void setCurrentSelectedY(int input);
    void setSelectedColor(QColor input);


    bool getIsPixelSelected();
    int getCurrentSelectedX();
    int getCurrentSelectedY();
    QColor getSelectedColor();

    void shiftPixel(int x, int y, QColor color);

    void setOldPixelPosToGray(int x, int y);


protected:
    void paintEvent (QPaintEvent *event) override;
};

#endif // FRAME_H
