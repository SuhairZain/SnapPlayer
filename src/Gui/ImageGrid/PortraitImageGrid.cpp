/*
 * PortraitImageGrid.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: SuhairZain
 */

#include <src/Gui/ImageGrid/PortraitImageGrid.h>

#include <bb/cascades/Color>
#include <bb/cascades/ContextMenuHandler>
#include <bb/device/DisplayInfo>
#include <bb/cascades/GridListLayout>
#include <bb/cascades/ScrollView>
#include <bb/cascades/ListView>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>

#include <src/Gui/ImageGrid/PortraitImageGridItem.h>

PortraitImageGrid::PortraitImageGrid()
{
    recentImage = new PortraitImageGridItem;
    bb::device::DisplayInfo dispInfo;
    int screenWidth = dispInfo.pixelSize().width();

    recentImage->setPreferredWidth(screenWidth-12);

    int recentHeight = float(screenWidth-12)*(9.0f/16.0f);
    qDebug()<<recentHeight;
    recentImage->setPreferredHeight(recentHeight);
    recentImage->updateItem("app/native/assets/videos/" + QString::number(10) + ".mp4", 1232, 4, TRUE);
    //recentImage->setImage("asset:///images/0/", "The recent files", 5231);
    recentImage->setBottomMargin(6.0f);

    dataModel = new GroupDataModel;

    QStringList sortingKeys;
    //sortingKeys<<"rootFolder"<<"filePath"<<"fileName";
    sortingKeys<<"rootFolder"<<"fileName";
    dataModel->setGrouping(ItemGrouping::ByFullValue);
    dataModel->setSortingKeys(sortingKeys);

    ListView *videosList = ListView::create().
            //flickMode(FlickMode::None).
            horizontal(HorizontalAlignment::Fill).
            //leadingVisual(recentImage).
            layout(GridListLayout::create().
                    columnCount(3).headerMode(ListHeaderMode::Sticky)/*.cellAspectRatio(1.0f)*/).
            listItemProvider(new PortraitImageGridItemProvider).
            connect(SIGNAL(triggered(QVariantList)), this, SLOT(onListViewTriggered(QVariantList))).
            scrollRole(ScrollRole::None).
            primaryKeyTarget(FALSE).
            //stickToEdgePolicy(ListViewStickToEdgePolicy::Beginning).
            dataModel(dataModel);
    qDebug()<<videosList->isBufferedScrollingEnabled();
    videosList->setBufferedScrollingEnabled(FALSE);
    //videosList->setMaxHeight(((screenWidth-24)*15/3) + 3*30 + (15*12));//dispInfo.pixelSize().height()-12-recentHeight);
    //videosList->setLeadingVisualSnapThreshold(0.0f);
    //videosList->scroll(-200);
    //videosList->scrollToPosition(-1000, ScrollAnimation::None);
    //videosList->setSnapMode(SnapMode::LeadingEdge);
    //videosList->setLeadingVisual(new Control);

    Container *rootC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Fill).
            add(recentImage).
            add(videosList);

    ScrollView *contentScroll = ScrollView::create(rootC).
            primaryKeyTarget(TRUE).
            scrollMode(ScrollMode::Vertical).
            scrollRole(ScrollRole::Main).
            overScrollEffectMode(OverScrollEffectMode::None).
            horizontal(HorizontalAlignment::Fill);

    Container *finalRoot = Container::create().
            horizontal(HorizontalAlignment::Fill).
            top(6.0f).
            right(6.0f).
            bottom(6.0f).
            left(6.0f).
            background(Color::fromARGB(0xffc63d0f)).
            add(contentScroll);
            //add(recentImage).
            //add(videosList);
    setRoot(finalRoot);
}

void PortraitImageGrid::addContent(QList<QVariantMap> filesList)
{
    /*unsigned short int listSize = filesList.size();
    for(int i=0; i<listSize; ++i)
    {
        QVariantMap temp;
        temp["fileName"] = "app/native/assets/videos/" + QString::number(i) + ".mp4";
        temp["duration"] = 165;
        temp["animActive"] = TRUE;

        dataModel->insert(temp);
    }*/
    dataModel->insertList(filesList);
}

void PortraitImageGrid::checkForNextAndPrev(QVariantList iPath)
{
    QVariantList tempPath = iPath;
    tempPath.replace(tempPath.size()-1, tempPath.last().toInt() + 1);
    if(dataModel->data(tempPath)==QVariant::Invalid)
    {
        emit nextChanged("");
    }
    else
    {
        emit nextChanged(getFullVideoPath(tempPath));
    }

    tempPath = iPath;
    tempPath.replace(tempPath.size()-1, tempPath.last().toInt() - 1);
    if(dataModel->data(tempPath)==QVariant::Invalid)
    {
        emit prevChanged("");
    }
    else
    {
        emit prevChanged(getFullVideoPath(tempPath));
    }
}

QString PortraitImageGrid::getFullVideoPath(QVariantList indexPath)
{
    QVariantMap dataMap = dataModel->data(indexPath).toMap();

    QDir dir = QDir::current();
    if(dataMap["rootFolder"].toString().left(8)=="_DEVICE_")
    {
        dir.cd("shared/" + dataMap["filePath"].toString());
    }
    else
    {
        dir.cd("../../removable/sdcard/" + dataMap["filePath"].toString());
    }

    return dir.absoluteFilePath(dataMap["fileName"].toString());
}

void PortraitImageGrid::onListViewTriggered(QVariantList indexPath)
{
    QVariantMap dataMap = dataModel->data(indexPath).toMap();

    checkForNextAndPrev(indexPath);

    emit tapped(getFullVideoPath(indexPath), indexPath);
}

/*
 *
    int nVidsInEachRow[] = {3, 2};
    int pointsAtRowIndex = 0;
    int count=0;

    for(int i=0; i<5; i++)
    {
        Container *tempC = Container::create().
                preferredHeight(300.0f).
                layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight));
        rootC->add(tempC);
        tempC->setBottomMargin(6.0f);

        for(int j=0; j<nVidsInEachRow[pointsAtRowIndex]; j++)
        {
            PortraitImageGridItem *tempItem = new PortraitImageGridItem;
            tempItem->setRightMargin(6.0f);
            tempC->add(tempItem);
            //tempItem->setImage("asset:///images/" + QString::number(++count) + "/", "The files's name", 342);

            imageList.append(tempItem);

            if(j==nVidsInEachRow[pointsAtRowIndex]-1)
                break;
        }
        if(++pointsAtRowIndex==2)
            pointsAtRowIndex = 0;
    }
 */
