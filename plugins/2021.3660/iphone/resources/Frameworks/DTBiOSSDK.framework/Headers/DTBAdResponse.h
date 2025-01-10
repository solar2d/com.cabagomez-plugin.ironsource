//
//  DTBAdResponse.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"
#import "DTBAdSize.h"
#import "SKAdNetworkInfo.h"

NS_ASSUME_NONNULL_BEGIN

@class DTBAdLoader;
@class DTBPricePoint;

typedef enum {
    NETWORK_ERROR = 81,
    NETWORK_TIMEOUT,
    NO_FILL,
    INTERNAL_ERROR,
    REQUEST_ERROR
} DTBAdError;

@interface DTBAdResponse : NSObject

@property (nonatomic, copy) NSString *bidId APS_DEPRECATED_MESSAGE();

@property (nonatomic) BOOL isVideo APS_DEPRECATED_MESSAGE("Use -[APSAd adFormat] instead.");

@property (nonatomic, copy) NSDictionary *kvp APS_DEPRECATED_MESSAGE();

@property (nonatomic, copy, nullable) NSDictionary *skAdNetworkParams APS_DEPRECATED_MESSAGE();

@property (nonatomic, copy, nullable) NSArray *clickTrackersArray APS_DEPRECATED_MESSAGE();

@property (nonatomic, strong, nullable) DTBAdLoader *dtbAdLoader APS_DEPRECATED_MESSAGE();

/** The number of seconds of video playback before a video can be skipped. If the value is zero, the video is not skippable.
 */
@property (nonatomic, assign, readonly) NSInteger videoSkipAfterDurationInSeconds APS_DEPRECATED_MESSAGE();
/** This represents the video inventory type from AAX if video flag is set to true
 */
@property (nonatomic, copy, readonly) NSString *videoInventoryType APS_DEPRECATED_MESSAGE("Use -[APSAd adFormat] instead.");

@property (nonatomic, strong, nullable) SKAdNetworkInfo *skanInfo;

/**
 * Add a non-null price point into an internal array.
 * @param pp A non-null  DTBPricePoint object to be added.
 */
- (void)addDTBPricePoint:(DTBPricePoint *) pp APS_DEPRECATED_MESSAGE();

/**
 * @return A nullable crid string.
 */
- (NSString *_Nullable) crid APS_DEPRECATED_MESSAGE();

/**
 * @return A host name string.
 */
- (NSString *_Nonnull) hostname APS_DEPRECATED_MESSAGE();

/**
 * @return An array of DTBAdSize objects from all DTBPricePoint objects in the internal array.
 */
- (NSArray *) adSizes APS_DEPRECATED_MESSAGE();

/**
 * @deprecated
 */
- (NSString * _Nullable)pricePoints:(DTBAdSize * _Nullable)adSize __deprecated;

/**
 * @deprecated
 */
- (NSString * _Nullable)defaultPricePoints __deprecated;

/**
 * @return A DTBAdSize of the first DTBPricePoint in the internal array.
 */
- (DTBAdSize *_Nullable) adSize APS_DEPRECATED_MESSAGE("Use -[APSAd adFormat] instead");

/**
 * @return A dictionary with string keys and values of custom targeting from all price points in the internal array.
 */
- (NSDictionary<NSString *, NSString *> *_Nullable) customTargeting APS_DEPRECATED_MESSAGE("Use -[APSAd customTargeting] instead.");

/**
 * @return An ad loader object. Returns nil if the ad loader has not been previously set.
 */
- (DTBAdLoader *_Nullable) getAdLoader APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
