//
//  APSURLSessionTask.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @abstract A network service that handles HTTP GET/POST requests and automatically parses the response to the
 * callbacks.  Use this class instead of NSURLSessionDataTask.
 *
 * @description A reusable class that takes an NSURLRequest instance, makes a network request, parses the
 * HTTPURLResponse body and makes the callback with the different payload types (NSData/NSString/NSDictionary)
 * based on the APIs.
 *
 * Use one of the factory methods, @{ref taskWithDefaultCachePolicy} and @{ref taskWithIgnoringCachePolicy}
 * to instantiate an object.
 *
 * The class also supports optional callbacks to handle:
 * 1) Non-200 HTTP response code, e.g. unsuccessful callback
 * 2) When the network response returns with NSError, e.g. error callback
 * 3) When there is an NSException occurs during the response parsing, e.g. exception callback.
 *
 */
@interface APSURLSessionTask : NSObject


/**
 * Start a new network request with a callback to return an NSData payload.
 * @param request An URL request object.
 * @param successfulHandler A required completion block called with NSData payload from HTTP 200 result.
 * @param unsuccessfulHandler An optional completion block called from HTTP non-200 result.
 * @param errorHandler An optional completion block called when the underlying NSURLSessionDataTask returns an NSError.
 * @param exceptionHandler An optional completion block called when there is an NSException thrown inside the method.
 */
- (void)     startWithRequest:(NSURLRequest *)request
    successfulHandlerWithData:(void (^)(NSData *payload))successfulHandler
          unsuccessfulHandler:(void (^ _Nullable)(NSHTTPURLResponse *response, NSError *error))unsuccessfulHandler
                 errorHandler:(void (^ _Nullable)(NSError *error))errorHandler
             exceptionHandler:(void (^ _Nullable)(NSException *exception, NSError * _Nullable error))exceptionHandler;

/**
 * Start a new network request with a callback to return an NSString payload.
 * @param request An URL request object.
 * @param successfulHandler A required completion block called with NSData payload from HTTP 200 result.
 * @param unsuccessfulHandler An optional completion block called from HTTP non-200 result.
 * @param errorHandler An optional completion block called when the underlying NSURLSessionDataTask returns an NSError.
 * @param exceptionHandler An optional completion block called when there is an NSException thrown inside the method.
 */
- (void)       startWithRequest:(NSURLRequest *)request
    successfulHandlerWithString:(void (^)(NSString *payload))successfulHandler
            unsuccessfulHandler:(void (^ _Nullable)(NSHTTPURLResponse *response, NSError *error))unsuccessfulHandler
                   errorHandler:(void (^ _Nullable)(NSError *error))errorHandler
               exceptionHandler:(void (^ _Nullable)(NSException *exception, NSError * _Nullable error))exceptionHandler;

/**
 * Start a new network request with a callback to return an NSDictionary payload.
 * @param request An URL request object.
 * @param successfulHandler A required completion block called with NSData payload from HTTP 200 result.
 * @param unsuccessfulHandler An optional completion block called from HTTP non-200 result.
 * @param errorHandler An optional completion block called when the underlying NSURLSessionDataTask returns an NSError.
 * @param exceptionHandler An optional completion block called when there is an NSException thrown inside the method.
 */
- (void)           startWithRequest:(NSURLRequest *)request
    successfulHandlerWithDictionary:(void (^)(NSDictionary *payload))successfulHandler
                unsuccessfulHandler:(void (^ _Nullable)(NSHTTPURLResponse *response, NSError *error))unsuccessfulHandler
                       errorHandler:(void (^ _Nullable)(NSError *error))errorHandler
                   exceptionHandler:(void (^ _Nullable)(NSException *exception, NSError * _Nullable error))exceptionHandler;


- (instancetype)init NS_UNAVAILABLE; /** Use one of the class methods instead. */

#pragma mark - Factory methods

/**
 * Return an instance with default cache policy, e.g., the task can returns a cached result
 * if the request was done previously with the default TTL cache policy.
 */
+ (APSURLSessionTask *)taskWithDefaultCachePolicy;

/**
 * Return an instance with ignoring local cache policy, e.g., the task will always makes
 * a network request.
 */
+ (APSURLSessionTask *)taskWithIgnoringCachePolicy;

@end

NS_ASSUME_NONNULL_END
