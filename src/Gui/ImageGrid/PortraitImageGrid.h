/*
 * PortraitImageGrid.h
 *
 *  Created on: Aug 18, 2014
 *      Author: SuhairZain
 */

#ifndef PORTRAITIMAGEGRID_H_
#define PORTRAITIMAGEGRID_H_

//#include <bb/cascades/Container>
#include <bb/cascades/CustomControl>
#include <bb/cascades/GroupDataModel>

#include <src/Gui/ImageGrid/PortraitImageGridItem.h>

using namespace bb::cascades;

class PortraitImageGrid: public CustomControl
{
Q_OBJECT
signals:
    void nextChanged(QString);
    void prevChanged(QString);
    void tapped(QString, QVariantList);
private slots:
    void onListViewTriggered(QVariantList);
public:
    PortraitImageGrid();
    void addContent(QList<QVariantMap>);
    void checkForNextAndPrev(QVariantList);
private:
    QString getFullVideoPath(QVariantList);

    GroupDataModel *dataModel;
    PortraitImageGridItem *recentImage;
    //QList<PortraitImageGridItem*> imageList;
};

#endif /* IMAGEGRID_H_ */
