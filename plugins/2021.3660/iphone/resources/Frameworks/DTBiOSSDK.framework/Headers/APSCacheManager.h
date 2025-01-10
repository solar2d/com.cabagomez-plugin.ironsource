//
//  APSCacheManager.h
//  DTBiOSSDK
//
//  Copyright © 2021 amazon.com. All rights reserved.
//

#ifndef APSCacheManager_h
#define APSCacheManager_h

#import <Foundation/Foundation.h>
#import "APSCacheData.h"
#import "APSDeprecatedMessage.h"

@interface APSCacheManager : NSObject

+ (void)addAdMobCacheWithRequestId:(NSString *)requestId cacheData:(APSCacheData *) cacheData APS_DEPRECATED_MESSAGE();
+ (void) removeExpiredAdMobCaches APS_DEPRECATED_MESSAGE();
+ (void)removeAdMobCacheWithRequestId:(NSString *) requestId APS_DEPRECATED_MESSAGE();
+ (NSMutableDictionary *) getAdMobCacheDataDictionary APS_DEPRECATED_MESSAGE();
+ (APSCacheData *)getAdMobCacheWithRequestId:(NSString *) requestId APS_DEPRECATED_MESSAGE();
+ (BOOL)containsAutoRefreshRequestId:(NSString *) requestId APS_DEPRECATED_MESSAGE();
+ (void)addAutoRefreshId:(NSString *) requestId APS_DEPRECATED_MESSAGE();
@end


#endif /* APSCacheManager_h */
