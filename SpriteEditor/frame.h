#ifndef FRAME_H
#define FRAME_H
#include <QMainWindow>

class Frame
{
    QImage image;
    Frame* nextFrame;
    Frame* previousFrame;
    int currentPixelSize;

public:
    Frame();

    QImage getImage();
    // newSize must be one of these numbers: 1,2,3,4,6,8,9,12,18,24,36
    void setCurrentPixelSize(int newSize);
    int getCurrentPixelSize();

    /**
     * @brief This function returns the current pixel (starting and ending pixel for both x and y of QImage)  that was clicked.
     *  For example, if current size of pixel is 8 and the coordinate (700,900) is clicked,
     * this function will return an array of size 4 looks like this: [696, 703, 896, 903]
     * @param x -x coordinate of the mouse clicked position
     * @param y -y coordinate of the mouse clicked position
     * @return an array - [xStarting, xEnding, yStarting, yEnding]
     */
    int* getPixelOfCoordinates(int x, int y);
};

#endif // FRAME_H
