//
//  ISAPSAdapter.h
//  ISAPSAdapter
//
//  Copyright © 2023 ironSource Mobile Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IronSource/ISBaseAdapter+Internal.h>

static NSString * const APSAdapterVersion = @"4.3.7";
static NSString * Githash = @"";

@import CoreLocation;
@import CoreTelephony;
@import MediaPlayer;
@import StoreKit;
@import SystemConfiguration;
@import QuartzCore;

@interface ISAPSAdapter : ISBaseAdapter

@end

