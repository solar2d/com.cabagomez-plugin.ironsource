//
//  APSAdController.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class APSAd;
@protocol APSAdDelegate;

/**
 * @abstract Ad controller fetches the input ad object and manages the ad presentation lifecycle.
 */
@interface APSAdController : NSObject

- (instancetype)init NS_UNAVAILABLE;
/**
 * @abstract Init with an @{ref APSAdDelegate}.
 *
 * @param delegate A delegate conforming the @{ref APSAdDelegate}. The delegate will be called based on the
 * ad presentation lifecycle.
 * @return A new instance of APSAdController.
 */
- (instancetype)initWithDelegate:(id<APSAdDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/**
 * @abstract Set an ad frame.
 *
 * @param frame A CGRect frame to set the banner ad view position.
 */
- (void)setAdFrame:(CGRect)frame;

/**
 * @abstract Fetch ad with optional extra dictionary.
 *
 * @param ad The @{ref APSAd} object to fetch. If it is a banner ad but the ad frame is not set through @{ref setAdFrame},
 * it will throw an NSException in development and will not fetch ad but does not throw an exception in production.
 * @param extras The optional NSDictionary that is passed into the ad view.
 */
- (void)fetchAd:(APSAd *)ad extras:(NSDictionary * _Nullable)extras;

/**
 * @abstract A utility method to present an interstitial ad from an input root view controller.
 * @param controller A presenting UIViewController.
 * @note If the ad is not an interstitial ad, it will throw an NSException in development and will not show the ad but
 * does not throw an exception in production.
 */
- (void)showFromViewController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
