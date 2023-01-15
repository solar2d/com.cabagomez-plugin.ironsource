//
//  ISAppLovinAdapter.h
//  ISAppLovinAdapter
//
//  Copyright © 2022 IronSource. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IronSource/ISBaseAdapter+Internal.h"

static NSString * const AppLovinAdapterVersion = @"4.3.35";
static NSString * GitHash = @"1f2ec838a";

//System Frameworks For AppLovin Adapter
@import AdSupport;
@import AppTrackingTransparency;
@import AudioToolbox;
@import AVFoundation;
@import CFNetwork;
@import CoreGraphics;
@import CoreMedia;
@import CoreMotion;
@import CoreTelephony;
@import MessageUI;
@import SafariServices;
@import StoreKit;
@import SystemConfiguration;
@import UIKit;
@import WebKit;

@interface ISAppLovinAdapter : ISBaseAdapter

@end
