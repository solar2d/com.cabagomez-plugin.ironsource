//
//  APSAdDelegate.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#ifndef APSAdDelegate_h
#define APSAdDelegate_h

NS_ASSUME_NONNULL_BEGIN

@class APSAd;

/**
 * @abstract Ad presentation lifecycle callback.
 * @description This is the unifed ad lifecycle callback for banners/interstitials/rewarded videos.
 */
@protocol APSAdDelegate<NSObject>

/**
 * Called when the ad was loaded and ready to be rendered.
 * @param ad The APSAd object.
 */
- (void)adDidLoad:(APSAd *)ad;
/**
 * Called when the ad failed to load. Look at the ad.errorCode for more information.
 * @param ad The APSAd object.
 */
- (void)adFailedToLoad:(APSAd *)ad;
/**
 * Called when the ad was clicked.
 * @param ad The APSAd object.
 */
- (void)adClicked:(APSAd *)ad;
/**
 * Called when the ad viewable impression is fired.
 * @param ad The APSAd object.
 */
- (void)adImpressionFired:(APSAd *)ad;

@optional

/**
 * Called when the ad was added into a view hierarchy and visible.
 * @param ad The APSAd object.
 */
- (void)adDidAppear:(APSAd *)ad;
/**
 * Called when the ad was removed from the view hierarchy.
 * @param ad The APSAd object.
 */
- (void)adDidDisappear:(APSAd *)ad;
/**
 * Called when the ad had an error. Look at the ad.errorCode for more information.
 * @param ad The APSAd object.
 */
- (void)adDidThrowError:(APSAd *)ad;
/**
 * Called when the video ad playback is complete.
 * @param ad The APSAd object.
 */
- (void)adVideoPlaybackCompleted:(APSAd *)ad;

@end

NS_ASSUME_NONNULL_END

#endif /* APSAdDelegate_h */
