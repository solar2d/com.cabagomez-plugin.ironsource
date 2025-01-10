//
//  DTBAdInterstitialViewController.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <AVFoundation/AVFoundation.h>
#import "APSDeprecatedMessage.h"

NS_ASSUME_NONNULL_BEGIN

@class DTBAdView;
@protocol DTBAdInterstitialDispatcherDelegate;

@interface DTBAdInterstitialViewController : UIViewController

@property(nonatomic, weak) DTBAdView *adView APS_DEPRECATED_MESSAGE();

@property(nonatomic, strong) id<DTBAdInterstitialDispatcherDelegate> dispatcherDelegate APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
