//
//  APSError.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const APSErrorAdDomain;

/**
 * Enums to specify error codes.
 */
typedef NS_ENUM(NSInteger, APSErrorCode) {
    APSErrorCodeServerError,
    APSErrorCodeNoFill,
    APSErrorCodeInvalidAppKey,
    APSErrorCodeOther
};

/**
 * An APS Error class.
 */
@interface APSError : NSObject

/**
 * A utility method to create an NSError from an errorCode.
 * @param errorCode An error code of @{ref APSErrorcode}.
 */
+ (NSError *)errorWithCode:(APSErrorCode)errorCode;

@end

NS_ASSUME_NONNULL_END
