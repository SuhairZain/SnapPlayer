/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.2
import bb.multimedia 1.2

//For landscape mode, probably
/*Page {
 * property int spaceCount: 0
 * property int spacing: 10
 * Container {
 * layout: DockLayout {
 * }
 * Container{
 * horizontalAlignment: HorizontalAlignment.Center
 * verticalAlignment: VerticalAlignment.Center
 * Container {
 * horizontalAlignment: HorizontalAlignment.Center
 * layout: AbsoluteLayout {
 * 
 * }
 * ImageView {
 * layoutProperties: AbsoluteLayoutProperties {
 * positionY: 250
 * }
 * horizontalAlignment: HorizontalAlignment.Center
 * imageSource: "asset:///images/5/1.jpg"
 * }
 * ImageView {
 * layoutProperties: AbsoluteLayoutProperties {
 * positionY: 200
 * }
 * horizontalAlignment: HorizontalAlignment.Center
 * imageSource: "asset:///images/4/1.jpg"
 * }
 * ImageView {
 * layoutProperties: AbsoluteLayoutProperties {
 * positionY: 150
 * }
 * horizontalAlignment: HorizontalAlignment.Center
 * imageSource: "asset:///images/3/1.jpg"
 * }
 * ImageView {
 * layoutProperties: AbsoluteLayoutProperties {
 * positionY: 100
 * }
 * horizontalAlignment: HorizontalAlignment.Center
 * imageSource: "asset:///images/2/1.jpg"
 * }
 * ImageView {
 * layoutProperties: AbsoluteLayoutProperties {
 * positionY: 50
 * }
 * horizontalAlignment: HorizontalAlignment.Center
 * imageSource: "asset:///images/1/1.jpg"
 * }
 * ImageView {
 * horizontalAlignment: HorizontalAlignment.Center
 * imageSource: "asset:///images/0/1.jpg"
 * }
 * }
 * Button {
 * horizontalAlignment: HorizontalAlignment.Center
 * text: "Flip"
 * onClicked: {
 * //image.setScaleX(0.1)
 * //image.setScaleY(11.1)
 * }
 * }
 * }
 * }
 }*/

Page {
    property int screenWidth: 768
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            ImageToggleButton {
                horizontalAlignment: HorizontalAlignment.Center
                imageSourceDefault: "asset:///images/icons/ic_lock_default.png"
                imageSourceChecked: "asset:///images/icons/ic_lock_checked.png"
                imageSourceDisabledChecked: "asset:///images/icons/ic_lock_disabled_checked.png"
                imageSourceDisabledUnchecked: "asset:///images/icons/ic_lock_disabled_unchecked.png"
                imageSourcePressedChecked: "asset:///images/icons/ic_lock_default.png"
                imageSourcePressedUnchecked: "asset:///images/icons/ic_lock_checked.png"

                checked: true
                enabled: true
            }
        }
        
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }
        
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }
        
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }
        
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            ImageToggleButton {
                horizontalAlignment: HorizontalAlignment.Center
                
                imageSourceDefault: "asset:///images/icons/ic_lock_default.png"
                imageSourceChecked: "asset:///images/icons/ic_lock_checked.png"
                imageSourceDisabledChecked: "asset:///images/icons/ic_lock_disabled_checked.png"
                imageSourceDisabledUnchecked: "asset:///images/icons/ic_lock_disabled_unchecked.png"
                imageSourcePressedChecked: "asset:///images/icons/ic_lock_default.png"
                imageSourcePressedUnchecked: "asset:///images/icons/ic_lock_checked.png"
                
                checked: true
                enabled: false
            }
        }
    }
}