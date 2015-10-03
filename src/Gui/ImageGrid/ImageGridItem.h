/*
 * ImageGridItem.h
 *
 *  Created on: Aug 21, 2014
 *      Author: SuhairZain
 */

#ifndef IMAGEGRIDITEM_H_
#define IMAGEGRIDITEM_H_

#include <bb/cascades/Container>
#include <bb/cascades/CustomControl>
#include <bb/cascades/FadeTransition>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>
#include <bb/cascades/ListItemListener>

using namespace bb::cascades;

class ImageGridItem: public CustomControl, public ListItemListener
{
Q_OBJECT
private slots:
    void fadeOutCompleted();
    void onTimeout();
public:
    ImageGridItem();
    virtual void addItemsToRoot()=0;
    void activate(bool);
    void reset(bool, bool);
    void select(bool);
    void updateItem(QString, int, int, bool);
private:
    void setAnimationsEnabled(bool);
    unsigned short int imagePointer, imageMaxIndex;
    bool animationsActive;

    FadeTransition *fadeOut;
    QString imageRoot, videoPath;
    QTimer fadeOutTimer;
protected:
    ImageView *image;
    Label *durationLabel, *fileNameLabel;
};

#endif /* IMAGEGRIDITEM_H_ */
