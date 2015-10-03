/*
 * VolumeBar.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: SuhairZain
 */

#include <src/Gui/CustomControls/VolumeBar.h>

#include <bb/cascades/Container>
#include <bb/cascades/StackLayout>

VolumeBar::VolumeBar()
{
    volume = 1.0f;

    /*muteImage = ImageView::create().
            horizontal(HorizontalAlignment::Center).
            image("asset:///images/icons/ic_volume_mute.png");*/

    Container *rootC = Container::create().
            left(10.0f).
            layout(StackLayout::create().orientation(LayoutOrientation::BottomToTop));//.
    //add(muteImage);
    setRoot(rootC);

    for(int i=0; i<10; i++)
    {
        ImageView *temp = ImageView::create().
                horizontal(HorizontalAlignment::Center).
                image("asset:///images/icons/volumeBar.png");
        rootC->add(temp);

        barsList.append(temp);
    }

    /*for(int i=0; i<3; i++)
    {
        ImageView *temp = ImageView::create().
                horizontal(HorizontalAlignment::Center).
                image("asset:///images/icons/volumeBarEmpty.png");
        rootC->add(temp);

        barsList.append(temp);
    }*/

    fullImage = ImageView::create().
            horizontal(HorizontalAlignment::Center).
            image("asset:///images/icons/ic_volume_full.png");
    rootC->add(fullImage);
}

void VolumeBar::onVolumeChanged(float changeInVolume)
{
    volume += changeInVolume;

    if(volume>=1.0f)
    {
        fullImage->setImage("asset:///images/icons/ic_volume_full.png");
        volume = 1;
    }
    else
        fullImage->setImage("asset:///images/icons/ic_volume_full_false.png");

    if(volume<0.0f)
    {
        volume = 0;
    }

    int count = volume/0.1f;

    for(int i=0; i<10; i++)
    {
        if(i<count)
            barsList.at(i)->setImage("asset:///images/icons/volumeBar.png");
        else
            barsList.at(i)->setImage("asset:///images/icons/volumeBarEmpty.png");
    }

    emit volumeChanged(volume);
}
