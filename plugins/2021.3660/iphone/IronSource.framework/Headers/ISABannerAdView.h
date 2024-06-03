//
//  ISNBannerAdView.h
//  IronSource
//
//  Copyright © 2024 IronSource. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ISABannerAdInfo.h"
#import "ISABannerAdViewDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Class responsible for handling the operations and callbacks of a banner ad.
 */
@interface ISABannerAdView : UIView

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

/**
 The delegate for the ad callbacks.
 Set this delegate in order to receive callbacks from the ad.
 The callbacks will be invoked on the main thread.
 */
@property(nonatomic, weak, nullable) id<ISABannerAdViewDelegate> delegate;

/**
 Contains information associated with the ad.
 */
@property(nonatomic, strong, readonly) ISABannerAdInfo* adInfo;

/**
 The view controller to show the ad on.
 Set this property if you did not already set it via `ISABannerAdRequest` when loading the ad.
 */
@property(nonatomic, weak, nullable) UIViewController* viewController;

NS_ASSUME_NONNULL_END

@end
