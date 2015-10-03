/*
 * VideoOptionsBar.cpp
 *
 *  Created on: Aug 22, 2014
 *      Author: SuhairZain
 */

#include <bb/cascades/Container>
#include <bb/cascades/ImageButton>
#include <bb/cascades/ImageToggleButton>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>

#include <src/Gui/CustomControls/VideoOptionsBar.h>

VideoOptionsBar::VideoOptionsBar()
{
    zoomLevel = ZoomLevel::ZL1;

    ImageButton *backButton = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            defaultImage("asset:///images/icons/ic_back.png").
            pressedImage("asset:///images/icons/ic_back.png").
            connect(SIGNAL(clicked()), this, SIGNAL(backPressed()));

    Container *backButtonC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1.0f)).
            add(backButton);

    ImageButton *zoomButton = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            defaultImage("asset:///images/icons/ic_zoom_in_out.png").
            pressedImage("asset:///images/icons/ic_zoom_in_out.png").
            connect(SIGNAL(clicked()), this, SLOT(onZoomButtonClicked()));

    Container *zoomButtonC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1.0f)).
            add(zoomButton);

    ImageButton *zoomResetButton = ImageButton::create().
            horizontal(HorizontalAlignment::Center).
            defaultImage("asset:///images/icons/ic_zoom_reset.png").
            pressedImage("asset:///images/icons/ic_zoom_reset.png").
            connect(SIGNAL(clicked()), this, SIGNAL(zoomReset()));

    Container *zoomResetButtonC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1.0f)).
            add(zoomResetButton);

    ImageToggleButton *rotationLockButton = ImageToggleButton::create().
            horizontal(HorizontalAlignment::Center).
            imageDefault("asset:///images/icons/ic_lock_default.png").
            imageChecked("asset:///images/icons/ic_lock_checked.png").
            //imageDisabledChecked("asset:///images/icons/ic_lock_disabled_checked.png").
            //imageDisabledUnchecked("asset:///images/icons/ic_lock_disabled_unchecked.png").
            imagePressedChecked("asset:///images/icons/ic_lock_pressed_checked.png").
            imagePressedUnchecked("asset:///images/icons/ic_lock_pressed_unchecked.png").
            connect(SIGNAL(checkedChanged(bool)), this, SIGNAL(rotationLock(bool)));

    Container *rotationLockC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1.0f)).
            add(rotationLockButton);

    ImageToggleButton *screenLockButton = ImageToggleButton::create().
            horizontal(HorizontalAlignment::Center).
            imageDefault("asset:///images/icons/ic_screen_lock_open.png").
            imageChecked("asset:///images/icons/ic_screen_lock_locked.png").
            //imageDisabledChecked("asset:///images/icons/ic_lock_disabled_checked.png").
            //imageDisabledUnchecked("asset:///images/icons/ic_lock_disabled_unchecked.png").
            imagePressedChecked("asset:///images/icons/ic_screen_lock_open.png").
            imagePressedUnchecked("asset:///images/icons/ic_screen_lock_locked.png").
            connect(SIGNAL(checkedChanged(bool)), this, SIGNAL(screenLock(bool)));

    Container *screenLockC = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(1.0f)).
            add(screenLockButton);

    Container *rootC = Container::create().
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            add(backButtonC).
            add(zoomButtonC).
            add(zoomResetButtonC).
            add(rotationLockC).
            add(screenLockC);
    setRoot(rootC);

    /*for(int i=0; i<3; i++)
    {
        Container *tempC = Container::create().
                layoutProperties(StackLayoutProperties::create().spaceQuota(1.0f));
        rootC->add(tempC);
    }*/
}

void VideoOptionsBar::onZoomButtonClicked()
{
    if(++zoomLevel==ZoomLevel::ZL_LAST)
        zoomLevel = ZoomLevel::ZL1;

    //qDebug()<<ZoomLevel::Level(zoomLevel);
    /*switch(zoomLevel)
    {
        case ZoomLevel::ZL1:
            emit zoomLevelChanged(ZoomLevel::ZL1);
            break;
        case ZoomLevel::ZL2:
            emit zoomLevelChanged(ZoomLevel::ZL2);
            break;
        case ZoomLevel::ZL3:
            emit zoomLevelChanged(ZoomLevel::ZL3);
            break;
        case ZoomLevel::ZL0_75:
            emit zoomLevelChanged(ZoomLevel::ZL0_75);
            break;
        case ZoomLevel::ZL0_5:
            emit zoomLevelChanged(ZoomLevel::ZL0_5);
            zoomLevel = -1;
            break;
        default:
            qDebug()<<"////UNKNOWN ZOOM LEVEL";
    }*/
    emit zoomLevelChanged(ZoomLevel::Level(zoomLevel));
}
