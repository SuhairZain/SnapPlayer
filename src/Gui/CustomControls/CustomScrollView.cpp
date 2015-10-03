/*
 * CustomScrollView.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: SuhairZain
 */

#include <src/Gui/CustomControls/CustomScrollView.h>

#include <bb/cascades/PinchEvent>

CustomScrollView::CustomScrollView(Control *root)
{
    skipCounter = 0;

    isHorizontal = isScrolling = isVertical = FALSE;

    lastY = 0;
    startX = startY = 0;
    lastRatio = 1.0f;

    PinchHandler *handler = PinchHandler::create().
            onPinch(this, SLOT(onPinchStarted(/*bb::cascades::PinchEvent**/)),
                    SLOT(onPinchUpdated(bb::cascades::PinchEvent*)),
                    SLOT(onPinchEnded(bb::cascades::PinchEvent*)),
                    SLOT(onPinchCancelled()));

    rootControl = root;
    root->addGestureHandler(handler);
    connect(root, SIGNAL(touch(bb::cascades::TouchEvent*)), this, SLOT(onTouch(bb::cascades::TouchEvent*)));

    setRoot(rootControl);
}

/*int CustomScrollView::getDistance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}*/

void CustomScrollView::onPinchCancelled()
{
    rootControl->setScale(lastRatio);
    isScrolling = FALSE;
}

void CustomScrollView::onPinchEnded(bb::cascades::PinchEvent*)
{
    qDebug()<<"Ended";
    isScrolling = FALSE;

    lastRatio = rootControl->scaleX();
    //rootImage->resetScale();
}

void CustomScrollView::onPinchStarted(/*bb::cascades::PinchEvent**/)
{
    isScrolling = TRUE;
    //qDebug()<<"Started";
}

void CustomScrollView::onPinchUpdated(bb::cascades::PinchEvent* event)
{
    rootControl->setScale(lastRatio*event->pinchRatio());
}

void CustomScrollView::onTouch(bb::cascades::TouchEvent *event)
{
    if(event->isDown())
    {
        startX = event->localX();
        startY = event->localY();

        isHorizontal = isVertical = FALSE;
    }
    else if(event->isMove() && !isScrolling)
    {
        //Forward and backward
        if(isHorizontal)
        {
            if(++skipCounter==30)
            {
                emit seekForward((event->localX() - startX)*50);
                startX = event->localX();
                skipCounter = 0;
            }
        }
        //Up and down, volume
        else if(isVertical)
        {
            emit volumeChanged((lastY - event->localY())/600);
        }
        //None, decide whether to lock to horizontal or vertical
        else
        {
            int distX = abs(startX-event->localX());
            int distY = abs(startY-event->localY());

            if(distX>20)
                isHorizontal = TRUE;
            else if(distY>20)
                isVertical = TRUE;
        }

        //lastY = event->screenY();
    }
    //lastX = event->localX();
    lastY = event->localY();
}

void CustomScrollView::resetControlScale()
{
    rootControl->resetScale();

    lastRatio = 1.0f;
}

void CustomScrollView::setControlScale(float scale)
{
    rootControl->setScale(scale);
    lastRatio = scale;
}
