/*
 * LandscapeImageGridRecentItem.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: SuhairZain
 */

#include <src/Gui/ImageGrid/LandscapeImageGridRecentItem.h>

#include <bb/cascades/Color>
#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>

#include <time.h>

LandscapeImageGridRecentItem::LandscapeImageGridRecentItem()
{
    srand(time(NULL) + rand());
    int multi100 = rand()%20;

    fadeOutTimer.setInterval(4000 + multi100*100);
    //qDebug()<<"Timeout"<<fadeOutTimer.interval();
    connect(&fadeOutTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    imageMaxIndex = imagePointer = 0;

    image = ImageView::create().
            image("asset:///images/placeholder.jpg").
            scalingMethod(ScalingMethod::AspectFill);

    Container *BG = Container::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Bottom).
            preferredHeight(75.0f).
            background(Color::fromARGB(0xffae734b)).
            opacity(0.6f);

    duration = Label::create().
            horizontal(HorizontalAlignment::Right).
            text("0:00:22");
    duration->textStyle()->setColor(Color::White);
    duration->textStyle()->setFontSize(FontSize::PointValue);
    duration->textStyle()->setFontSizeValue(5.0f);

    fileName = Label::create().
            text("File's name");
    fileName->textStyle()->setColor(Color::White);
    fileName->textStyle()->setFontSize(FontSize::PointValue);
    fileName->textStyle()->setFontSizeValue(5.0f);

    Container *textC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Bottom).
            left(6.0f).
            add(duration).
            add(fileName);

    rootC = Container::create().
            bottomMargin(6.0f).
            layout(DockLayout::create()).
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            add(image).
            add(BG).
            add(textC);
    setRoot(rootC);

    fadeOut = FadeTransition::create(rootC).
            parent(rootC).
            duration(50).
            to(0.0f);
    connect(fadeOut, SIGNAL(ended()), this, SLOT(fadeOutCompleted()));
}

void LandscapeImageGridRecentItem::fadeOutCompleted()
{
    image->setImage(Image(imageRoot + QString::number(imagePointer) + ".jpg"));
    rootC->setOpacity(1.0f);

    if(++imagePointer>imageMaxIndex)
        imagePointer = 0;
}

void LandscapeImageGridRecentItem::onTimeout()
{
    fadeOut->play();

    int multi100 = rand()%20;
    fadeOutTimer.start(4000 + multi100*100);
}

void LandscapeImageGridRecentItem::setAnimationsEnabled(bool enable)
{
    if(enable)
        fadeOutTimer.start((rand()%20)*50);
    else
        fadeOutTimer.stop();
}

void LandscapeImageGridRecentItem::setImage(QString imageRootPath, QString name, int dur)
{
    imageRoot = imageRootPath;
    imageMaxIndex = 3;
    imagePointer = 0;
    fileName->setText(name);

    QString h = QString::number(dur/3600);
    dur %= 3600;
    QString m = QString::number(dur/60);
    if(m.length()==1)
        m = m.prepend('0');
    dur %= 60;
    QString s = QString::number(dur);
    if(s.length()==1)
        s = s.prepend('0');
    duration->setText(h + ":" + m + ":" + s);

    /*fadeOutCompleted();
    fadeOutTimer.start();*/
    onTimeout();
}
