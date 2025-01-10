//
//  APSAd+UnityLevelPlayAdditions.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import "APSAd.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Use the constant as a key to set the network data for APS.
 *
 * [IronSource setNetworkDataWithNetworkKey:APS_NETWORK_KEY andNetworkData:networkData];
 */
#define APS_NETWORK_KEY @"APS"

@interface APSAd (UnityLevelPlayAdditions)

/**
 * Use this method to build UnityLevelPlay (previously known as IronSource) APS network data.
 * [IronSource setNetworkDataWithNetworkKey:@"APS" andNetworkData:[ad networkDataWithKey:IS_BANNER]];
 *
 * @param key The constant key string of the network data dictionary. The constants, e.g., IS_BANNER, IS_INTERSTITIAL
 * are defined in IronSource.h.
 * @return A dictionary of APS network data.
 */
- (NSDictionary *)networkDataWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
