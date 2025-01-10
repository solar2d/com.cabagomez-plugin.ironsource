//
//  DTBAdLoader.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"
#import "DTBAdSize.h"
#import "DTBAdCallback.h"

#define A9_BID_ID_KEY        @"amzn_b"
#define A9_HOST_KEY          @"amzn_h"
#define A9_PRICE_POINTS_KEY  @"amznslots"
#define A9_VID_KEY           @"amzn_vid"
#define A9_SKADN_KEY         @"amzn_skadn"
#define APS_VIDEO_FLAG       @"isv"
#define APS_VIDEO_TYPE       @"vtype"
#define APS_VIDEO_SKIP_AFTER @"skipafter"
#define APS_APP_KEY          @"appkey"

@interface DTBAdLoader : NSObject

@property (nonatomic, copy) NSString *_Nullable slotGroup APS_DEPRECATED_MESSAGE();
@property (nonatomic, copy) NSString * _Nonnull correlationId;

- (void)setSizes:(DTBAdSize * _Nonnull)size, ... NS_REQUIRES_NIL_TERMINATION APS_DEPRECATED_MESSAGE();

- (void)setAdSizes:(NSArray *_Nonnull) adSizes APS_DEPRECATED_MESSAGE();

- (void)putCustomTarget:(NSString * _Nonnull)value withKey:(NSString *_Nonnull) key APS_DEPRECATED_MESSAGE("Use -[APSAdRequest setCustomTarget:forKey instead");

- (void)loadAd:(id<DTBAdCallback>  _Nonnull) callback APS_DEPRECATED_MESSAGE("Use -[APSAdRequest loadAdWithCompletionHandler:] instead");

- (NSError * _Nullable)loadSmartBanner:(id<DTBAdCallback>  _Nonnull) callback APS_DEPRECATED_MESSAGE();

- (void) setAutoRefresh APS_DEPRECATED_MESSAGE("Use -[APSAdRequest setAutoRefresh] instead");

- (void) stop APS_DEPRECATED_MESSAGE();

- (void)setAutoRefresh:(int) seconds APS_DEPRECATED_MESSAGE("Use -[APSAdRequest setAutoRefreshDurationInSeconds:] instead.");

- (void) pauseAutorefresh APS_DEPRECATED_MESSAGE();
- (void) resumeAutorefresh APS_DEPRECATED_MESSAGE();

- (void)setRefreshFlag:(BOOL) flag APS_DEPRECATED_MESSAGE();

@end
