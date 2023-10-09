//
//  DTBLog.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"

NS_ASSUME_NONNULL_BEGIN

// Log level for the DTBLog util class.
// Lower = finer-grained logs.
typedef enum
{
    DTBLogLevelAll   = 0,
    DTBLogLevelTrace = 10,
    DTBLogLevelDebug = 20,
    DTBLogLevelInfo  = 30,
    DTBLogLevelWarn  = 40,
    DTBLogLevelError = 50,
    DTBLogLevelFatal = 60,
    DTBLogLevelOff   = 70
} DTBLogLevel;

/**
 * Application implements this protocol if further manipulations besides NSLog are required
 *
 */
@protocol DTBLogDelegate
/**
 * delegate is call with a message originated from DTBLog
 */
- (void)onMessageLogged:(NSString *)message APS_DEPRECATED_MESSAGE("Use APSLoggerDelegate instead.");

@end


@protocol DTBLogTagDelegate

- (NSString * _Nonnull) requestedTag;
/**
 * delegate is call with a message originated from DTBLog
 */
- (void)onMessageLogged:(NSString *)message APS_DEPRECATED_MESSAGE();

@end

// Util class to log the events in DTB Mobile API.
// Logger works only when the constant DTB_DEBUG_MODE is set to 1 in DTBConstants.h file
// If DTB_DOMAIN is set to BETA then default log level is DTBLogLevelAll
// otherwise default Log level is DTBLogLevelError.
@interface DTBLog : NSObject

// Returns the current set log level
+ (DTBLogLevel)logLevel APS_DEPRECATED_MESSAGE();

// Set's the log level
+ (void)setLogLevel:(DTBLogLevel) level APS_DEPRECATED_MESSAGE();

+ (void)setDelegate:(id<DTBLogDelegate> _Nullable)delegate APS_DEPRECATED_MESSAGE("Use +[APSLogger setDelegate:] instead.");

+ (void)setTagDelegate:(id<DTBLogTagDelegate> _Nullable)delegate APS_DEPRECATED_MESSAGE();

+ (void)trace:(NSString *)message APS_DEPRECATED_MESSAGE("Use +[APSLogger trace:] instead.");
+ (void)debug:(NSString *)message APS_DEPRECATED_MESSAGE("Use +[APSLogger debug:] instead.");
+ (void)info:(NSString *)message APS_DEPRECATED_MESSAGE("Use +[APSLogger info:] instead.");
+ (void)warn:(NSString *)message APS_DEPRECATED_MESSAGE("Use +[APSLogger warn:] instead.");
+ (void)error:(NSString *)message APS_DEPRECATED_MESSAGE("Use +[APSLogger error:] instead.");
+ (void)fatal:(NSString *)message APS_DEPRECATED_MESSAGE("Use +[APSLogger fatal:] instead.");

+ (void)traceWithTag:(NSString *)tag message:(NSString *)message APS_DEPRECATED_MESSAGE();
+ (void)debugWithTag:(NSString *)tag message:(NSString *)message APS_DEPRECATED_MESSAGE();
+ (void)infoWithTag:(NSString *)tag message:(NSString *)message APS_DEPRECATED_MESSAGE();
+ (void)warnWithTag:(NSString *)tag message:(NSString *)message APS_DEPRECATED_MESSAGE();
+ (void)errorWithTag:(NSString *)tag message:(NSString *)message APS_DEPRECATED_MESSAGE();
+ (void)fatalWithTag:(NSString *)tag message:(NSString *)message APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
