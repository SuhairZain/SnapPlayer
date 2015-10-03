/*
 * LandscapeImageGrid.h
 *
 *  Created on: Aug 19, 2014
 *      Author: SuhairZain
 */

#ifndef LANDSCAPEIMAGEGRID_H_
#define LANDSCAPEIMAGEGRID_H_

//#include <bb/cascades/ArrayDataModel>
#include <bb/cascades/CustomControl>
#include <bb/cascades/GroupDataModel>

#include <src/Gui/ImageGrid/LandscapeImageGridItem.h>
#include <src/Gui/ImageGrid/LandscapeImageGridRecentItem.h>

using namespace bb::cascades;

class LandscapeImageGrid: public CustomControl
{
Q_OBJECT
signals:
    void tapped(QString);
private slots:
    void onListViewTriggered(QVariantList);
public:
    LandscapeImageGrid();
    void addContent();
    void setAnimationsEnabled(bool);
private:
    //ArrayDataModel *dataModel;
    //Container *scrollingRootC;
    GroupDataModel *dataModel;
    LandscapeImageGridRecentItem *recentImage1, *recentImage2, *recentImage3;
    //QList<LandscapeImageGridItem*> imageList;
};

#endif /* LANDSCAPEIMAGEGRID_H_ */
