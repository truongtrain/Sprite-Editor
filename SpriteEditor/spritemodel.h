#ifndef SPRITEMODEL_H
#define SPRITEMODEL_H

#include <QMainWindow>
#include <vector>
#include "frame.h"


class SpriteModel : public QObject
{
    Q_OBJECT

private:
    QList<QImage> images;
    std::vector<Frame*> frames;
    int currentFrameIndex;
    int frameRate;
    const int GRID_RESOLUTION = 960;
    void adjustToAvailableFrame(int index);
    Frame* current;

public:
    SpriteModel();
    ~SpriteModel();
    void changeResolution(int res);

signals:
    // Lets view know a frame was added and gives it the count of frames
    void frameChanged(int count);

public slots:
    /**
     * Adds a blank frame to the list then tells the view to update
     * its corresponding list.
     */
    void addFrame();

    /**
     * Removes the frame at the selected index. Guranteed that
     * 2 or more frames exist when called.
     */
    void removeFrame(int selectedIndex);

    /**
     * Updates the current index to whatever the list defaulted to after
     * an item was removed.
     */
    void setCurrentFrameIndex(int selectedIndex);

    void save(QString fileName);
    
    void load(QString fileName);

};

#endif // SPRITEMODEL_H
