//
//  APS.h
//  This is the main SDK class.
//
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class APSInitConfig;

/**
 * Supported ad network type.
 */
typedef NS_ENUM(NSInteger, APSAdNetwork) {
    APSAdNetworkNone,
    APSAdNetworkGoogleAdManager,
    APSAdNetworkAdmob,
    APSAdNetworkAdGeneration,
    APSAdNetworkUnityLevelPlay,
    APSAdNetworkMax,
    APSAdNetworkNimbus,
    APSAdNetworkOther,
    APSAdNetworkCustomMediation
};

/**
 * Mobile Rich Media Ad Interface (MRAID) policy type.
 */
typedef NS_ENUM(NSInteger, APSMraidPolicy) {
    APSMraidPolicyAutoDetect,
    APSMraidPolicyDfp,
    APSMraidPolicyNone,
    APSMraidPolicyCustom
};

/**
 * The privacy type used in the @{ref setPrivacyString:type:}.
 */
typedef NS_ENUM(NSInteger, APSPrivacyType) {
    APSPrivacyTypeIABCCPAUSPrivacy,
    APSPrivacyTypeIABCCPAAPSPrivacy,
    APSPrivacyTypeDSAPrivacy
};

/**
 * Supported MRAID versions.
 */
typedef NSString APSMraidVersion;

/**
 * Log level type. A logging method with higher or equal to the level will be logged into the console.
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

FOUNDATION_EXPORT APSMraidVersion * const APSMraidVersion1_0;
FOUNDATION_EXPORT APSMraidVersion * const APSMraidVersion2_0;
FOUNDATION_EXPORT APSMraidVersion * const APSMraidVersion3_0;

/**
 * Main APS SDK class. Use this class to initialize the SDK and set SDK properties.
 */
@interface APS : NSObject

/**
 * @abstract Initialize the SDK without a configuration.
 * @description This should be the first call before using the SDK. We recommend the call in a main thread from
 * the -[AppDelegate application:didFinishLaunchingWithOptions:] method.
 *
 * @param appKey The publisher application key. If the appKey is nil or empty, it will throws a runtime NSException in
 * development and will not initialize the SDK but does not throw an exception in production.
 * @param adNetwork The main ad network used by the app.
 * parameters in the config object may be overriden by the DTB portal.
 * @param completion Optional completion block called when the initialize is complete.  This block will be called
 * from a background thread.
 */
+ (void)initializeWithAppKey:(NSString *)appKey
                   adNetwork:(APSAdNetwork)adNetwork
                  completion:(nullable void (^)(NSError *error))completion;

/**
 * @abstract Initialize the SDK with a configuration.
 * @description This should be the first call before using the SDK. We recommend the call in a main thread from
 * the -[AppDelegate application:didFinishLaunchingWithOptions:] method.
 *
 * @param appKey The publisher application key. If the appKey is nil or empty, it will throws a runtime NSException in
 * development and will not initialize the SDK but does not throw an exception in production.
 * @param adNetwork The main ad network used by the app.
 * @param config The initialize config object.  If nil, the config parameters will use default values. Note that
 * parameters in the config object may be overriden by the DTB portal.
 * @param completion Optional completion block called when the initialize is complete.  This block will be called
 * from a background thread.
 */
+ (void)initializeWithAppKey:(NSString *)appKey
                   adNetwork:(APSAdNetwork)adNetwork
                      config:(APSInitConfig * _Nullable)config
                  completion:(nullable void (^)(NSError *error))completion;

/**
 * @abstract Set a custom attribute key value strings.
 *
 * @param value The custom attribute value.
 * @param key The custom attribute key.  If the key already exists, the value will be replaced.
 * @note If the key or value is nil or empty, it will throw an NSException in development and will not add the
 * custom attribute but does not throw an exception in production.
 */
+ (void)setCustomAttribute:(NSString *)value forKey:(NSString *)key;

/**
 * @abstract Ad network.
 *
 * @return The current ad network.
 */
+ (APSAdNetwork)adNetwork;

/**
 * @abstract Set the privacy string.
 *
 * @param string The privacy string associated with the privacyType.
 * @param privacyType A @{ref APSPrivacyType} of the privacy string.
 */
+ (void)setPrivacyString:(NSString *)string type:(APSPrivacyType)privacyType;

+ (void)setPrivacyValue:(NSDictionary * _Nullable)dict type:(APSPrivacyType)privacyType;

/**
 * @abstract Set the content URL.
 * @descritpion The URL of the content you are displaying to users. For example, if you are displaying content from
 * https://yourdomain.com/section/content, you can pass this URL.
 *
 * @param contentUrl The URL of the app content. If the parameter is nil or empty, it will throw an NSException in
 * development and will not set the content URL but does not throw an exception in production.
 */
+ (void)setContentUrl:(NSString *)contentUrl;

/**
 * @abstract Set the current impression depth level.
 * @description The count of impressions in a given app session. Maintain a global counter within the app for each
 * session, then update and pass the counter in this method. This will include total impressions from all of your
 * demand and can be reset once a session ends.
 *
 * @param depthLevel A positive integer of the current impression counter. if the parameter is less than or equal to
 * zero, it will throw an NSException in development and will not set the impression depth but does not throw
 * an exeception in production.
 */
+ (void)setImpressionDepth:(NSInteger)depthLevel;

/**
 * @abstract Set the duration of the session.
 * @description The total duration of time a user has spent thus far in a specific app session, expressed in seconds.
 * A session can be defined as the following examples: when a user logs in/out or when a user dismisses the app to the
 * background. This can be anything that you define as a session within your app.
 *
 * @param sessionDurationInSeconds The current duration from the beginning of the session in seconds.  If the parameter
 * is less than or equal to zero, it will throw an NSException in development and wil not set the session duration but
 * does not throw an exception in production.
 */
+ (void)setSessionDurationInSeconds:(NSInteger)sessionDurationInSeconds;

/**
 * @abstract The SDK Version
 *
 * @return The current SDK version string.
 */
+ (NSString *)version;

@end

NS_ASSUME_NONNULL_END
