//
//  APSAdRequest.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "APSAdFormat.h"
#import "APSAdFormatProperties.h"

@class APSAd;

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract Ad load error enums
 * @description enum values of errors after loading an ad.
 */
typedef NS_ENUM(NSInteger, APSAdLoadError) {
    APSAdLoadErrorNetworkError,
    APSAdLoadErrorNetworkTimeOut,
    APSAdLoadErrorNoFill,
    APSAdLoadErrorInternalError,
    APSAdLoadErrorRequestError
};

/**
 * The load ad completion handler is called after the @{ref loadAdWithCompletionHandler} finishes
 * loading an ad.  If it is successful, the ad param will be instantiated and can be passed to the
 * @{ref APSAdController}.  If the load ad fails, the ad param can be used to create another
 * @{ref APSAdRequest} with the initWithAd: constructor and the error will
 * contain error.code with APSAdLoadError enum.
 */
typedef void (^APSLoadAdCompletionHandler)(APSAd *ad, NSError * _Nullable error);

/**
 * Ad request object.
 */
@interface APSAdRequest : NSObject

/**
 * Set auto refresh flag.  When it is set to YES, the ad request will attempt to load a new ad every specified interval
 * (default to 60 seconds) and will call the completion handler callback.  Call @{ref stopAutoRefresh} to ensure that
 * the auto refresh is reset and the next callback is stopped.
 */
@property (nonatomic, assign) BOOL autoRefresh;
/**
 * Set auto refresh duration in seconds.
 *
 * @note
 * 1. If the @{ref autoRefresh} is enabled, the default duration is 60 seconds.
 * 2. Setting this property will override the default value.
 * 3. If the setting value is 0, it will disable auto refresh.
 * 4. The minium duration is 20 seconds.  Any value below this will throw a runtime exception in development environment
 *  and will be reset to 60 seconds in production.
 */
@property (nonatomic, assign) NSInteger autoRefreshDurationInSeconds;

/**
 * @abstract Init a new instance from a slot UUID string.
 *
 * @param slotUUID A slot UUID string. If the parameter is nil or empty, it will throw an NSException in development
 * and will not set the slot UUID but does not throw an exception in production.
 * @return A new @{ref APSAdRequest} instance.
 * @note Use this constructor to create a new APSAdRequest from a slot UUID.
 */
- (instancetype)initWithSlotUUID:(NSString *)slotUUID;

/**
 * @abstract Init a new instance from an existing ad object.
 *
 * @param ad The @{ref APSAd} object. If the parameter is nil or ad's slot UUID is empty, it will throw an NSException in
 * development and will return nil but does not throw an exception in production.
 * @return A new @{ref APSAdRequest} instance.
 * @note Use this constructor to create a new APSAdRequest from the previous APSAd object returned
 * from the previous request.
 */
- (instancetype)initWithAd:(APSAd *)ad;

/**
 * @abstract Set the ad format.
 *
 * @param adFormat An ad format of @{ref APSAdFormat}.
 */
- (void)setAdFormat:(APSAdFormat)adFormat;

/**
 * @abstract Set the ad format.
 *
 * @param adFormat An ad format of @{ref APSAdFormat}.
 * @param properties AdFormatProperties (width, height) of @{APSAdFormatProperties}.
 */
- (void)setAdFormat:(APSAdFormat)adFormat withProperties:(APSAdFormatProperties *)properties;

/**
 * @abstract Load an ad with a completion callback.
 *
 * @param completionHandler A completion handler callback @{ref APSLoadAdCompletionHandler}. Check the error parameter
 * to make sure that load ad is complete without error. Once an ad is loaded, we can use the @{APSAdDispatcher} to
 * fetch the creative and manages the ad presentation lifecycle.
 */
- (void)loadAdWithCompletionHandler:(APSLoadAdCompletionHandler)completionHandler;

/**
 * @abstract Set additional custom target key/value to pass to the ad load request.
 *
 * @param value The key value. Cannot be nil.
 * @param key The key string. Cannot be nil.
 */
- (void)setCustomTarget:(NSString *)value forKey:(NSString *)key;

/**
 * @abstract Stop autorefresh.
 * @description If the request has auto refresh set to YES, this call will stop the next auto refresh timer.  However
 * it's possible there is a pending bid request that would result in the load commpletion handler to be called.  If
 * the request does not have the auto refresh set, the method will do nothing.
 */
- (void)stopAutoRefresh;

@end

NS_ASSUME_NONNULL_END
