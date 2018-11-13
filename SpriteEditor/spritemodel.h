#ifndef SPRITEMODEL_H
#define SPRITEMODEL_H

#include <QMainWindow>
#include <vector>
#include <cmath>
#include "frame.h"



class SpriteModel : public QObject
{
    Q_OBJECT

private:
    QList<QImage> images;
    std::vector<Frame*> frames;
    int currentFrameIndex;
    int frameRate;
    int framesMade;
    int currentPixelSize = 25;
    bool isDrawMirroredChecked = false;
    //const int GRID_RESOLUTION = 800;

    void adjustToAvailableFrame(int index);

public:
    SpriteModel();
    ~SpriteModel();
signals:
    // Lets view know a frame was added and gives it the count of frames
    void frameAdded(int count);
    void frameDuplicated(int index);
    void currentFrameUpdated(Frame& current);
    void sendImages(QList<QImage> images);

public slots:
    /**
     * Adds a blank frame to the list then tells the view to update
     * its corresponding list.
     */
    void addFrame();
    void changeResolutionOfAllFrames(int value);
    void setDrawMirrored(bool checked);
    void exportGif();


    /**
     * Removes the frame at the selected index. Guranteed that
     * 2 or more frames exist when called.
     */
    void removeFrame(int removedIndex, int newIndex);

    /**
     * Adds a frames based on a given index, then tells the view
     * to update its corresponding list.
     */
    void duplicateFrame(int index);

    /**
     * Updates the current index to whatever the list defaulted to after
     * an item was removed.
     */
    void setCurrentFrameIndex(int selectedIndex);

    void getImages();

    void updateImages(int index, QImage& image);


};

#endif // SPRITEMODEL_H
