/*
 * CustomScrollView.h
 *
 *  Created on: Aug 25, 2014
 *      Author: SuhairZain
 */

#ifndef CUSTOMSCROLLVIEW_H_
#define CUSTOMSCROLLVIEW_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/PinchHandler>
#include <bb/cascades/TouchEvent>

using namespace bb::cascades;

class CustomScrollView: public CustomControl
{
Q_OBJECT
signals:
    void seekForward(int);
    void volumeChanged(float);
private slots:
    void onPinchCancelled();
    void onPinchEnded(bb::cascades::PinchEvent*);
    void onPinchStarted(/*bb::cascades::PinchEvent**/);
    void onPinchUpdated(bb::cascades::PinchEvent*);
    void onTouch(bb::cascades::TouchEvent*);
public:
    CustomScrollView(Control*);
    void resetControlScale();
    void setControlScale(float);
private:
    //int getDistance(int, int, int, int);
    unsigned int skipCounter;

    bool isHorizontal, isScrolling, isVertical;
    float lastRatio;
    int lastY;//, lastX;
    int startX, startY;
    Control *rootControl;
};

#endif /* CUSTOMSCROLLVIEW_H_ */
