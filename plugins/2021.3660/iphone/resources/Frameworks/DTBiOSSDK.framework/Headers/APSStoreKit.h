//
//  APSStoreKit.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import "SKAdNetworkInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * APS Store Kit provides interfaces to Apple StoreKit Ad Netwrok (SKAdNetwork).
 */
@interface APSStoreKit : NSObject

/**
 * Process an storekit event.
 * @param eventName The event name string.
 * @param options The event parameter string.
 */
+ (void)processEvent:(NSString *)eventName options:(NSString *)options;

/**
 * @return YES if the debug feature flag "skadn_params_hardcode" is enabled or the skadnTestMode is set to YES.
 */
+ (BOOL)shouldUseMockResponse;

+ (NSString * _Nullable )mockResponseVersion;

/**
 * @return The mocked SKAdNetwork payload used for StoreKit creative testing.
 */
+ (NSDictionary<NSString *, NSObject *> *)mockResponseDictionary:(NSString *)version;

/**
 * Add SKAdNetwork network id array from the Info.plist with the "skadn" key.
 */
+ (void)addSkadnParamsIfExists:(NSMutableDictionary *)params;

/**
 * Parse the SKAdNetwork key/values from the AAX bid response into a dictionary for SKAN legacy 2.0 response format.
 */
+ (NSDictionary * _Nullable)parseLegacySKAdNetworkParamsFromAAXResponse:(NSDictionary *)rawResponseSKAdnDictionary;

/**
 * Parse the SKAdNetwork key/values from the AAX bid response into a SKAdNetworkInfo object for SKAN oRTB response format.
 */
+ (SKAdNetworkInfo * _Nullable)parseSKAdNetworkInfoFromAAXResponse:(NSDictionary *)rawResponseSKAdnDictionary;

/**
 * For SKAdnewtork phase 2, send the SKAdNetwork entries every 24 hours under a sampling rate.
 */
+ (void)sendSKAdNetworkChecksumPacketIfNeededForPhase2;

/**
 * Handle SK Ad Network parameters from bid queue and opens SK url if available
 */
/**
 * Handle SK Ad Network parameters from bid queue.
 * It'll open the destination URL by either the StoreKit Product Page or a web browser.
 */
+ (void)skadnHelper:(NSString *)label withInfo:(NSString *)info;

@end

NS_ASSUME_NONNULL_END
