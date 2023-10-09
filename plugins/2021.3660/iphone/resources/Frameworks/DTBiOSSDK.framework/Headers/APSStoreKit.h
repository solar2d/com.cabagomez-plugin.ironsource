//
//  APSStoreKit.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 APS Store Kit provides interfaces to Apple StoreKit Ad Netwrok (SKAdNetwork).
 */
@interface APSStoreKit : NSObject

/**
 Process an storekit event.
 @param eventName The event name string.
 @param options The event parameter string.
 */
+ (void)processEvent:(NSString *)eventName options:(NSString *)options;

@end

NS_ASSUME_NONNULL_END
