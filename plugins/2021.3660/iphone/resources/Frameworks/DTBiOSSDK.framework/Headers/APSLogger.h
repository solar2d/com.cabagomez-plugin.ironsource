//
//  APSLogger.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Log level type. Any @{APSLogger} method with higher or equal to the level will be logged into the console.
 */
typedef NS_ENUM(NSInteger, APSLogLevel) {
    APSLogLevelAll,
    APSLogLevelTrace,
    APSLogLevelDebug,
    APSLogLevelInfo,
    APSLogLevelWarn,
    APSLogLevelError,
    APSLogLevelFatal,
    APSLogLevelOff
};

/**
 A log delegate.
 */
@protocol APSLoggerDelegate

/**
 Called when APS logs a message. Use @{APSLogger} setDelegate: to listen to the log.
 */
- (void)didLogMessage:(NSString * _Nonnull)message;

@end

/**
 The main log class that puts log messages into the device log console. Do not instantiate the object directly.
 Use the class methods below.
 */
@interface APSLogger : NSObject

/**
 Log a trace message
 @param message The message string to be logged.
 */
+ (void)trace:(NSString * _Nonnull)message;

/**
 Log a debug message
 @param message The message string to be logged.
 */
+ (void)debug:(NSString * _Nonnull)message;

/**
 Log an info message
 @param message The message string to be logged.
 */
+ (void)info: (NSString * _Nonnull)message;

/**
 Log a warning message
 @param message The message string to be logged.
 */
+ (void)warn: (NSString * _Nonnull)message;

/**
 Log an error message
 @param message The message string to be logged.
 */
+ (void)error:(NSString * _Nonnull)message;

/**
 Log a fatal message
 @param message The message string to be logged.
 */
+ (void)fatal:(NSString * _Nonnull)message;

/**
 Set a log delegate to listen to logging messages.
 @param delegate An @{ref APSLoggerDelegate}.
 */
+ (void)setDelegate:(id<APSLoggerDelegate>)delegate;

/**
 @abstract Set a log level.
 @description APSLogger will log messages to the console only when the level is at least the log level.
 For example, if we set the log level to APSLogLevelWarn, the [APSLogger warn:], [APSLogger error:] will
 log meesages to the console but [APSLogger info:], [APLogger debug:] will not.

 @param level A threshold log level.
 */
+ (void)setLogLevel:(APSLogLevel)level;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
