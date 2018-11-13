#include "spritemodel.h"
#include <QDebug>

SpriteModel::SpriteModel()
{

}


SpriteModel::~SpriteModel()
{

}


void SpriteModel::changeResolution(int res)
{
    res++;
}

void SpriteModel::addFrame()
{



    //add image
    QImage image;
    image= QImage(960,960,QImage::Format_RGB32);

    image.fill(qRgba(160 , 160, 160, 10));
    images.append(image);
    int frameCount = int(images.size());
    currentFrameIndex = frameCount - 1;
    emit frameChanged(frameCount);

}

void SpriteModel::removeFrame(int selectedIndex)
{
    int frameCount = int(images.size());

    // Adjust index since we have to add this to the begin() iterator
    selectedIndex = selectedIndex - 1;
    images.removeAt(selectedIndex);
    emit frameChanged(frameCount);

}

void SpriteModel::setCurrentFrameIndex(int selectedIndex)
{
    currentFrameIndex = selectedIndex;
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
          outStream << "1" << '\n';

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

    QTextStream in(&f);

    QString line = in.readLine();
    QStringList fields = line.split(" ");
    int currentPixelSize = fields[0].toInt();
    int numberOfFrames = in.readLine().toInt();


    
    for (int frame = 0; frame < numberOfFrames; frame++)
    {
        current = new Frame();

        for (int row = 0; row < GRID_RESOLUTION; row = row + currentPixelSize)
        {
            int index = 0;
            for (int column = 0; column < GRID_RESOLUTION; column = column + currentPixelSize)
            {
                QColor color;
                QStringList colorLine = in.readLine().split(" ");

                color.setRed(colorLine[index].toInt());
                color.setGreen(colorLine[index+1].toInt());
                color.setBlue(colorLine[index+2].toInt());
                color.setAlpha(colorLine[index+3].toInt());

                index += 4;

                current->drawPixel(row * currentPixelSize, column * currentPixelSize, color);
            }
        }

        frames.push_back(current);
    }
    
}




