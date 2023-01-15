//
//  BUAppOpenAd.h
//  AFNetworking
//
//  Created by Willie on 2021/12/8.
//

#import "BUInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@class BUAppOpenAd, BUAdSlot;
@protocol BUAppOpenAdDelegate;

/// Callback for loading ad results.
/// @param appOpenAd Ad instance after successfully loaded.
/// @param error Loading error.
typedef void (^BUAppOpenAdLoadCompletionHandler)(BUAppOpenAd * _Nullable appOpenAd,
                                                 NSError * _Nullable error);

/// App-open ad object. Use it to load ads and display.
 __attribute__((objc_subclassing_restricted))
@interface BUAppOpenAd : BUInterfaceBaseObject

/// Ad event delegate.
@property (nonatomic, weak, nullable) id<BUAppOpenAdDelegate> delegate;

/// Create an instance by BUAdSlot.
/// @param slot A BUAdSlot instance. The necessary parameter is `ID`.
- (instancetype)initWithSlot:(BUAdSlot *)slot;

/// Load ad data.
/// @param timeout If the ad data is not successfully loaded within the timeout period, a timeout error will be returned. The unit is seconds.
/// @param completionHandler Callback for loading ad results.
- (void)loadOpenAdWithTimeout:(NSTimeInterval)timeout
            completionHandler:(nullable BUAppOpenAdLoadCompletionHandler)completionHandler;

/// Display ad. You need to call `loadOpenAdWithTimeout:completionHandler:` and succeed before call `presentFromRootViewController:`
/// @param rootViewController UIViewController that ad display depends on.
- (void)presentFromRootViewController:(UIViewController *)rootViewController;

@end


/// Ad event protocol.
@protocol BUAppOpenAdDelegate <NSObject>

@optional

/// The ad has been presented.
/// @param appOpenAd The BUAppOpenAd instance.
- (void)didPresentForAppOpenAd:(BUAppOpenAd *)appOpenAd;

/// The ad was clicked.
/// @param appOpenAd The BUAppOpenAd instance.
- (void)didClickForAppOpenAd:(BUAppOpenAd *)appOpenAd;

/// The ad was skipped.
/// @param appOpenAd The BUAppOpenAd instance.
- (void)didClickSkipForAppOpenAd:(BUAppOpenAd *)appOpenAd;

/// The ad countdown is over.
/// @param appOpenAd The BUAppOpenAd instance.
- (void)countdownToZeroForAppOpenAd:(BUAppOpenAd *)appOpenAd;

@end

NS_ASSUME_NONNULL_END
