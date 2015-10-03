/*
 * PortraitImageGridItem.h
 *
 *  Created on: Aug 18, 2014
 *      Author: SuhairZain
 */

#ifndef PORTRAITIMAGEGRIDITEM_H_
#define PORTRAITIMAGEGRIDITEM_H_

/*#include <bb/cascades/Container>
#include <bb/cascades/CustomControl>
#include <bb/cascades/FadeTransition>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>*/
#include <bb/cascades/ListItemProvider>

#include <src/Gui/ImageGrid/ImageGridItem.h>

using namespace bb::cascades;

class PortraitImageGridItem: public ImageGridItem
{
Q_OBJECT
/*private slots:
    void fadeOutCompleted();
    void onTimeout();*/
public:
    PortraitImageGridItem();
    void addItemsToRoot();
    //void setImage(QString, QString, int);
    void setPreferredWidth(float);
private:
};

class PortraitImageGridItemProvider: public ListItemProvider
{
public:
    VisualNode* createItem(ListView*, const QString&);
    void updateItem(ListView*, VisualNode*, const QString&, const QVariantList&, const QVariant&);
};

#endif /* PORTRAITIMAGEGRIDITEM_H_ */
