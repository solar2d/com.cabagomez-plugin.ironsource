//
//  APSInitConfig.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#import "APS.h"
#import "APSLogger.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSInitConfig : NSObject

/**
 * @abstract Use geolocation.
 * @description Set to YES if the app supports geolocation permission. If users give permissions to location access,
 * the flag will determine whether it should access location information during bid requests. If users don't give
 * the permission, the flag will not be used.  Default is NO.
 */
@property (nonatomic, assign) BOOL useGeolocation;

/**
 * @abstract Set logging level.
 * @description The desired logging level. SDK will log messages into the console when the logging level is the same as
 * or below to the target log level defined in @{ref APSLogLevel}.  Default is APSLogLevelError.
 */
@property (nonatomic, assign) APSLogLevel logLevel;

/**
 * @abstract Set the testing mode.
 * @description Set to YES to enable test mode used during the integration verification. Do not forget to turn the
 * testing mode off before app submission as the test ads are not eligible for monetization. Default is NO.
 */
@property (nonatomic, assign) BOOL testMode;

/**
 * @abstract Set the SKAdNetwork testing mode.
 * @description Set to YES to enable the SKAdNetwork testing mode used during the integration verification. Do not
 * forget to turn the testing mode off before app submission as the test ads are not eligible for monetization.
 * Default is NO.
 */
@property (nonatomic, assign) BOOL skAdNetworkTestMode;
@property (nonatomic, assign, nullable) NSString *skAdNetworkTestModeVersion;

@property (nonatomic, assign) BOOL gdprRegionTestMode;

/**
 * @abstract Allows frequency tracking of an ad being served.
 * @description If set, the sdk will generate an id to track the frequency of an ad being served. The id is unique per
 * device, per app, per bidder, and resets at minimum every 30 days. Default is YES.
 */
@property (nonatomic, assign) BOOL publisherExtendedIdFeatureEnabled;

/**
 * @abstract Set OMID partner name. Set this in conjunction with @{ref omidPartnerVersion}.  Default is not set.
 */
@property (nonatomic, copy, nullable) NSString *omidPartnerName;

/**
 * @abstract Set OMID partner version. Set this in conjunction with @{ref omidPartnerName}. Default is not set.
 */
@property (nonatomic, copy, nullable) NSString *omidPartnerVersion;

/**
 * @abstract Set the MRAID policy. Default is APSMraidPolicyAutoDetect.
 */
@property (nonatomic, assign) APSMraidPolicy mraidPolicy;

/**
 * @abstract Set the supported versions of MRAID.
 * @description An array of supported @{APSMraidVersion}.  If one of APSMraidVersion in the mraidSupportedVersions is not
 * supported, it will throw an NSException in development and will not set the mraidVersions but does not throw an
 * exception in production.  Defaults is @[ APSMraidVersion1_0, APSMraidVersion2_0, APSMraidVersion3_0 ].
 */
@property (nonatomic, copy, nullable) NSArray<APSMraidVersion *> *mraidSupportedVersions;

@end

NS_ASSUME_NONNULL_END
