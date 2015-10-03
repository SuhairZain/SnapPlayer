/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <bb/cascades/ActionItem>
#include <bb/cascades/ForeignWindowControl>
#include <bb/multimedia/MediaPlayer>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/OrientationSupport>
#include <bb/cascades/Page>
//#include <bb/cascades/ScrollView>
//#include <bb/cascades/Slider>

#include <src/Gui/CustomControls/CustomScrollView.h>
#include <src/Gui/CustomControls/CustomSlider.h>
#include <src/Gui/ImageGrid/LandscapeImageGrid.h>
#include <src/Gui/ImageGrid/PortraitImageGrid.h>
#include <src/Gui/CustomControls/VideoOptionsBar.h>

using namespace bb::cascades;
/*namespace bb
{
    namespace cascades
    {
    }
}*/
/*!
 * @brief Application UI object
 *
 * Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI : public QObject
{
Q_OBJECT
public:
    ApplicationUI();
    ~ApplicationUI();
private Q_SLOTS:
    void onAppAsleep();
    void onClosed();
    void onListNextChanged(QString);
    void onListPrevChanged(QString);
    void onOrientationChange(bb::cascades::UIOrientation::Type);
    void onPlayerDurationChanged(unsigned int);
    void onPlayerMediaStateChanged(bb::multimedia::MediaState::Type);
    void onPlayerMetaDataChanged(QVariantMap);
    void onPlayerPositionChanged(unsigned int);
    void onPlayNext();
    void onPlayPause();
    void onPlayPrev();
    //void onScrollContentScaleChanged();
    void onScrollSeekForward(int);
    //void onScrollViewAreaChanged(QRectF, float);
    void onSliderValueChanged(float);
    void onTapped(QString, QVariantList);
    void onVideoOptionsBackPressed();
    void onVideoOptionsRotationLock(bool);
    void onVideoOptionsScreenLock(bool);
    void onVideoOptionsZoomLevelChanged(ZoomLevel::Level);
    void onVideoOptionsZoomReset();
private:
    void onVideoSizeChanged(bool justAboutToChange=FALSE);
    QStringList searchForDirs(QDir);

    QSize screenSize, videoSize;
    QString nextUrl, prevUrl;
    QVariantList currentIndexPath;
    UIOrientation::Type lockedOrientation;
    bool rotationLocked, screenLocked;
    float videoDuration;
    double backupVolume;

    ActionItem *playPauseAction, *nextAction, *prevAction;
    ForeignWindowControl *control;
    bb::multimedia::MediaPlayer *player;
    NavigationPane *navPane;
    Page *mediaPage, *listPage;
    //ScrollView *videoPlayerScroll;

    //Page *rootPage;
    CustomScrollView *myVideoScroll;
    CustomSlider *mySlider;
    LandscapeImageGrid *landGrid;
    PortraitImageGrid *portGrid;
    VideoOptionsBar *videoOptionsBar;
};

#endif /* ApplicationUI_HPP_ */
