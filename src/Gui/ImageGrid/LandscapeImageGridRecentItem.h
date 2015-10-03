/*
 * LandscapeImageGridRecentItem.h
 *
 *  Created on: Aug 19, 2014
 *      Author: SuhairZain
 */

#ifndef LANDSCAPEIMAGEGRIDRECENTITEM_H_
#define LANDSCAPEIMAGEGRIDRECENTITEM_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/FadeTransition>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>

using namespace bb::cascades;

class LandscapeImageGridRecentItem: public CustomControl
{
Q_OBJECT
private slots:
    void fadeOutCompleted();
    void onTimeout();
public:
    LandscapeImageGridRecentItem();
    void setAnimationsEnabled(bool);
    void setImage(QString, QString, int);
    void setPreferredWidth(float);
private:
    unsigned short int imagePointer, imageMaxIndex;
    Container *rootC;
    FadeTransition *fadeOut;
    ImageView *image;
    Label *duration, *fileName;

    QString imageRoot;
    QTimer fadeOutTimer;
};

#endif /* LANDSCAPEIMAGEGRIDRECENTITEM_H_ */
