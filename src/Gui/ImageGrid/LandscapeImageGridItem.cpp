/*
 * LandscapeImageGridItem.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: SuhairZain
 */

#include <src/Gui/ImageGrid/LandscapeImageGridItem.h>

#include <bb/cascades/Color>
#include <bb/cascades/Container>
#include <bb/cascades/DockLayout>
#include <bb/cascades/Header>
#include <bb/cascades/StackLayout>
#include <bb/cascades/StackLayoutProperties>
//#include <bb/cascades/TapHandler>

#include <time.h>

LandscapeImageGridItem::LandscapeImageGridItem()
{
    addItemsToRoot();
}

void LandscapeImageGridItem::addItemsToRoot()
{
    Container *BG = Container::create().
            background(Color::fromARGB(0xffae734b)).
            opacity(0.6f).
            preferredSize(2000, 150);

    image->setPreferredHeight(150);
    image->setScalingMethod(ScalingMethod::AspectFit);

    fileNameLabel->setHorizontalAlignment(HorizontalAlignment::Right);
    durationLabel->setHorizontalAlignment(HorizontalAlignment::Right);

    Container *textC = Container::create().
            horizontal(HorizontalAlignment::Right).
            vertical(VerticalAlignment::Center).
            layoutProperties(StackLayoutProperties::create().spaceQuota(1)).
            add(fileNameLabel).
            add(durationLabel);
    textC->add(fileNameLabel);

    Container *content = Container::create().
            layout(StackLayout::create().orientation(LayoutOrientation::LeftToRight)).
            add(image).
            add(textC);

    Container *rootC = Container::create().
            layout(DockLayout::create()).
            add(BG).
            add(content);
    setRoot(rootC);

    setBottomMargin(6.0f);
}

/*void ImageGridItem::setPreferredWidth(float width)
{
    CustomControl::setPreferredWidth(width);
    image->setPreferredWidth(width);
}*/

VisualNode* LandscapeImageGridItemProvider::createItem(ListView*, const QString& type)
{
    if(type=="header")
        return new Header;
    else
        return new LandscapeImageGridItem;
}

void LandscapeImageGridItemProvider::updateItem(ListView*, VisualNode *listItem,
        const QString&itemType, const QVariantList&, const QVariant &data)
{
    if(itemType=="header")
    {
        Header *header = static_cast<Header*>(listItem);
        header->setTitle(data.toString());
    }
    else
    {
        QVariantMap dataMap = data.toMap();
        //qDebug()<<dataMap;

        LandscapeImageGridItem *myItem = static_cast<LandscapeImageGridItem*>(listItem);
        myItem->updateItem(dataMap["fileName"].toString(), dataMap["duration"].toInt(), 4,
                dataMap["animActive"].toBool());
    }
}
