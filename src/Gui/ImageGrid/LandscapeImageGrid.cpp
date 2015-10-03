/*
 * LandscapeImageGrid.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: SuhairZain
 */

#include <src/Gui/ImageGrid/LandscapeImageGrid.h>

#include <bb/cascades/Color>
#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
//#include <bb/cascades/ScrollView>
#include <bb/cascades/ListView>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>

LandscapeImageGrid::LandscapeImageGrid()
{
    recentImage1 = new LandscapeImageGridRecentItem;
    recentImage1->setBottomMargin(6.0f);
    recentImage1->setImage("asset:///images/10/", "Recent video number 1", 1232);

    recentImage2 = new LandscapeImageGridRecentItem;
    recentImage2->setBottomMargin(6.0f);
    recentImage2->setImage("asset:///images/11/", "The second recent video", 10);

    recentImage3 = new LandscapeImageGridRecentItem;
    recentImage3->setBottomMargin(6.0f);
    recentImage3->setImage("asset:///images/12/", "This would be the 3rd recent video", 69);

    Container *recentContainer = Container::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(4)).
            rightMargin(6.0f).
            add(recentImage1).
            add(recentImage2).
            add(recentImage3);

    //scrollingRootC = Container::create();

    /*ScrollView *scroll = ScrollView::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(6)).
            content(scrollingRootC);*/
    dataModel = new GroupDataModel;

    QStringList sortingKeys;
    sortingKeys<<"fileName";
    dataModel->setSortingKeys(sortingKeys);

    ListView *videosList = ListView::create().
            layoutProperties(StackLayoutProperties::create().spaceQuota(6)).
            listItemProvider(new LandscapeImageGridItemProvider).
            dataModel(dataModel).
            connect(SIGNAL(triggered(QVariantList)), this, SLOT(onListViewTriggered(QVariantList)));

    Container *dualContainer = Container::create().
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            add(recentContainer).
            add(videosList);
            //add(scroll);

    Container *rootC = Container::create().
            background(Color::fromARGB(0xffc63d0f)).
            top(6.0f).
            right(6.0f).
            bottom(6.0f).
            left(6.0f).
            layout(DockLayout::create()).
            add(dualContainer);
    setRoot(rootC);
}

void LandscapeImageGrid::addContent()
{
    for(int i=0; i<10; ++i)
    {
        QVariantMap temp;
        temp["fileName"] = "app/native/assets/videos/" + QString::number(i) + ".mp4";
        temp["duration"] = 165;
        temp["animActive"] = TRUE;

        dataModel->insert(temp);
        /*LandscapeImageGridItem *item = new LandscapeImageGridItem;
        //item->setImage("app/native/assets/videos/" + QString::number(i) + ".mp4", "Video's name", 100);
        item->setBottomMargin(6.0f);
        scrollingRootC->add(item);
        connect(item, SIGNAL(tapped(QString)), this, SIGNAL(tapped(QString)));*/
        //imageList.append(item);
    }

    //unsigned short int listSize = dataModel->size();
    //for(int i=0; i<listSize;)
    //{
        //qDebug()<<dataModel->toListOfMaps();
        //qDebug()<<temp;
        //temp["animActive"] = TRUE;
    //}
}

void LandscapeImageGrid::onListViewTriggered(QVariantList indexPath)
{
    qDebug()<<indexPath;
}

void LandscapeImageGrid::setAnimationsEnabled(bool enabled)
{
    //qDebug()<<"////"<<enabled<<"called on LandGrid";

    recentImage1->setAnimationsEnabled(enabled);
    recentImage2->setAnimationsEnabled(enabled);
    recentImage3->setAnimationsEnabled(enabled);

    /*unsigned short int listSize = dataModel->size();
    for(int i=0; i<listSize;)
    {
        QVariantMap temp = dataModel->data(QVariantList()<<i).toMap();
        qDebug()<<temp;
        //temp["animActive"] = TRUE;
    }*/
}
