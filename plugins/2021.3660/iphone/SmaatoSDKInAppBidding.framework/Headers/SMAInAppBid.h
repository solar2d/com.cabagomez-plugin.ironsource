//
//  SMAInAppBid.h
//  SmaatoSDKInAppBidding
//
//  Created by siarhei on 05.05.20.
//  Copyright © 2020 Smaato Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
Class \c SMAInAppBid acts as container for whole body of ad response in OpenRTB 2.5 format
*/
@interface SMAInAppBid: NSObject

/// raw body of ad response
@property (nonatomic, copy, nullable, readonly) NSData *jsonBody;

/**
Create new instance of \c SMAInAppBid based on ad response body

@param  data Body of ad response. Must not be \c nil.

@return      The initialized \c SMAInAppBid or \c nil on failure
*/
+ (instancetype _Nullable)bidWithResponseData:(NSData *_Nonnull)data;

@end
