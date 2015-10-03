/*
 * CustomSlider.h
 *
 *  Created on: Aug 21, 2014
 *      Author: SuhairZain
 */

#ifndef CUSTOMSLIDER_H_
#define CUSTOMSLIDER_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/ImageView>
#include <bb/cascades/ProgressIndicator>

using namespace bb::cascades;

class CustomSlider: public CustomControl
{
Q_OBJECT
signals:
    void valueChanged(float);
private slots:
    void onTouch(bb::cascades::TouchEvent*);
    void onTranslationXChanging(float);
public:
    CustomSlider(int);
    void setScreenWidth(int);
    void setValue(float);
private:
    unsigned short int width, skipCounter;

    ImageView *mover;
    ProgressIndicator *indicator;
};

#endif /* CUSTOMSLIDER_H_ */
