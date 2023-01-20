//
//  ALSdkConfiguration.h
//  AppLovinSDK
//
//  Created by Thomas So on 9/29/18.
//  Copyright © 2020 AppLovin Corporation. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 * Object that contains various flags related to the SDK configuration.
 */
@interface ALSdkConfiguration : NSObject

/**
 * AppLovin SDK-defined app tracking transparency status values (extended to include "unavailable" state on iOS before iOS14).
 */
typedef NS_ENUM(NSInteger, ALAppTrackingTransparencyStatus)
{
    /**
     * Device is on iOS before iOS14, AppTrackingTransparency.framework is not available.
     */
    ALAppTrackingTransparencyStatusUnavailable = -1,
    
    /**
     * The user has not yet received an authorization request to authorize access to app-related data that can be used for tracking the user or the device.
     */
    ALAppTrackingTransparencyStatusNotDetermined,
    
    /**
     * Authorization to access app-related data that can be used for tracking the user or the device is restricted.
     */
    ALAppTrackingTransparencyStatusRestricted,
    
    /**
     * The user denies authorization to access app-related data that can be used for tracking the user or the device.
     */
    ALAppTrackingTransparencyStatusDenied,
    
    /**
     * The user authorizes access to app-related data that can be used for tracking the user or the device.
     */
    ALAppTrackingTransparencyStatusAuthorized
};

/**
 * Gets the country code for this user. The value of this property will be an empty string if no country code is available for this user.
 *
 * @warning Do not confuse this with the <em>currency</em> code which is "USD" in most cases.
 */
@property (nonatomic, copy, readonly) NSString *countryCode;

/**
 * Get the list of those Ad Unit IDs that are in the waterfall that is currently active for a particular user and
 * for which Amazon Publisher Services is enabled.
 *
 * Which waterfall is currently active for a user depends on things like A/B tests, keyword targeting, or DNT.
 *
 * @return @c nil when configuration fetching fails (e.g. in the case of no connection) or
 * an empty array if no Ad Unit IDs have Amazon Publisher Services enabled.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<NSString *> *enabledAmazonAdUnitIdentifiers;

/**
 * Indicates whether or not the user authorizes access to app-related data that can be used for tracking the user or the device.
 *
 * @warning Users can revoke permission at any time through the "Allow Apps To Request To Track" privacy setting on the device.
 */
@property (nonatomic, assign, readonly) ALAppTrackingTransparencyStatus appTrackingTransparencyStatus;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

__attribute__((deprecated))
typedef NS_ENUM(NSInteger, ALConsentDialogState)
{
    ALConsentDialogStateUnknown,
    ALConsentDialogStateApplies,
    ALConsentDialogStateDoesNotApply
};

@interface ALSdkConfiguration (ALDeprecated)
@property (nonatomic, assign, readonly) ALConsentDialogState consentDialogState __deprecated_msg("This API has been deprecated and will be removed in a future release.");
@end
