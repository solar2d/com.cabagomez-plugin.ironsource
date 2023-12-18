//
//  SMAInAppBidding.h
//  SmaatoSDKInAppBidding
//
//  Created by siarhei on 05.05.20.
//  Copyright © 2020 Smaato Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SMAInAppBid;

/**
Class \c SMAInAppBidding provided methods to support In-App-Bidding solution when Smaato SDK acts
 as service for Smaato ad response rendering that is result of server-to-server exchange.
*/
@interface SMAInAppBidding: NSObject

/**
Save \c SMAInAppBid object into internal cache for future usage by SmaatoSDK public API for ad rendering and management.

@param bid    A bid object that contains ad response body. Must not be \c nil.
@param errorPtr  If any issue is found, the `error` parameter will contain error information and nil will be returned as method result

@return      If bid object is valid and processing completes successfully, the string result parameter
is returned. This string will contain unique identifier like "<ADSPACE_ID>:<SESSION_ID>", that can be used
to render ads based on this given bid.
*/
+ (NSString *_Nullable)saveBid:(SMAInAppBid *_Nonnull)bid error:(NSError *_Nullable *_Nullable)errorPtr;

@end
