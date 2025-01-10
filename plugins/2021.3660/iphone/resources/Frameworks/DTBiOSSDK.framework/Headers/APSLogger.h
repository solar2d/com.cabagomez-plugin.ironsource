//
//  APSLogger.h
//  APSiOSShared
//
//  Copyright © 2023 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Log level type. Any @{APSLogger} method with higher or equal to the level will be logged into the console.
 */
typedef NS_ENUM(NSInteger, APSLoggerLevel) {
    APSLoggerLevelAll,
    APSLoggerLevelTrace,
    APSLoggerLevelDebug,
    APSLoggerLevelInfo,
    APSLoggerLevelWarn,
    APSLoggerLevelError,
    APSLoggerLevelFatal,
    APSLoggerLevelOff
};

/**
 * A log delegate.
 */
@protocol APSLoggerDelegate

/**
 * Called when APS logs a message. Use @{APSLogger} setDelegate: to listen to the log.
 */
- (void)didLogMessage:(NSString * _Nonnull)message;

@end

/**
 * The main log class that puts log messages into the device log console. Do not instantiate the object directly.
 * Use the class methods below.
 *
 * @description A logging message format is @"{prefix} - {logLevel} : [{tag}] {message}".
 */
@interface APSLogger : NSObject

/**
 * Set a log delegate to listen to logging messages.
 * @param delegate An @{ref APSLoggerDelegate}.
 */
+ (void)setDelegate:(id<APSLoggerDelegate>)delegate;

/**
 * @abstract Set a log level.
 * @description APSLogger will log messages to the console only when the level is at least the log level.
 * For example, if we set the log level to APSLoggerLevelWarn, the [APSLogger warn:], [APSLogger error:] will
 * log meesages to the console but [APSLogger info:], [APLogger debug:] will not. Default log level is @{ref APSLoggerLevelError.
 *
 * @param level A threshold log level.
 */
+ (void)setLevel:(APSLoggerLevel)level;

/**
 * @return The current log level of @{ref APSLoggerLevel}.
 */
+ (APSLoggerLevel)level;

/**
 * @abstract Set individual logging message prefix. The default value is @"LOG".
 */
+ (void)setPrefix:(NSString *)prefix;

- (instancetype)init NS_UNAVAILABLE;

/**
 * Log a trace message
 * @param message The message string to be logged.
 */
+ (void)trace:(NSString *)message;
/**
 * Log a trace message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 */
+ (void)trace:(NSString *)message exception:(NSException *)exception;
/**
 * Log a trace message
 * @param message The message string to be logged.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)trace:(NSString *)message tag:(NSObject *)tag;
/**
 * Log a trace message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)trace:(NSString *)message exception:(NSException *)exception tag:(NSObject *)tag;

/**
 * Log a debug message
 * @param message The message string to be logged.
 */
+ (void)debug:(NSString *)message;
/**
 * Log a debug message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 */
+ (void)debug:(NSString *)message exception:(NSException *)exception;
/**
 * Log a debug message
 * @param message The message string to be logged.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)debug:(NSString *)message tag:(NSObject *)tag;
/**
 * Log a debug message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)debug:(NSString *)message exception:(NSException *)exception tag:(NSObject *)tag;

/**
 * Log an info message
 * @param message The message string to be logged.
 */
+ (void)info:(NSString *)message;
/**
 * Log an info message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 */
+ (void)info:(NSString *)message exception:(NSException *)exception;
/**
 * Log an info message
 * @param message The message string to be logged.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)info:(NSString *)message tag:(NSObject *)tag;
/**
 * Log an info message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)info:(NSString *)message exception:(NSException *)exception tag:(NSObject *)tag;

/**
 * Log a warning message
 * @param message The message string to be logged.
 */
+ (void)warn:(NSString *)message;
/**
 * Log a warning message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 */
+ (void)warn:(NSString *)message exception:(NSException *)exception;
/**
 * Log a warning message
 * @param message The message string to be logged.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)warn:(NSString *)message tag:(NSObject *)tag;
/**
 * Log a warning message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)warn:(NSString *)message exception:(NSException *)exception tag:(NSObject *)tag;

/**
 * Log an error message
 * @param message The message string to be logged.
 */
+ (void)error:(NSString *)message;
/**
 * Log an error message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 */
+ (void)error:(NSString *)message exception:(NSException *)exception;
/**
 * Log an error message
 * @param message The message string to be logged.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)error:(NSString *)message tag:(NSObject *)tag;
/**
 * Log an error message
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)error:(NSString *)message exception:(NSException *)exception tag:(NSObject *)tag;

/**
 * Log a fatal message with a remote logging sampling.
 *
 * @description Fatal is a severe error type that in addition to logging messages into the console. It will
 * use @{ref APSAnalytics} to sample the logging events and upload them to the backend for further analysis.
 * Be mindful of using this since it will consume extra network bandwidth and backend resources to consume it.
 *
 * @param message The message string to be logged.
 */
+ (void)fatalWithRemoteLogging:(NSString *)message;
/**
 * Log a fatal message with a remote logging sampling.
 *
 * @description Fatal is a severe error type that in addition to logging messages into the console. It will
 * use @{ref APSAnalytics} to sample the logging events and upload them to the backend for further analysis.
 * Be mindful of using this since it will consume extra network bandwidth and backend resources to consume it.
 *
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 */
+ (void)fatalWithRemoteLogging:(NSString *)message exception:(NSException *)exception;
/**
 * Log a fatal message with a remote logging sampling.
 *
 * @description Fatal is a severe error type that in addition to logging messages into the console. It will
 * use @{ref APSAnalytics} to sample the logging events and upload them to the backend for further analysis.
 * Be mindful of using this since it will consume extra network bandwidth and backend resources to consume it.
 *
 * @param message The message string to be logged.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)fatalWithRemoteLogging:(NSString *)message tag:(NSObject *)tag;
/**
 * Log a fatal message with a remote logging sampling.
 *
 * @description Fatal is a severe error type that in addition to logging messages into the console. It will
 * use @{ref APSAnalytics} to sample the logging events and upload them to the backend for further analysis.
 * Be mindful of using this since it will consume extra network bandwidth and backend resources to consume it.
 *
 * @param message The message string to be logged.
 * @param exception The exception which will be logged as part of the APSAnalytics.
 * @param tag The tag param can be either NSString or NSObject which will set the tag value based on its class.
 */
+ (void)fatalWithRemoteLogging:(NSString *)message exception:(NSException *)exception tag:(NSObject *)tag;

@end

NS_ASSUME_NONNULL_END
