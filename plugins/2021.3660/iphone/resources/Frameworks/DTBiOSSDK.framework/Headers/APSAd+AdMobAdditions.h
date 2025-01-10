//
//  APSAd+AdMobAdditions.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import <DTBiOSSDK/APSAd.h>

NS_ASSUME_NONNULL_BEGIN

@class DTBAdResponse;

@interface APSAd (AdMobAdditions)

/**
 * A utility method to build keywords property for Google AdMob's GADRequest from a slot UUID.
 *
 * GADBannerView *adView = ...;
 * GADRequest *request = [GADRequest request];
 * request.keywords = [APSAd keywordsWithSlotUUID:@"a_slot_uuid"];
 * [adView loadRequest:request];
 *
 * @param slotUUID A slot UUID string.
 * @return keywords string array used by the AdMob adpater.
 */
+ (NSArray<NSString *> * _Nullable)keywordsWithSlotUUID:(NSString *)slotUUID;

/**
 * A utility method to build keywords property for Google AdMob's GADRequest from a slot UUID and a banner ad format.
 * The method will throw a runtime exception if the ad format is not a banner type in the development environment and
 * return nil in production.
 *
 * GADBannerView *adView = ...;
 * GADRequest *request = [GADRequest request];
 * request.keywords = [APSAd keywordsWithSlotUUID:@"a_slot_uuid" adFormat:APSAdFormatBanner];
 * [adView loadRequest:request];
 *
 * @param slotUUID A slot UUID string. Must not be empty.
 * @param adFormat An @{ref APSAdFormat}. Must be a banner format type, e.g. APSAdFormatBanner,
 * APSAdFormatLeaderBoard or APSAdFormatMREC.
 * @return keywords string array used by the AdMob adpater. If parameters have errrors, returns nil.
 */
+ (NSArray<NSString *> * _Nullable)keywordsWithSlotUUID:(NSString *)slotUUID adFormat:(APSAdFormat)adFormat;

/**
 * Utility method to verify that the serverParameter provided by Admob callback is valid.
 * @param serverParameter A server parameter provided by the GADCustomEventBanner protocol.
 * @return YES if the APSAd object contains a valid price point specified in the @{ref serverParameter}, NO otherwise.
 */
- (BOOL)isValidPricePoint:(NSString *)serverParameter;

@end

NS_ASSUME_NONNULL_END
