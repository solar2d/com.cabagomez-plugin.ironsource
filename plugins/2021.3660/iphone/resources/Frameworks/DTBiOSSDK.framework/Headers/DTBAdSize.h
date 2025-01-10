//
//  DTBAdSize.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"

#define DTB_VIDEO_WIDTH  ((int)640)
#define DTB_VIDEO_HEIGHT ((int)390)

typedef enum {
    VIDEO,
    DISPLAY,
    INTERSTITIAL
} ADType;

@interface DTBAdSize : NSObject
@property(readonly, nonatomic) ADType adType APS_DEPRECATED_MESSAGE("Use -[APSAd adFormat] instead.");
@property(readonly, nonatomic) NSInteger width APS_DEPRECATED_MESSAGE();
@property(readonly, nonatomic) NSInteger height APS_DEPRECATED_MESSAGE();
@property(readonly, nonatomic) NSString *slotUUID APS_DEPRECATED_MESSAGE("Use -[APSAd slotUUID] intead.");
@property(nonatomic, copy) NSDictionary *pubSettings APS_DEPRECATED_MESSAGE();


- (instancetype) init NS_UNAVAILABLE APS_DEPRECATED_MESSAGE();

- (instancetype)initBannerAdSizeWithWidth:(NSInteger)width height:(NSInteger)height andSlotUUID:(NSString *) slotUUID APS_DEPRECATED_MESSAGE();

- (instancetype)initInterstitialAdSizeWithSlotUUID:(NSString *) slotUUID APS_DEPRECATED_MESSAGE();

- (instancetype)initVideoAdSizeWithSlotUUID:(NSString *) slotUUID APS_DEPRECATED_MESSAGE();

- (instancetype)initVideoAdSizeWithPlayerWidth:(NSInteger)width height:(NSInteger)height andSlotUUID:(NSString *) slotUUID APS_DEPRECATED_MESSAGE();

- (instancetype)initVideoAdSizeWithPlayerWidth:(NSInteger)width height:(NSInteger)height slotUUID:(NSString *)slotUUID andPubSettings:(NSDictionary *) pubSettings APS_DEPRECATED_MESSAGE();

- (BOOL) isInterstitialAd APS_DEPRECATED_MESSAGE();

@end
