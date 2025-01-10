//
//  APSAd.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <DTBiOSSDK/APS.h>
#import <DTBiOSSDK/APSAdFormat.h>
#import <DTBiOSSDK/APSAdMediaType.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Ad lifecycle state.
 */
typedef NS_ENUM(NSInteger, APSAdState) {
    APSAdStateInitialized,
    APSAdStateLoaded,
    APSAdStateFetched,
    APSAdStateRendered,
    APSAdStateDisappeared,
    APSAdStateError,
    APSAdStateExit
};

/**
 * Ad lifecycle delegate calbacks.
 */
@protocol APSAdDelegate;


/**
 * @abstract The ad domain class.
 */
@interface APSAd : NSObject

/***
 * State of the ad in the lifecycle.
 */
@property (nonatomic, assign, readonly) APSAdState state;
/**
 * Raw ad response.
 */
@property (nonatomic, strong, readonly) NSObject *adResponse;
/**
 * Raw ad error.
 */
@property (nonatomic, strong, readonly) NSObject *adError;
/**
 * Slot UUID of the ad.
 */
@property (nonatomic, copy, readonly) NSString *slotUUID;
/**
 * Ad format type.
 */
@property (nonatomic, assign, readonly) APSAdFormat adFormat;
/**
 * Ad media type.
 */
@property (nonatomic, assign, readonly) APSAdMediaType adMediaType;
/**
 * Ad mediation network/server.
 */
@property (nonatomic, assign, readonly) APSAdNetwork adNetwork;
/**
 * Custom targeting dictionary.
 */
@property (nonatomic, copy, nullable, readonly) NSDictionary<NSString *, NSString *> *customTargeting;
/**
 * Mediation hints for mediation adapters.
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString *, NSString *> *mediationHints;
/**
 * Amazon slot string.
 */
@property (nonatomic, copy, readonly) NSString *amznSlots;
/**
 * Ad view is set to nil initially until an ad is fetched and ready to render.
 */
@property (nonatomic, strong, readonly, nullable) UIView *adView;
/**
 * Error code.
 */
@property (nonatomic, assign, readonly) NSInteger errorCode;

/**
 * @{ref APSAD} should not be instantiated directly. Use @{ref APSAdRequest} to load an ad.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * @abstract Create a new ad object from an existing ad and clone metadata.
 * @description @{ref APSAd} is a stateful object that can hold references to heavyweight ad view and others.
 * If we want to cache the ad object without the ad view, use this method to clone the object metadata into a new one.
 *
 * @param ad The ad object.
 */
+ (instancetype)adWithMetadataFromAd:(APSAd *)ad;

@end

NS_ASSUME_NONNULL_END
