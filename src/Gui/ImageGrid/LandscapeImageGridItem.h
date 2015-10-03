/*
 * LandscapeImageGridItem.h
 *
 *  Created on: Aug 19, 2014
 *      Author: SuhairZain
 */

#ifndef LANDSCAPEIMAGEGRIDITEM_H_
#define LANDSCAPEIMAGEGRIDITEM_H_

/*#include <bb/cascades/CustomControl>
#include <bb/cascades/FadeTransition>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>*/
#include <bb/cascades/ListItemProvider>

#include <src/Gui/ImageGrid/ImageGridItem.h>

using namespace bb::cascades;

//class LandscapeImageGridItem: public CustomControl
class LandscapeImageGridItem: public ImageGridItem
{
Q_OBJECT
//signals:
    //void tapped(QString);
private slots:
    //void fadeOutCompleted();
    //void onTapped();
    //void onTimeout();
public:
    LandscapeImageGridItem();
    void addItemsToRoot();
    void setAnimationsEnabled(bool);
    void setImage(QString, QString, int);
    void setPreferredWidth(float);
private:
    /*unsigned short int imagePointer, imageMaxIndex;
    //Container *rootC;
    FadeTransition *fadeOut;
    ImageView *image;
    Label *duration, *fileName;*/

    QString imageRoot, videoPath;
    QTimer fadeOutTimer;
};

class LandscapeImageGridItemProvider: public ListItemProvider
{
public:
    VisualNode* createItem(ListView*, const QString&);
    void updateItem(ListView*, VisualNode*, const QString&, const QVariantList&, const QVariant&);
};

#endif /* LANDSCAPEIMAGEGRIDITEM_H_ */
