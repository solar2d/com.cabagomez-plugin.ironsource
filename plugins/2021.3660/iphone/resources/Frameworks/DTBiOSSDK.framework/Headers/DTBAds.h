//
//  DTBAds.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"
#import "DTBLog.h"
#import "DTBDebugProperties.h"
#import "DTBAdNetworkInfo.h"

@class DTBSlotGroup;

/* NOTE: these values have been decided based on the custom
 encoding scheme. We have chosen the following values for the
 consent status: Unknown = 1, Explicit Yes = 7, Explicit No = 0 */
typedef NS_ENUM(NSInteger, DTBConsentStatus)  {
    CONSENT_NOT_DEFINED = -1,
    UNKNOWN = 1,
    EXPLICIT_YES = 7,
    EXPLICIT_NO = 0
};

/* Same as above. These values have been decided based on the custom
 encoding protocol: Google = 1, MoPub = 2 */
typedef NS_ENUM(NSInteger, DTBCMPFlavor) {
    CMP_NOT_DEFINED = -1,
    GOOGLE_CMP = 1,
    MOPUB_CMP = 2
};

typedef enum
{
    // set as default use MoPub, then DFP
    AUTO_DETECT_MRAID,
    // set mraid version based on DFP
    DFP_MRAID,
    // set mraid version based on MOPUB
    MOPUB_MRAID,
    // ignore mraid version
    NONE_MRAID,
    // use application set MRAID version
    CUSTOM_MRAID
} DTBMRAIDPolicy;

@interface DTBAds : NSObject

@property (nonatomic) BOOL useSecureConnection APS_DEPRECATED_MESSAGE();
@property (nonatomic) BOOL testMode APS_DEPRECATED_MESSAGE("Use +[APS setTestMode:] instead.");
@property (nonatomic) BOOL useGeoLocation APS_DEPRECATED_MESSAGE("Use +[APS setUseGeoLocation:] instead.");
@property (nonatomic) DTBMRAIDPolicy mraidPolicy APS_DEPRECATED_MESSAGE("Use +[APS setMraidPolicy:] insetead.");
@property (nonatomic) NSArray<NSString *> *  _Nullable mraidCustomVersions APS_DEPRECATED_MESSAGE("Use +[APS setMraidSupportedVersions:] instead.");
@property (nonatomic) BOOL isReady APS_DEPRECATED_MESSAGE();
@property (nonatomic) DTBDebugProperties * _Nonnull debugProperties APS_DEPRECATED_MESSAGE();

// Serverless Environment Markers
@property (nonatomic) NSArray * _Nonnull serverlessMarkers APS_DEPRECATED_MESSAGE();

/**
 * Use these APIs if your app is using Non-IAB GDPR Compliance (ex: AdMob, MoPub)
 */
- (void)setVendorList:(NSArray<NSNumber *> *_Nullable)vendorList APS_DEPRECATED_MESSAGE();
- (void)setConsentStatus:(DTBConsentStatus)consentStatus APS_DEPRECATED_MESSAGE("Use +[APS setConsentStatus:] instead.");
- (void)setCmpFlavor:(DTBCMPFlavor)cmpFlavor APS_DEPRECATED_MESSAGE("Use +[APS setCmpFlavor:] instead.");

// The client needs to call this API to determine if the consent status is unknown.
- (BOOL)isConsentStatusUnknown APS_DEPRECATED_MESSAGE();

+ (DTBAds * _Nonnull)sharedInstance APS_DEPRECATED_MESSAGE("Use APS class instead.");

// Set the applicationId provided by the Amazon Appstore.
- (void)setAppKey:(NSString * _Nonnull)appKey APS_DEPRECATED_MESSAGE("Use APS class initialization instead.");

// Set the Ad Network mediation name and it's info
- (void)setAdNetworkInfo:(DTBAdNetworkInfo *_Nullable)dtbAdNetworkInfo APS_DEPRECATED_MESSAGE("Use APS class initialization instead.");

// Retrieves the appKey, if already stored, otherwise will throw an exception
- (NSString * _Nullable)appKey APS_DEPRECATED_MESSAGE();

- (void)setLogLevel:(DTBLogLevel)logLevel APS_DEPRECATED_MESSAGE("Use +[APS setLogLevel:] instead.");

+ (NSString * _Nonnull)version APS_DEPRECATED_MESSAGE("Use +[APS version] instead.");

- (void)addSlotGroup:(DTBSlotGroup * _Nonnull)group APS_DEPRECATED_MESSAGE();

- (DTBSlotGroup * _Nullable)slotGroupByName:(NSString * _Nullable)name APS_DEPRECATED_MESSAGE();

- (BOOL)hasAdapters APS_DEPRECATED_MESSAGE();

- (void)removeNonIAB APS_DEPRECATED_MESSAGE();

- (void)setAPSPublisherExtendedIdFeatureEnabled:(BOOL)publisherExtendedIdFeatureEnabled APS_DEPRECATED_MESSAGE("Use +[APS setPublisherExtendedIdFeatureEnabled:] instead.");

/**
 * Use these APIs to add any custom attributes or parameters that might
 * be important for APS SDK to pick up.
 * The value type can be anything but please try to use NSString or NSDictionary for simplicity.
 */
- (void)addCustomAttribute:(NSString * _Nonnull)withKey value:(id _Nonnull)value APS_DEPRECATED_MESSAGE("Use +[APS addCustomAttribute:forKey:] instead");
- (void)removeCustomAttribute:(NSString * _Nonnull)forKey APS_DEPRECATED_MESSAGE();

/*
 * Alternative method to store and retrieve the local extras.
 */
+ (NSDictionary * _Nullable)getLocalExtras:(NSString * _Nonnull)adUnitId APS_DEPRECATED_MESSAGE();
+ (void)setLocalExtras:(NSString * _Nonnull)adUnitId localExtras:(NSDictionary * _Nonnull)localExtras APS_DEPRECATED_MESSAGE();
+ (void)removeLocalExtras:(NSString * _Nonnull)key APS_DEPRECATED_MESSAGE();
@end
