/*
 * ImageGridItem.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: SuhairZain
 */

#include <src/Gui/ImageGrid/ImageGridItem.h>

#include <time.h>

ImageGridItem::ImageGridItem()
{
    fileNameLabel = Label::create().
            text("File's name");
    fileNameLabel->textStyle()->setColor(Color::White);
    fileNameLabel->textStyle()->setFontSize(FontSize::PointValue);
    fileNameLabel->textStyle()->setFontSizeValue(5.0f);

    durationLabel = Label::create().
            text("0:00:22");
    durationLabel->textStyle()->setColor(Color::White);
    durationLabel->textStyle()->setFontSize(FontSize::PointValue);
    durationLabel->textStyle()->setFontSizeValue(5.0f);

    animationsActive = FALSE;

    imageMaxIndex = imagePointer = 0;

    srand(time(NULL) + rand());
    int multi100 = rand()%20;

    fadeOutTimer.setInterval(4000 + multi100*100);
    connect(&fadeOutTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    image = ImageView::create().
            image("asset:///images/placeholder.jpg");

    fadeOut = FadeTransition::create(image).
            parent(image).
            duration(50).
            to(0.0f);
    connect(fadeOut, SIGNAL(ended()), this, SLOT(fadeOutCompleted()));
}

void ImageGridItem::activate(bool activate)
{
    if(activate)
        image->setOpacity(0.5f);
    else
        image->setOpacity(1.0f);

    //select(activate);
}

void ImageGridItem::fadeOutCompleted()
{
    image->setOpacity(1.0f);
    image->setImage(Image(imageRoot + QString::number(imagePointer) + ".jpg"));

    if(++imagePointer>imageMaxIndex)
        imagePointer = 0;
}

void ImageGridItem::onTimeout()
{
    fadeOut->play();

    int multi100 = rand()%20;
    fadeOutTimer.start(4000 + multi100*100);
}

void ImageGridItem::reset(bool, bool)
{
}

void ImageGridItem::select(bool)
{
}

void ImageGridItem::setAnimationsEnabled(bool enable)
{
    if(enable)
        fadeOutTimer.start((rand()%20)*50);
    else
        fadeOutTimer.stop();
}

void ImageGridItem::updateItem(QString fileName, int dur, int count, bool animActive)
{
    videoPath = fileName;
    imageRoot = QDir::homePath() + "/" + fileName + "/";

    //qDebug()<<vidPath<<imageRoot;
    imageMaxIndex = count-1;
    imagePointer = 0;
    fileNameLabel->setText(fileName);

    QString h = QString::number(dur/3600);
    dur %= 3600;
    QString m = QString::number(dur/60);
    if(m.length()==1)
        m = m.prepend('0');
    dur %= 60;
    QString s = QString::number(dur);
    if(s.length()==1)
        s = s.prepend('0');
    durationLabel->setText(h + ":" + m + ":" + s);

    if(animActive && !animationsActive)
        setAnimationsEnabled(TRUE);
    else if(!animActive && animationsActive)
        setAnimationsEnabled(FALSE);
}
