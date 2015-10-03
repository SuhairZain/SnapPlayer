/*
 * VolumeBar.h
 *
 *  Created on: Aug 25, 2014
 *      Author: SuhairZain
 */

#ifndef VOLUMEBAR_H_
#define VOLUMEBAR_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/ImageView>

using namespace bb::cascades;

class VolumeBar: public CustomControl
{
Q_OBJECT
signals:
    void volumeChanged(double);
private slots:
    void onVolumeChanged(float);
public:
    VolumeBar();
private:
    float volume;
    ImageView *fullImage;//, *muteImage;
    QList<ImageView*> barsList;
};

#endif /* VOLUMEBAR_H_ */
