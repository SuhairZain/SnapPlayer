/*
 * VideoOptionsBar.h
 *
 *  Created on: Aug 22, 2014
 *      Author: SuhairZain
 */

#ifndef VIDEOOPTIONSBAR_H_
#define VIDEOOPTIONSBAR_H_

#include <bb/cascades/CustomControl>

using namespace bb::cascades;

class ZoomLevel
{
public:
    enum Level{ZL1, ZL2, ZL3, ZL0_75, ZL0_5, ZL_LAST};
};

class VideoOptionsBar: public CustomControl
{
Q_OBJECT
signals:
    void backPressed();
    void rotationLock(bool);
    void screenLock(bool);
    void zoomLevelChanged(ZoomLevel::Level);
    void zoomReset();
private slots:
    void onZoomButtonClicked();
public:
    VideoOptionsBar();
private:
    short int zoomLevel;
    //ImageToggleButton *rotationLockButton;
};

#endif /* VIDEOOPTIONSBAR_H_ */
