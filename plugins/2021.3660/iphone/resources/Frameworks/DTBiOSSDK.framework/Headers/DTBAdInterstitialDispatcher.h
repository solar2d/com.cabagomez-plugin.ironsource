//
//  DTBAdInterstitialDispatcher.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"
#import "DTBAdDispatcher.h"
#import "DTBMediationConstants.h"

NS_ASSUME_NONNULL_BEGIN

@class DTBAdInterstitialDispatcher;

@protocol DTBAdInterstitialDispatcherDelegate<NSObject>

/// Sent when an interstitial ad has loaded.
- (void)interstitialDidLoad:(DTBAdInterstitialDispatcher *_Nullable ) interstitial APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adDidLoad:] instead.");

/// Sent when interstitial ad has failed to load.
- (void)            interstitial:(DTBAdInterstitialDispatcher * _Nullable )interstitial
    didFailToLoadAdWithErrorCode:(DTBAdErrorCode) errorCode APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adFailedToLoad:] instead.");

/// Sent when an interstitial is about to be shown.
- (void)interstitialWillPresentScreen:(DTBAdInterstitialDispatcher *_Nullable ) interstitial APS_DEPRECATED_MESSAGE();

/// Sent when an interstitial is about to be shown.
- (void)interstitialDidPresentScreen:(DTBAdInterstitialDispatcher *_Nullable ) interstitial APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adDidAppear:] instead.");

/// Sent when an interstitial is about to be dismissed.
- (void)interstitialWillDismissScreen:(DTBAdInterstitialDispatcher *_Nullable ) interstitial APS_DEPRECATED_MESSAGE();

/// Sent when an interstitial has been dismissed.
- (void)interstitialDidDismissScreen:(DTBAdInterstitialDispatcher *_Nullable ) interstitial APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adDidDisappear:] instead.");

/// Sent when an interstitial is clicked and an external application is launched.
- (void)interstitialWillLeaveApplication:(DTBAdInterstitialDispatcher *_Nullable ) interstitial APS_DEPRECATED_MESSAGE();

- (void)showFromRootViewController:(UIViewController *_Nonnull) controller APS_DEPRECATED_MESSAGE("Use -[APSAdController showFromViewController:] instead.");

- (void) impressionFired APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate impressionFired:] instead.");

@optional
- (void)videoPlaybackCompleted:(DTBAdInterstitialDispatcher *) interstitial APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adVideoPlaybackCompleted:] instead.");
- (void)adClicked APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adClicked:] instead.");
- (void)adDidThrowError APS_DEPRECATED_MESSAGE("Use -[APSAdDelegate adDidThrowError:] instead.");
@end


@interface DTBAdInterstitialDispatcher : DTBAdDispatcher

@property(nonatomic, weak) id<DTBAdInterstitialDispatcherDelegate> delegate APS_DEPRECATED_MESSAGE("Use APSAdController instead.");

@property(nonatomic, assign) BOOL interstitialLoaded APS_DEPRECATED_MESSAGE("Use APSAdController instead.");

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDelegate:(id<DTBAdInterstitialDispatcherDelegate>) delegate APS_DEPRECATED_MESSAGE("Use APSAdController instead.");
- (void)fetchAd:(NSString *) bidInfo APS_DEPRECATED_MESSAGE("Use APSAdController instead.");
- (void)fetchAdWithParameters:(NSDictionary *) params APS_DEPRECATED_MESSAGE("Use APSAdController instead.");
- (void)fetchAd:(NSString *)bidInfo params:(NSDictionary *_Nullable) params APS_DEPRECATED_MESSAGE("Use APSAdController instead.");
- (void)showFromController:(UIViewController *_Nonnull) controller APS_DEPRECATED_MESSAGE("Use APSAdController instead.");

- (void) interstitialWillAppear APS_DEPRECATED_MESSAGE("Use APSAdController instead.");
- (void) interstitialDidAppear APS_DEPRECATED_MESSAGE("Use APSAdController instead.");
- (void) interstitialWillDisappear APS_DEPRECATED_MESSAGE("Use APSAdController instead.");
- (void) interstitialDidDisappear APS_DEPRECATED_MESSAGE("Use APSAdController instead.");


+ (void)showInterstitialFromController:(UIViewController *_Nonnull) controller APS_DEPRECATED_MESSAGE("Use -[APSAdController showFromViewController:] instead.");

@end

NS_ASSUME_NONNULL_END
