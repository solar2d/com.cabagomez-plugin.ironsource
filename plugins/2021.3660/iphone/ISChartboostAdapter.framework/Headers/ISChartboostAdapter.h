//
//  ISChartboostAdapter.h
//  ISChartboostAdapter
//
//  Copyright © 2023 ironSource Mobile Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IronSource/ISBaseAdapter+Internal.h>
#import <IronSource/IronSource.h>

static NSString * const ChartboostAdapterVersion = @"4.3.15";
static NSString * Githash = @"9b65801b4";

//System Frameworks For Chartboost Adapter

@import AdSupport;
@import AVFoundation;
@import CoreGraphics;
@import CoreMedia;
@import StoreKit;
@import UIKit;
@import WebKit;

@interface ISChartboostAdapter : ISBaseAdapter

@end
