/*
 * ImageGridItem.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: SuhairZain
 */

#include <src/Gui/ImageGrid/PortraitImageGridItem.h>

//#include <bb/cascades/AbsoluteLayout>
#include <bb/cascades/DockLayout>
#include <bb/cascades/Header>
//#include <bb/cascades/TextStyle>

#include <time.h>

PortraitImageGridItem::PortraitImageGridItem()
{
    addItemsToRoot();
}

void PortraitImageGridItem::addItemsToRoot()
{
    image->setHorizontalAlignment(HorizontalAlignment::Fill);
    image->setVerticalAlignment(VerticalAlignment::Fill);
    image->setScalingMethod(ScalingMethod::AspectFill);

    Container *textBG = Container::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Bottom).
            preferredHeight(75).
            background(Color::fromARGB(0xffae734b)).
            opacity(0.6f);

    durationLabel->setHorizontalAlignment(HorizontalAlignment::Right);
    //bottomMargin(0.0f).
    //bottomMargin(0.0f).

    Container *textC = Container::create().
            horizontal(HorizontalAlignment::Fill).
            vertical(VerticalAlignment::Bottom).
            add(durationLabel).
            add(fileNameLabel);

    Container *rootC = Container::create().
            layout(DockLayout::create()).
            add(image).
            add(textBG).
            add(textC);
    setRoot(rootC);
}

void PortraitImageGridItem::setPreferredWidth(float width)
{
    CustomControl::setPreferredWidth(width);
    image->setPreferredWidth(width);
}



VisualNode* PortraitImageGridItemProvider::createItem(ListView*, const QString& type)
{
    if(type=="header")
        return new Header;
    else
        return new PortraitImageGridItem;
}

void PortraitImageGridItemProvider::updateItem(ListView*, VisualNode *listItem,
        const QString&itemType, const QVariantList&, const QVariant &data)
{
    if(itemType=="header")
    {
        Header *header = static_cast<Header*>(listItem);
        QString filePath = data.toString();
        if(filePath.left(8)=="_DEVICE_")
        {
            filePath = filePath.right(filePath.size()-8);
            //int index = filePath.indexOf('/');
            //QString headerTitle = filePath.left(index);
            /*while(index>0)
            {
                filePath = filePath.right(filePath.size() - index - 1);
                index = filePath.indexOf('/');
                headerTitle = headerTitle.append(" | " + filePath.left(index));
            }*/
            //qDebug()<<filePath.right(filePath.size() - filePath.indexOf('/') - 1);
            header->setTitle(filePath.left(filePath.indexOf('/')));
        }
        else
        {
            header->setTitle("Media Card");
        }
        //qDebug()<<headerTitle;
    }
    else
    {
        QVariantMap dataMap = data.toMap();
        //qDebug()<<dataMap;

        PortraitImageGridItem *myItem = static_cast<PortraitImageGridItem*>(listItem);
        myItem->updateItem(dataMap["fileName"].toString(), dataMap["duration"].toInt(), 4,
                dataMap["animActive"].toBool());
    }
}
