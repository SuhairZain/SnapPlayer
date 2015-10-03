/*
 * CustomSlider.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: SuhairZain
 */

#include <src/Gui/CustomControls/CustomSlider.h>

#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>

#define skipCount 20

CustomSlider::CustomSlider(int w): width(w)
{
    skipCounter = 0;

    indicator = ProgressIndicator::create().
            implicitLayoutAnimations(FALSE).
            preferredWidth(w).
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            state(ProgressIndicatorState::Pause).
            from(0).
            to(100).
            value(0);

    mover = ImageView::create().
            vertical(VerticalAlignment::Center).
            image("asset:///images/icons/mover.png").
            connect(SIGNAL(translationXChanging(float)), this, SLOT(onTranslationXChanging(float)));
    //connect(mover, SIGNAL(tra))

    Container *rootC = Container::create().
            layout(DockLayout::create()).
            add(indicator).
            add(mover).
            onTouch(this, SLOT(onTouch(bb::cascades::TouchEvent*)));
    setRoot(rootC);
}

void CustomSlider::setScreenWidth(int newWidth)
{
    width = newWidth;
    indicator->setPreferredWidth(newWidth);
}

void CustomSlider::onTouch(bb::cascades::TouchEvent *event)
{
    //0 for normal pos, width for extreme
    if(event->isMove())
    {
        int x = event->localX();
        if(x>0 && x<width)
        {
            if(++skipCounter==skipCount)
            {
                skipCounter = 0;
                emit valueChanged(float(x)/float(width));
                mover->setTranslationX(x);
            }
        }
        else if(x<0)
        {
            if(++skipCounter==skipCount)
            {
                skipCounter = 0;
                emit valueChanged(0);
                mover->setTranslationX(0);
            }
        }
        else if(x>width)
        {
            if(++skipCounter==skipCount)
            {
                skipCounter = 0;
                emit valueChanged(1);
                mover->setTranslationX(width);
            }
        }
    }
    else if(event->isDown())
    {
        mover->setImage("asset:///images/icons/moverPressed.png");
        int x = event->localX();
        if(x>0 && x<width)
        {
            emit valueChanged(float(x)/float(width));
            mover->setTranslationX(x);
        }
        else if(x<0)
        {
            emit valueChanged(0);
            mover->setTranslationX(0);
        }
        else if(x>width)
        {
            emit valueChanged(1);
            mover->setTranslationX(width);
        }
    }
    else if(event->isCancel() || event->isUp())
        mover->setImage("asset:///images/icons/mover.png");
}

void CustomSlider::onTranslationXChanging(float x)
{
    indicator->setValue(x*100/width);
}

void CustomSlider::setValue(float perc)
{
    mover->setTranslationX(width*perc);
}
