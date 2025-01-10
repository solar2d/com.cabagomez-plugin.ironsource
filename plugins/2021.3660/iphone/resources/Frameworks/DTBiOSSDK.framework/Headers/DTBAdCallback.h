//
//  DTBAdCallback.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.


#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"
#import "DTBAdResponse.h"
#import "DTBAdErrorInfo.h"

@protocol DTBAdCallback

@optional
- (void)onFailure:(DTBAdError) error APS_DEPRECATED_MESSAGE("Use APSLoadAdCompletionHandler with error != nil instead.");
- (void)onFailure:(DTBAdError)error dtbAdErrorInfo:(DTBAdErrorInfo *) dtbAdErrorInfo APS_DEPRECATED_MESSAGE();

@required
- (void)onSuccess:(DTBAdResponse *) adResponse APS_DEPRECATED_MESSAGE("Use APSLoadAdCompletionHandler with error == nil instead.");

@end
