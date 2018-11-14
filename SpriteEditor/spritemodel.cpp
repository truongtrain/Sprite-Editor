#include "spritemodel.h"
#include "gif.h"
#include <QDebug>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>

SpriteModel::SpriteModel()
{
    framesMade = 0;
}

SpriteModel::~SpriteModel()
{
   for(int i = 0; i < frames.size(); i++)
   {
       delete frames[i];
   }
   frames.clear();
}

void SpriteModel::addFrame()
{
   // Frame newFrame;
    frames.push_back(new Frame(nullptr,isDrawMirroredChecked));

    // Adding a frame switches focus to that new frame
    framesMade++;
    images.append(QPixmap().toImage());
    emit sendImages(images);
    emit frameAdded(framesMade);

    frames[frames.size()-1]->changeResolution(currentPixelSize);
}

void SpriteModel::removeFrame(int removedIndex, int newIndex)
{
    //delete frames.at(removedIndex);
    //frames.erase(frames.begin() + removedIndex);
    //setCurrentFrameIndex(newIndex);
    images.removeAt(removedIndex);
    emit sendImages(images);
    delete frames[removedIndex];
    frames.removeAt(removedIndex);
    setCurrentFrame(newIndex);
}

void SpriteModel::duplicateFrame(int index)
{
    //Frame* original = frames.at(index);

    //int newIndex = index + 1;
    //frames.insert(frames.begin() + newIndex, copy);

    //emit frameDuplicated(index);
    Frame* original = frames[index];
    //Frame* copy = new Frame(*original);
    Frame* copy = new Frame(*original,isDrawMirroredChecked);

    int newIndex = index + 1;
    images.insert(newIndex, copy->getImage());
    frames.insert(newIndex, copy);

    framesMade++;

    emit sendImages(images);
    emit frameDuplicated();
}

void SpriteModel::setCurrentFrame(int selectedIndex)
{
    qDebug() << "Frame Index: " << selectedIndex;
    emit currentFrameUpdated(frames[selectedIndex]);
}

void SpriteModel::changeResolutionOfAllFrames(int value)
{
    std::cout << "frames.size() = " << frames.size() << std::endl;

    int scaleFactor = std::pow(2, value);
    int newPixelSize = 200/scaleFactor;

    currentPixelSize = newPixelSize;

    for (int i = 0; i < frames.size(); i++)
    {
        frames[i]->changeResolution(newPixelSize);
        std::cout << "telling frame " << i << " to update res" << std::endl;
    }
}

void SpriteModel::swapItem(int currentIndex, int newIndex)
{
    std::swap(frames[currentIndex], frames[newIndex]);

    setCurrentFrame(newIndex);
}

void SpriteModel::setDrawMirrored(bool checked)
{
    isDrawMirroredChecked = checked;
    //for (unsigned long i = 0; i < frames.size(); i++)

    for (int i = 0; i < frames.size(); i++)
        frames[i]->setDrawMirrored(checked);
}

void SpriteModel::getImages()
{
    qDebug() << "images sent";
    //updateImages(currentFrameIndex, images[currentFrameIndex]);
    qDebug() << "line 109";
    emit sendImages(images);
}

void SpriteModel::updateImages(int index, QImage& image)
{
    qDebug() << "image " << index << " updated";
    images[index] = image;
    emit sendImages(images);
}

void SpriteModel::save(QString fileName)
{
    QFile f( fileName );
    int currentPixelSize = frames[0]->getCurrentPixelSize();
    if ( f.open(QIODevice::WriteOnly) )
    {
        QTextStream outStream( &f );

    // store data in f

//       /* Write the line to the file */
          outStream << GRID_RESOLUTION/currentPixelSize << " " << GRID_RESOLUTION/currentPixelSize << '\n';
          outStream << frames.size() << '\n';

          for (int frame = 0; frame < frames.size(); frame++)
          {
              QImage image = frames[frame]->getImage();

        for ( int y = 10; y < image.height(); y = y + currentPixelSize )
        {
                for ( int x = 10; x < image.width(); x = x + currentPixelSize )
                {
                    QColor clrCurrent( image.pixel( x, y ));

                    int red = clrCurrent.red();
                    int green = clrCurrent.green();
                    int blue = clrCurrent.blue();
                    int alpha = clrCurrent.alpha();

                    if (red == 160 && green == 160 && blue == 160 && alpha == 255)
                    {
                        red = 0;
                        green = 0;
                        blue = 0;
                        alpha = 0;
                    }

                    outStream << red << " " << green << " " <<
                    blue << " " << alpha << " ";
                }

            outStream << "\n";
        }
       }
    }

    f.close();
}

void SpriteModel::load(QString fileName)
{
    QFile f(fileName);

    // Stop the timer

    frames.clear();

    qDebug() << "In load.";

    if ( f.open(QIODevice::ReadOnly) )
    {
        qDebug() << "In if statement.";
    QTextStream in(&f);

    QString line = in.readLine();
    QStringList fields = line.split(" ");
    int currentPixelSize = GRID_RESOLUTION/fields[0].toInt();
    int numberOfFrames = in.readLine().toInt();

    for (int frame = 0; frame < numberOfFrames; frame++)
    {
        current = new Frame();

        for (int row = 15; row < GRID_RESOLUTION; row = row + currentPixelSize)
        {
            int index = 0;
            QStringList colorLine = in.readLine().split(" ");
            for (int column = 30; column < GRID_RESOLUTION; column = column + currentPixelSize)
            {
                QColor color;


                color.setRed(colorLine[index].toInt());
                color.setGreen(colorLine[index+1].toInt());
                color.setBlue(colorLine[index+2].toInt());
                color.setAlpha(colorLine[index+3].toInt());

                index += 4;

                current->drawPixel(column, row, color);

                qDebug() << current->getImage().pixelColor(row, column);
            }
        }

        frames.push_back(current);
        qDebug() << "pushed back.";

    }
    qDebug() << frames.size();
     setCurrentFrame(frames.size() - 1);

    }

}

void SpriteModel::exportGif()
{
        QString fileName = QFileDialog::getSaveFileName(NULL, "Spawn to", "", "GIF image (*.gif)");


        if(!fileName.isEmpty())
        {
            uint32_t frameSpeed = 100 / 2; // Half of second per frame

            QImage &startImg = frames[0]->getImage();

            GifWriter writer;

            GifBegin(&writer, fileName.toUtf8().constData(), (uint32_t)startImg.width(), (uint32_t)startImg.height(), frameSpeed);


            for (Frame *currentFrame : frames)
            {
                QImage currentImage = currentFrame->getImage().rgbSwapped();


                QByteArray alpha8((char *)currentImage.bits(), currentImage.byteCount());


                GifWriteFrame(&writer, (uint8_t *)alpha8.data(), currentImage.width(), currentImage.height(), frameSpeed);
            }

            GifEnd(&writer);

            QMessageBox::information(NULL, "Done!", QString("GIF Image has been wrote!"));
        }
}
