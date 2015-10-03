import bb.cascades 1.2

Page {/*
    property int imageHeight: 150
    Container {
        layout: DockLayout {

        }
        background: Color.create("#c63d0f")
        //background: Color.LightGray
        topPadding: 6
        bottomPadding: 6
        leftPadding: 6
        rightPadding: 6
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Container {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 4
                }
                rightMargin: 6
                    Container {
                        layout: DockLayout {
                            
                        }
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        ImageView {
                            
                            scalingMethod: ScalingMethod.AspectFill
                            imageSource: "asset:///images/0/1.jpg"
                        }
                        Container {
                            preferredHeight: 75
                            horizontalAlignment: HorizontalAlignment.Fill
                            verticalAlignment: VerticalAlignment.Bottom
                            opacity: 0.6
                            background: Color.create("#ae734b")
                        }
                        Container {
                            horizontalAlignment: HorizontalAlignment.Fill
                            verticalAlignment: VerticalAlignment.Bottom
                            leftPadding: 6
                            Label {
                                horizontalAlignment: HorizontalAlignment.Right
                                textStyle.color: Color.White
                                textStyle.fontSize: FontSize.PointValue
                                textStyle.fontSizeValue: 5.0
                                text: "0:43:23"
                            }
                            Label {
                                textStyle.color: Color.White
                                textStyle.fontSize: FontSize.PointValue
                                textStyle.fontSizeValue: 5.0
                                text: "A pot of tea"
                            }
                        }    
                    }
                    ImageView {
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        scalingMethod: ScalingMethod.AspectFill
                        imageSource: "asset:///images/0/0.jpg"
                    }
                    ImageView {
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        scalingMethod: ScalingMethod.AspectFill
                        imageSource: "asset:///images/0/2.jpg"
                    }
                }
         //   }
            ScrollView {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 6
                }
                //Container on right, for all list items
                Container {
                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/1/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video name"
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }
                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/2/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video name"
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }

                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/3/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video's name is very long but it still is."
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }

                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/4/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video name"
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }

                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/5/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video name"
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }

                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/6/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video name"
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }

                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/7/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video name"
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }

                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/8/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video name"
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }

                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/9/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video name"
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }

                    Container {
                        layout: DockLayout {

                        }
                        //horizontalAlignment: HorizontalAlignment.Fill
                        //verticalAlignment: VerticalAlignment.Fill
                        Container {
                            background: Color.create("#ae734b")
                            opacity: 0.6
                            preferredHeight: imageHeight
                            preferredWidth: 1250
                            //horizontalAlignment: HorizontalAlignment.Fill
                            //verticalAlignment: VerticalAlignment.Fill
                        }
                        Container {
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }
                            ImageView {
                                preferredHeight: imageHeight
                                horizontalAlignment: HorizontalAlignment.Left
                                 verticalAlignment: VerticalAlignment.Center
                                imageSource: "asset:///images/10/0.jpg"
                                scalingMethod: ScalingMethod.AspectFit
                            }
                            Container {
                                layoutProperties: StackLayoutProperties {
                                    spaceQuota: 1
                                }
                                horizontalAlignment: HorizontalAlignment.Right
                                verticalAlignment: VerticalAlignment.Center
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "Video name"
                                }
                                Label {
                                    textStyle.fontSize: FontSize.XSmall
                                    horizontalAlignment: HorizontalAlignment.Right
                                    text: "0:23:51"
                                }
                            }
                        }
                        bottomMargin: 6
                    }
                }
            }
        }
    }*/
}
