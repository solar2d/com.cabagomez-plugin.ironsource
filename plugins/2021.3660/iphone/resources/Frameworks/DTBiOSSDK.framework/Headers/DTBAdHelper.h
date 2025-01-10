//
//  DTBAdHelper.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"
#import "DTBExpectedSize.h"

#define APS_ADMOB_CONST_SLOT_UUID             @"slotUUId"
#define APS_ADMOB_CONST_REQUEST_ID            @"requestId"
#define APS_ADMOB_CONST_SLOT_GROUP            @"slotGroup"
#define APS_ADMOB_CONST_WIDTH                 @"width"
#define APS_ADMOB_CONST_HEIGHT                @"height"
#define APS_ADMOB_CONST_CCPA_APS_PRIVACY      @"aps_privacy"
#define APS_ADMOB_CONST_CCPA_US_PRIVACY       @"us_privacy"
#define APS_ADMOB_CONST_ADAPTER_VERSION_NAME  @"custom_event_adapter_version"
#define APS_ADMOB_CONST_ADAPTER_VERSION_VALUE @"2.0"

#define APS_AAX_PRICE_POINT_LENGTH            12

#define COMPARE_LESS_THAN_OR_EQUAL_TO         @"leq"
#define COMPARE_GREATER_THAN_OR_EQUAL_TO      @"geq"
#define COMPARE_EQUAL_TO                      @"eq"

NS_ASSUME_NONNULL_BEGIN
@class DTBAdResponse;

@interface DTBAdHelper : NSObject

+ (NSError * _Nonnull)createAmazonErrorWithCode:(NSInteger) code APS_DEPRECATED_MESSAGE("Use +[APSError errorWithCode:] instead.");
+ (NSError * _Nonnull)createAmazonErrorWithCode:(NSInteger)code withMessage:(NSString *) msg APS_DEPRECATED_MESSAGE();

// ADMOB

+ (BOOL)validateAdMobBannerCustomEventWithExpectedSizeHandler:(id<DTBExpectedSize>)expectedSizeHandler serverParameter:(NSString *)serverParameter parameters:(NSDictionary *_Nullable) params APS_DEPRECATED_MESSAGE();

+ (BOOL)validateAdMobInterstitialCustomEvent:(NSString *)serverParameter parameters:(NSDictionary *_Nullable) params APS_DEPRECATED_MESSAGE("Use [APSAd isValidPricePoint:] instead.");

+ (UIView * _Nonnull)viewForAdView:(UIView * _Nonnull)adView
               expectedSizeHandler:(id<DTBExpectedSize> _Nonnull)expectedSizeHandler
                     requestedSize:(CGSize) requestedSize APS_DEPRECATED_MESSAGE();

+ (UIView * _Nonnull)viewForAdView:(UIView * _Nonnull)adView
                      expectedSize:(CGSize)expectedSize
                     requestedSize:(CGSize) requestedSize APS_DEPRECATED_MESSAGE();

+ (BOOL)handleBannerBidsWith:(id<DTBExpectedSize> _Nonnull)expectedSizeHandler withParams:(NSDictionary *_Nullable) params APS_DEPRECATED_MESSAGE();

+ (BOOL) isFetchManagerPresentForSmartBanner APS_DEPRECATED_MESSAGE();

+ (void)skadnHelper:(NSString *)label withInfo:(NSString *) info APS_DEPRECATED_MESSAGE("Use +[APSStoreKit processEvent:options:] instead.");

+ (NSString *) generateRandomUniqueNumber APS_DEPRECATED_MESSAGE();

+ (NSArray *)createAdMobBannerRequestKeyword:(NSString * _Nonnull)slotUUId
                                       width:(NSInteger)width
                                      height:(NSInteger)height
                                      extras:(NSDictionary *_Nullable) extras APS_DEPRECATED_MESSAGE("Use +[APSAd keywordsWithSlotUUID:width:height:] instead.");
+ (NSArray *)createAdMobBannerRequestKeyword:(NSString * _Nonnull)slotUUId
                                       width:(NSInteger)width
                                      height:(NSInteger) height APS_DEPRECATED_MESSAGE("Use +[APSAd keywordsWithSlotUUID:width:height:] instead.");;

+ (NSArray *)createAdMobInterstitialRequestKeyword:(NSString *_Nonnull) slotUUId APS_DEPRECATED_MESSAGE("Use +[APSAd keywordsWithSlotUUID:] instead.");
+ (NSArray *)createAdMobInterstitialRequestKeyword:(NSString * _Nonnull)slotUUId extras:(NSDictionary *_Nullable) extras APS_DEPRECATED_MESSAGE("Use +[APSAd keywordsWithSlotUUID:] instead.");

+ (NSArray *)createAdMobBannerRequestKeywordWithSlotGroup:(NSString *_Nonnull) slotGroup APS_DEPRECATED_MESSAGE();
+ (NSArray *)createAdMobBannerRequestKeywordWithSlotGroup:(NSString * _Nonnull)slotGroup
                                                   extras:(NSDictionary *_Nullable) extras APS_DEPRECATED_MESSAGE();

+ (NSString * _Nullable)getValueForKeyFromAdMobKeywords:(NSArray *)adMobKeywords key:(NSString *) key APS_DEPRECATED_MESSAGE();
+ (BOOL)validateAdMobCustomSingleEventPricePoint:(NSString *)serverParameter parameters:(NSDictionary *_Nullable) params APS_DEPRECATED_MESSAGE("Use [APSAd isValidPricePoint:] instead.");
+ (NSString *)reverseString:(NSString *) input APS_DEPRECATED_MESSAGE();
+ (BOOL)validateAdMobBannerCustomEventWithExpectedSizeHandlerGeneric:(id<DTBExpectedSize>)expectedSizeHandler serverParameter:(NSString *)serverParameter parameters:(NSDictionary * _Nullable)params isSpp:(BOOL) isSpp APS_DEPRECATED_MESSAGE();
+ (BOOL)validateAdMobInterstitialCustomEventGeneric:(NSString *)serverParameter parameters:(NSDictionary * _Nullable)params isSpp:(BOOL) isSpp APS_DEPRECATED_MESSAGE();

+ (void)sendAdapterSuccessEndEventWithEndTime:(NSNumber *)endTime
                                    startTime:(NSNumber *)startTime
                               adapterVersion:(NSString *)version
                                        bidId:(NSString *)bidId
                                correlationId:(NSString *)correlationId;

+ (void)sendAdapterFailureEndEventWithEndTime:(NSNumber *)endTime
                                    startTime:(NSNumber *)startTime
                               adapterVersion:(NSString *)version
                                correlationId:(NSString *)correlationId;

+ (void)setAdapterVersion:(NSString *)version;

@end

NS_ASSUME_NONNULL_END
