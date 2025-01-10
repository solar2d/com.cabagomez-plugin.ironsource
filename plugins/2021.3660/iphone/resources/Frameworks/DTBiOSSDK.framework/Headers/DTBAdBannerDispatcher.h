//
//  DTBAdDispatcher.h
//  DTBiOSSDK
//
//  Copyright (c) 2022 Amazon Publisher Services. All rights reserved.

#import <UIKit/UIKit.h>
#import "APSDeprecatedMessage.h"
#import "DTBAdDispatcher.h"

@protocol DTBAdBannerDispatcherDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface DTBAdBannerDispatcher : DTBAdDispatcher

- (instancetype)initWithAdFrame:(CGRect)frame delegate:(id<DTBAdBannerDispatcherDelegate>) delegate APS_DEPRECATED_MESSAGE("Use APSAdController instead.");

- (void)fetchBannerAdWithParameters:(NSDictionary *) parameters APS_DEPRECATED_MESSAGE();

- (void)fetchBannerAd:(NSString *_Nonnull) htmlString APS_DEPRECATED_MESSAGE("Use -[APSAdController fetchAd:extras:] instead.");

- (void)fetchBannerAd:(NSString * _Nonnull)htmlString params:(NSDictionary *_Nullable) params APS_DEPRECATED_MESSAGE("Use -[APSAdController fetchAd:extras:] instead.");

@end

@protocol DTBAdBannerDispatcherDelegate<NSObject>

- (void)adDidLoad:(UIView *_Nonnull) adView APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adDidLoad:] instead.");
- (void)adFailedToLoad:(UIView * _Nullable)banner errorCode:(NSInteger) errorCode APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adFailedToLoad:] instead.");
- (void)bannerWillLeaveApplication:(UIView *) adView APS_DEPRECATED_MESSAGE();
- (void) impressionFired APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adImpressionFired:] instead.");

@optional
- (void) adClicked APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adClicked:] instead.");;
@end

NS_ASSUME_NONNULL_END
