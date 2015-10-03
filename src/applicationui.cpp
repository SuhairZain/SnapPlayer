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

#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/Container>
#include <bb/device/DisplayInfo>
#include <bb/cascades/DockLayout>
#include <bb/cascades/Window>

#include <src/Gui/CustomControls/VolumeBar.h>
//#include <bb/cascades/QmlDocument>

/*#include <errno.h>
#include <screen/screen.h>*/
//#include <screen/effects.h>

using namespace bb::multimedia;

ApplicationUI::ApplicationUI() : QObject()
{
    backupVolume = 1;
    //OrientationSupport::instance()->setSupportedDisplayOrientation(SupportedDisplayOrientation::DisplayLandscape);
    rotationLocked = screenLocked = FALSE;

    bb::device::DisplayInfo displayInfo;
    screenSize = displayInfo.pixelSize();

    connect(Application::instance(), SIGNAL(asleep()), this, SLOT(onAppAsleep()));
    QStringList foundFilesList;

    QDir sharedPath = QDir::current();
    sharedPath.cd("shared");

    QStringList sharedFoldersContent = sharedPath.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i=0; i<sharedFoldersContent.size(); i++)
    {
        if(sharedFoldersContent.at(i)!="misc")
        {
            QDir temp = sharedPath;
            temp.cd(sharedFoldersContent.at(i));
            foundFilesList.append(searchForDirs(temp));
        }
    }

    QList<QVariantMap> foundFilesDetails;
    QVariantMap tempMap;
    //tempMap["drive"] = "_device";
    //qDebug()<<"Found List("<<foundFilesList.size()<<")--->>>>";
    QString tempS;
    unsigned short int deviceFilesSize = foundFilesList.size();
    for(int i=0; i<deviceFilesSize; ++i)
    {
        tempS = foundFilesList.at(i);
        tempS = tempS.right(tempS.size() - tempS.indexOf("shared") - 7);
        tempMap["filePath"] = tempS.left(tempS.lastIndexOf('/'));
        tempMap["rootFolder"] = "_DEVICE_" + tempS.left(tempS.indexOf('/'));
        tempMap["fileName"] = tempS.right(tempS.length() - tempS.lastIndexOf('/') - 1);
        foundFilesDetails.append(tempMap);
    }

    /*for(int i=0; i<foundFilesDetails.size(); ++i)
        qDebug()<<foundFilesDetails.at(i);*/
    //qDebug()<<"Search Over";

    //Invoked "/accounts/1000/removable/sdcard/downloads/IMG_03641_edit.jpg"
    QStringList memoryCardFiles;
    QDir rPath = QDir::current();
    //rPath.cdUp();
    //rPath.cdUp();
    rPath.cd("../../removable");
    if(rPath.entryList(QDir::Dirs | QDir::NoDotAndDotDot).contains("sdcard"))
    {
        rPath.cd("sdcard");
        memoryCardFiles.append(searchForDirs(rPath));

        //tempMap["drive"] = "_card";
        unsigned short int cardFilesSize = memoryCardFiles.size();
        for(int i=0; i<cardFilesSize; ++i)
        {
            tempS = memoryCardFiles.at(i);
            tempS = tempS.right(tempS.size() - tempS.indexOf("sdcard") - 7);
            tempMap["filePath"] = tempS.left(tempS.lastIndexOf('/'));
            tempMap["rootFolder"] = "_SDCARD_";// + tempS.left(tempS.indexOf('/'));
            //qDebug()<<tempMap["rootFolder"]
            tempMap["fileName"] = tempS.right(tempS.length() - tempS.lastIndexOf('/') - 1);
            foundFilesDetails.append(tempMap);
        }
    }
    else
    {
        qDebug()<<"No media card";
    }

    /*for(int i=0; i<foundFilesDetails.size();)
    {
        qDebug()<<foundFilesDetails.at(i++);
    }*/

    navPane = NavigationPane::create().
            backButtons(FALSE).
            peek(FALSE);
    Application::instance()->setScene(navPane);
    connect(navPane, SIGNAL(popTransitionEnded(bb::cascades::Page*)), this, SLOT(onClosed()));

    //screen_create_window();

    //screen_window_t controlHandle = new _screen_window;

    /*Window *mainWindow = Application::instance()->mainWindow();

    QString wName = "player_window";

    QByteArray windowName;
    windowName = wName.toLocal8Bit();

    screen_context_t screenContext;
    screen_window_t screenWindow;
    // We must create a context before you create a window.
    if (screen_create_context(&screenContext, SCREEN_APPLICATION_CONTEXT) != 0) {
        qDebug()<<"Unable to take context";
    }
    // Create a child window of the current window group, join the window group and set
    // a window ID.
    else if (screen_create_window_type(&screenWindow, screenContext, SCREEN_CHILD_WINDOW) != 0) {
        qDebug()<<"Unable to create window";
    }
    else if(screen_join_window_group(screenWindow, qPrintable(mainWindow->groupId())) != 0) {
        qDebug()<<"Unable to  join group";
    }
    else if(screen_set_window_property_cv(screenWindow, SCREEN_PROPERTY_ID_STRING, windowName.length(),
            windowName.constData()) != 0) {
        qDebug()<<"Unable to set property";
    }
    else if (screen_set_pixmap_property_iv(screen_pix, SCREEN_PROPERTY_BUFFER_SIZE, mSize) != 0) {
        qDebug()<<"Unable to set pixel map";
    }*/

    control = ForeignWindowControl::create().
            //parent(this).
            //windowHandle(mainWindow->handle()).
            //windowHandle(controlHandle).
            //preferredSize(1280, 768).
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            windowId("MyWindow").
            updatedProperties(WindowProperty::Size | WindowProperty::Position | WindowProperty::Visible);
    //control->bindToWindow(screenWindow, mainWindow->groupId(), windowName);
    //control->setVisible(TRUE);
    //control->setWindowId("");
    //qDebug()<<"Debug string"<<mainWindow->toDebugString();
    //connect(Application::instance()->mainWindow()->, SIGNAL())

    /*int brightnessValue = 0;
    qDebug()<<"Has error getting?"<<screen_get_window_property_iv(mainWindow->handle(), SCREEN_PROPERTY_BRIGHTNESS, &brightnessValue);
    qDebug()<<"Brightness value:"<<brightnessValue;
    brightnessValue = -255;
    qDebug()<<"Has error setting?"<<screen_set_window_property_iv(mainWindow->handle(), SCREEN_PROPERTY_BRIGHTNESS, &brightnessValue);
    brightnessValue = -128;
    qDebug()<<"Has error setting contrast?"<<screen_set_window_property_iv(mainWindow->handle(), SCREEN_PROPERTY_CONTRAST, &brightnessValue);
    qDebug()<<"Has error getting contrast?"<<screen_get_window_property_iv(mainWindow->handle(), SCREEN_PROPERTY_CONTRAST, &brightnessValue);
    qDebug()<<"Contrast value:"<<brightnessValue;
    qDebug()<<"Has error getting?"<<screen_get_window_property_iv(mainWindow->handle(), SCREEN_PROPERTY_BRIGHTNESS, &brightnessValue);
    qDebug()<<"Brightness value:"<<brightnessValue;*/
    //qDebug()<<errno;

    //TODO
    videoSize = screenSize;
    //control->setPreferredSize(videoSize.width(), videoSize.height());

    /*videoSlider = Slider::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Bottom).
            from(0).
            to(1);*/
    //connect(videoSlider, SIGNAL(immediateValueChanged(float)), this, SLOT(onSliderValueChanged(float)));

    myVideoScroll = new CustomScrollView(control);
    myVideoScroll->setHorizontalAlignment(HorizontalAlignment::Center);
    myVideoScroll->setVerticalAlignment(VerticalAlignment::Center);
    connect(myVideoScroll, SIGNAL(seekForward(int)), this, SLOT(onScrollSeekForward(int)));
    /*videoPlayerScroll = ScrollView::create(control).
            //ScrollView *videoPlayerScroll = ScrollView::create().
            horizontal(HorizontalAlignment::Center).
            vertical(VerticalAlignment::Center).
            minContentScale(0.25f).
            scrollMode(ScrollMode::Both).
            initialScalingMethod(ScalingMethod::None).
            overScrollEffectMode(OverScrollEffectMode::None).
            pinchToZoomEnabled(TRUE);*/
    //connect(videoPlayerScroll, SIGNAL(contentScaleChanged(float)), this, SLOT(onVideoOptionsZoomReset()));
    /*connect(videoPlayerScroll, SIGNAL(viewableAreaChanged(QRectF,float)),
            this, SLOT(onScrollViewAreaChanged(QRectF, float)));*/

    mySlider = new CustomSlider(screenSize.width()-80);
    mySlider->setHorizontalAlignment(HorizontalAlignment::Fill);
    mySlider->setVerticalAlignment(VerticalAlignment::Bottom);
    connect(mySlider, SIGNAL(valueChanged(float)), this, SLOT(onSliderValueChanged(float)));
    if(OrientationSupport::instance()->orientation()==UIOrientation::Landscape)
        mySlider->setScreenWidth(screenSize.height()-80);

    videoOptionsBar = new VideoOptionsBar;
    videoOptionsBar->setHorizontalAlignment(HorizontalAlignment::Fill);
    videoOptionsBar->setVerticalAlignment(VerticalAlignment::Top);
    connect(videoOptionsBar, SIGNAL(backPressed()), this, SLOT(onVideoOptionsBackPressed()));
    connect(videoOptionsBar, SIGNAL(rotationLock(bool)), this, SLOT(onVideoOptionsRotationLock(bool)));
    connect(videoOptionsBar, SIGNAL(screenLock(bool)), this, SLOT(onVideoOptionsScreenLock(bool)));
    connect(videoOptionsBar, SIGNAL(zoomLevelChanged(ZoomLevel::Level)),
            this, SLOT(onVideoOptionsZoomLevelChanged(ZoomLevel::Level)));
    connect(videoOptionsBar, SIGNAL(zoomReset()), this, SLOT(onVideoOptionsZoomReset()));

    VolumeBar *volumeBar = new VolumeBar;
    volumeBar->setVerticalAlignment(VerticalAlignment::Center);
    connect(myVideoScroll, SIGNAL(volumeChanged(float)), volumeBar, SLOT(onVolumeChanged(float)));

    Container *rootC = Container::create().
            layout(DockLayout::create()).
            background(Color::Black).
            add(myVideoScroll).
            //add(videoPlayerScroll).
            add(mySlider).
            add(videoOptionsBar).
            add(volumeBar);

    prevAction = ActionItem::create().
            image("asset:///images/icons/ic_previous.png").
            title("Previous").
            onTriggered(this, SLOT(onPlayPrev()));

    playPauseAction = ActionItem::create().
            image("asset:///images/icons/ic_pause.png").
            title("Pause").
            onTriggered(this, SLOT(onPlayPause()));

    nextAction = ActionItem::create().
            image("asset:///images/icons/ic_next.png").
            title("Next").
            onTriggered(this, SLOT(onPlayNext()));

    mediaPage = Page::create().
            actionBarVisibility(ChromeVisibility::Visible).
            content(rootC).
            parent(navPane).
            addAction(prevAction, ActionBarPlacement::OnBar).
            addAction(playPauseAction, ActionBarPlacement::OnBar).
            addAction(nextAction, ActionBarPlacement::OnBar);

    videoDuration = 0.0f;

    player = new MediaPlayer(this);
    //player->moveToThread(new QThread);
    connect(player, SIGNAL(durationChanged(unsigned int)), this, SLOT(onPlayerDurationChanged(unsigned int)));
    connect(player, SIGNAL(positionChanged(unsigned int)), this, SLOT(onPlayerPositionChanged(unsigned int)));
    connect(player, SIGNAL(metaDataChanged(QVariantMap)), this, SLOT(onPlayerMetaDataChanged(QVariantMap)));
    connect(player, SIGNAL(mediaStateChanged(bb::multimedia::MediaState::Type)),
            this, SLOT(onPlayerMediaStateChanged(bb::multimedia::MediaState::Type)));
    connect(volumeBar, SIGNAL(volumeChanged(double)), player, SLOT(setVolume(double)));

    //player->setRepeatMode(RepeatMode::Track);
    player->setAutoPause(TRUE);
    player->setVideoOutput(VideoOutput::PrimaryDisplay);
    player->setWindowGroupId(control->windowGroup());
    player->setWindowId(control->windowId());

    connect(OrientationSupport::instance(), SIGNAL(orientationAboutToChange(bb::cascades::UIOrientation::Type)),
            this, SLOT(onOrientationChange(bb::cascades::UIOrientation::Type)));

    //player->play();
    /*QmlDocument *doc;

    if(OrientationSupport::instance()->orientation()==UIOrientation::Portrait)
        doc = QmlDocument::create("asset:///portrait.qml").parent(this);
    else
        doc = QmlDocument::create("asset:///landscape.qml").parent(this);

    Application::instance()->setScene(doc->createRootObject<Page>());*/
    if(OrientationSupport::instance()->orientation()==UIOrientation::Portrait)
    {
        //control->setPreferredSize(768, 1280);
        portGrid = new PortraitImageGrid;
        listPage = Page::create().content(portGrid);
        navPane->push(listPage);
        portGrid->addContent(foundFilesDetails);
        connect(portGrid, SIGNAL(tapped(QString, QVariantList)), this, SLOT(onTapped(QString, QVariantList)));
        connect(portGrid, SIGNAL(nextChanged(QString)), this, SLOT(onListNextChanged(QString)));
        connect(portGrid, SIGNAL(prevChanged(QString)), this, SLOT(onListPrevChanged(QString)));

        landGrid = new LandscapeImageGrid;
        landGrid->setParent(listPage);
        landGrid->addContent();
        //connect(landGrid, SIGNAL(tapped(QString)), this, SLOT(onTapped(QString)));
    }
    else
    {
        //control->setPreferredSize(1280, 768);

        landGrid = new LandscapeImageGrid;
        listPage = Page::create().content(landGrid);
        navPane->push(listPage);
        landGrid->addContent();
        //qDebug()<<"Is landscape";
        //connect(landGrid, SIGNAL(tapped(QString)), this, SLOT(onTapped(QString)));

        portGrid = new PortraitImageGrid;
        portGrid->setParent(listPage);
        portGrid->addContent(foundFilesDetails);
        connect(portGrid, SIGNAL(tapped(QString, QVariantList)), this, SLOT(onTapped(QString, QVariantList)));
        connect(portGrid, SIGNAL(nextChanged(QString)), this, SLOT(onListNextChanged(QString)));
        connect(portGrid, SIGNAL(prevChanged(QString)), this, SLOT(onListPrevChanged(QString)));
        //connect(portGrid, SIGNAL(tapped(QString)), this, SLOT(onTapped(QString)));
    }
    //onOrientationChange(OrientationSupport::instance()->orientation());
}

ApplicationUI::~ApplicationUI()
{
    //player->deleteLater();
}

void ApplicationUI::onAppAsleep()
{
    if(player->mediaState()==MediaState::Started)
        onPlayPause();
}

void ApplicationUI::onClosed()
{
    player->stop();

    if(OrientationSupport::instance()->orientation()==UIOrientation::Landscape)
        landGrid->setAnimationsEnabled(TRUE);

    OrientationSupport::instance()->setSupportedDisplayOrientation(SupportedDisplayOrientation::All);
}

void ApplicationUI::onListNextChanged(QString n)
{
    nextUrl = n;
    nextAction->setEnabled(n!="");
}

void ApplicationUI::onListPrevChanged(QString p)
{
    prevUrl = p;
    prevAction->setEnabled(p!="");
}

void ApplicationUI::onOrientationChange(bb::cascades::UIOrientation::Type newOrientation)
{
    if(newOrientation==UIOrientation::Landscape)
    {
        listPage->setContent(landGrid);
        if(navPane->count()==1)
            landGrid->setAnimationsEnabled(TRUE);

        mySlider->setScreenWidth(screenSize.height()-80);
        //TODO
        //portGrid->setAnimationsEnabled(FALSE);
    }
    else
    {
        listPage->setContent(portGrid);
        if(navPane->count()==1)
        {
            //TODO
            //portGrid->setAnimationsEnabled(TRUE);
        }
        mySlider->setScreenWidth(screenSize.width()-80);

        landGrid->setAnimationsEnabled(FALSE);
    }

    onVideoSizeChanged(TRUE);
}

void ApplicationUI::onPlayerDurationChanged(unsigned int dur)
{
    videoDuration = dur;
}

void ApplicationUI::onPlayerMediaStateChanged(bb::multimedia::MediaState::Type state)
{
    //qDebug()<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<state;
    //qDebug()<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Size:"<<player->videoDimensions();
    if(state==MediaState::Stopped && navPane->count()>1)
        navPane->pop();

    //else if(state==MediaState::Prepared)
}

void ApplicationUI::onPlayerMetaDataChanged(QVariantMap map)
{
    int width = map["width"].toInt();
    int height = map["height"].toInt();

    if(width && height)
    {
        videoSize.setWidth(width);
        videoSize.setHeight(height);
        //qDebug()<<"////"<<videoSize;

        /*if(OrientationSupport::instance()->orientation()==UIOrientation::Portrait)
            onOrientationChange(UIOrientation::Landscape)*/
        //onOrientationChange(OrientationSupport::instance()->orientation());
        onVideoSizeChanged();
    }
}

void ApplicationUI::onPlayerPositionChanged(unsigned int pos)
{
    //videoSlider->setValue(float(pos)/videoDuration);
    qDebug()<<"////Volume"<<player->volume()<<"Backup"<<backupVolume;
    if(player->volume()==0)
        player->setVolume(backupVolume);
    mySlider->setValue(float(pos)/videoDuration);
}

void ApplicationUI::onPlayNext()
{
    if(nextAction->isEnabled())
    {
        nextAction->setEnabled(FALSE);
        currentIndexPath.replace(currentIndexPath.size()-1, currentIndexPath.last().toInt() + 1);
        onTapped(nextUrl, currentIndexPath);
        //QVariantList tempPath = currentIndexPath;
        portGrid->checkForNextAndPrev(currentIndexPath);
    }
}

void ApplicationUI::onPlayPause()
{
    if(playPauseAction->title()=="Pause")
    {
        player->pause();
        playPauseAction->setImage("asset:///images/icons/ic_play.png");
        playPauseAction->setTitle("Play");
    }
    else
    {
        player->play();
        playPauseAction->setImage("asset:///images/icons/ic_pause.png");
        playPauseAction->setTitle("Pause");
    }
}

void ApplicationUI::onPlayPrev()
{
    if(prevAction->isEnabled())
    {
        prevAction->setEnabled(FALSE);
        currentIndexPath.replace(currentIndexPath.size()-1, currentIndexPath.last().toInt() - 1);
        onTapped(prevUrl, currentIndexPath);
        //QVariantList tempPath = currentIndexPath;
        portGrid->checkForNextAndPrev(currentIndexPath);
    }
}

/*void ApplicationUI::onScrollContentScaleChanged()
{
    //videoPlayerScroll->scrollViewProperties()->setScrollMode(ScrollMode::Both);
}*/

void ApplicationUI::onScrollSeekForward(int seekBy)
{
    if(player->volume()!=0)
        backupVolume = player->volume();
    player->setVolume(0);
    int newPos = player->position()+seekBy;
    if(newPos<0)
        newPos=0;
    player->seekTime(newPos);
}

/*void ApplicationUI::onScrollViewAreaChanged(QRectF rect, float f)
{
    qDebug()<<"///Change"<<rect<<f;
}*/

//TODO replace with S-S
void ApplicationUI::onSliderValueChanged(float val)
{
    player->seekPercent(val);
}

void ApplicationUI::onTapped(QString vidPath, QVariantList iPath)
{
    //videoPlayerScroll->resetViewableArea();
    myVideoScroll->resetControlScale();
    currentIndexPath = iPath;

    player->setSourceUrl(vidPath);
    //player->prepare();
    navPane->push(mediaPage);
    //videoSlider->disconnect(SIGNAL(immediateValueChanged(float)), this, SLOT(onSliderValueChanged(float)));
    //videoSlider->setValue(0.0f);
    mySlider->setValue(0.0f);
    //connect(videoSlider, SIGNAL(immediateValueChanged(float)), this, SLOT(onSliderValueChanged(float)));
    playPauseAction->setImage("asset:///images/icons/ic_pause.png");
    playPauseAction->setTitle("Pause");
    player->play();

    if(OrientationSupport::instance()->orientation()==UIOrientation::Landscape)
        landGrid->setAnimationsEnabled(FALSE);
    //qDebug()<<player->videoDimensions();

    if(rotationLocked)
    {
        if(lockedOrientation==UIOrientation::Portrait)
            OrientationSupport::instance()->setSupportedDisplayOrientation(
                    SupportedDisplayOrientation::DisplayPortrait);
        else
            OrientationSupport::instance()->setSupportedDisplayOrientation(
                    SupportedDisplayOrientation::DisplayLandscape);
    }

}

void ApplicationUI::onVideoOptionsBackPressed()
{
    if(navPane->count()>1)
        navPane->pop();
}

void ApplicationUI::onVideoOptionsRotationLock(bool isLocked)
{
    if(isLocked)
    {
        OrientationSupport::instance()->setSupportedDisplayOrientation(
                SupportedDisplayOrientation::CurrentLocked);
        rotationLocked = TRUE;
        lockedOrientation = OrientationSupport::instance()->orientation();
    }
    else
    {
        OrientationSupport::instance()->setSupportedDisplayOrientation(SupportedDisplayOrientation::All);
        rotationLocked = FALSE;
    }
}

void ApplicationUI::onVideoOptionsScreenLock(bool isLocked)
{
    screenLocked = isLocked;
}

void ApplicationUI::onVideoOptionsZoomLevelChanged(ZoomLevel::Level level)
{
    float zLevel;
    switch(level)
    {
        case ZoomLevel::ZL1:
            zLevel = 1.0f;
            break;
        case ZoomLevel::ZL2:
            zLevel = 2.0f;
            break;
        case ZoomLevel::ZL3:
            zLevel = 3.0f;
            break;
        case ZoomLevel::ZL0_75:
            zLevel = 0.75f;
            break;
        case ZoomLevel::ZL0_5:
            zLevel = 0.5f;
            break;
        case ZoomLevel::ZL_LAST:
            qDebug()<<"////Prohibited value";
            break;
    }
    qDebug()<<"////Passed value"<<zLevel;
    myVideoScroll->setControlScale(zLevel);
}

//TODO change to S-S
void ApplicationUI::onVideoOptionsZoomReset()
{
    myVideoScroll->resetControlScale();
}

void ApplicationUI::onVideoSizeChanged(bool justAboutToChange)
{
    int scrH, scrW;
    if(OrientationSupport::instance()->orientation()==UIOrientation::Landscape)
    {
        scrH = screenSize.width();
        scrW = screenSize.height();
    }
    else
    {
        scrH = screenSize.height();
        scrW = screenSize.width();
    }

    if(justAboutToChange)
    {
        int temp = scrW;
        scrW = scrH;
        scrH = temp;
    }

    float hScale = float(scrW)/float(videoSize.width());
    float vScale = float(scrH)/float(videoSize.height());

    if(hScale>vScale)
    {
        control->setPreferredSize(vScale*videoSize.width(), vScale*videoSize.height());
    }
    else
    {
        control->setPreferredSize(hScale*videoSize.width(), hScale*videoSize.height());
    }
}

QStringList ApplicationUI::searchForDirs(QDir presentDir)
{
    QStringList fileExtensions;
    fileExtensions<<"*.3gp"<<"*.3g2"<<"*.asf"<<"*.avi"<<"*.f4v"<<"*.ismv";
    fileExtensions<<"*.m4v"<<"*.mkv"<<"*.mov"<<"*.mp4"<<"*.mpeg"<<"*.wmv";
    QStringList fileList = presentDir.entryList(fileExtensions, QDir::Files);

    QStringList returnList;
    for(int i=0; i<fileList.size();)
        returnList.append(presentDir.path() + "/" + fileList.at(i++));

    QStringList listOfDirs = presentDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(int i=0; i<listOfDirs.size();)
    {
        QDir temp = presentDir;
        temp.cd(listOfDirs.at(i++));
        returnList.append(searchForDirs(temp));
    }

    return returnList;
}
