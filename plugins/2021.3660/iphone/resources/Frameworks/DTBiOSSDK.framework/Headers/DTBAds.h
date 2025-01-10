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

/* NOTE:
    1. Deprecated since APS no longer supports the non-IAB consent.
    2. These values have been decided ...
*/
typedef NS_ENUM(NSInteger, DTBConsentStatus) {
    CONSENT_NOT_DEFINED = -1,
    UNKNOWN             = 1,
    EXPLICIT_YES        = 7,
    EXPLICIT_NO         = 0
} APS_NON_IAB_DEPRECATED_MESSAGE("APS no longer supports this API. For GDPR, we support TCFv2 strings. Implementation instructions can be found on the APS Portal under Resources > Privacy");

/* NOTE:
     1. Deprecated since APS no longer supports the non-IAB consent.
     2. These values have been decided ...
 */
typedef NS_ENUM(NSInteger, DTBCMPFlavor) {
    CMP_NOT_DEFINED = -1,
    GOOGLE_CMP      = 1
} APS_NON_IAB_DEPRECATED_MESSAGE("APS no longer supports this API. For GDPR, we support TCFv2 strings. Implementation instructions can be found on the APS Portal under Resources > Privacy");

typedef enum {
    // set as default to DFP
    AUTO_DETECT_MRAID,
    // set mraid version based on DFP
    DFP_MRAID,
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
@property (nonatomic, copy) NSArray<NSString *> *_Nullable mraidCustomVersions APS_DEPRECATED_MESSAGE("Use +[APS setMraidSupportedVersions:] instead.");
@property (nonatomic) BOOL isReady APS_DEPRECATED_MESSAGE();
@property (nonatomic, strong) DTBDebugProperties *_Nonnull debugProperties APS_DEPRECATED_MESSAGE();

// Serverless Environment Markers
@property (nonatomic, copy) NSArray *_Nonnull serverlessMarkers APS_DEPRECATED_MESSAGE();

/* NOTE:
     1. Deprecated since APS no longer supports the non-IAB consent.
     2. These values have been decided ...
 */
- (void)setVendorList:(NSArray<NSNumber *> *_Nullable) vendorList APS_NON_IAB_DEPRECATED_MESSAGE("APS no longer supports this API. For GDPR, we support TCFv2 strings. Implementation instructions can be found on the APS Portal under Resources > Privacy");
- (void)setConsentStatus:(DTBConsentStatus) consentStatus APS_NON_IAB_DEPRECATED_MESSAGE("APS no longer supports this API. For GDPR, we support TCFv2 strings. Implementation instructions can be found on the APS Portal under Resources > Privacy");
- (void)setCmpFlavor:(DTBCMPFlavor) cmpFlavor APS_NON_IAB_DEPRECATED_MESSAGE("APS no longer supports this API. For GDPR, we support TCFv2 strings. Implementation instructions can be found on the APS Portal under Resources > Privacy");

/* NOTE:
     1. Deprecated since APS no longer supports the non-IAB consent.
     2. These values have been decided ...
 */
- (BOOL) isConsentStatusUnknown APS_NON_IAB_DEPRECATED_MESSAGE("APS no longer supports this API. For GDPR, we support TCFv2 strings. Implementation instructions can be found on the APS Portal under Resources > Privacy");

+ (DTBAds *_Nonnull) sharedInstance APS_DEPRECATED_MESSAGE("Use APS class instead.");

// Set the applicationId provided by the Amazon Appstore.
- (void)setAppKey:(NSString *_Nonnull) appKey APS_DEPRECATED_MESSAGE("Use APS class initialization instead.");

// Set the Ad Network mediation name and it's info
- (void)setAdNetworkInfo:(DTBAdNetworkInfo *_Nullable) dtbAdNetworkInfo APS_DEPRECATED_MESSAGE("Use APS class initialization instead.");

// Retrieves the appKey, if already stored, otherwise will throw an exception
- (NSString *_Nullable) appKey APS_DEPRECATED_MESSAGE();

- (void)setLogLevel:(DTBLogLevel) logLevel APS_DEPRECATED_MESSAGE("Use +[APS setLogLevel:] instead.");

+ (NSString *_Nonnull) version APS_DEPRECATED_MESSAGE("Use +[APS version] instead.");

- (void)addSlotGroup:(DTBSlotGroup *_Nonnull) group APS_DEPRECATED_MESSAGE();

- (DTBSlotGroup * _Nullable)slotGroupByName:(NSString *_Nullable) name APS_DEPRECATED_MESSAGE();

- (BOOL) hasAdapters APS_DEPRECATED_MESSAGE();

/* NOTE:
     1. Deprecated since APS no longer supports the non-IAB consent.
     2. These values have been decided ...
 */
- (void) removeNonIAB APS_NON_IAB_DEPRECATED_MESSAGE("APS no longer supports this API. For GDPR, we support TCFv2 strings. Implementation instructions can be found on the APS Portal under Resources > Privacy");

- (void)setAPSPublisherExtendedIdFeatureEnabled:(BOOL) publisherExtendedIdFeatureEnabled APS_DEPRECATED_MESSAGE("Use +[APS setPublisherExtendedIdFeatureEnabled:] instead.");

/**
 * Use these APIs to add any custom attributes or parameters that might
 * be important for APS SDK to pick up.
 * The value type can be anything but please try to use NSString or NSDictionary for simplicity.
 */
- (void)addCustomAttribute:(NSString * _Nonnull)withKey value:(id _Nonnull) value APS_DEPRECATED_MESSAGE("Use +[APS addCustomAttribute:forKey:] instead");
- (void)removeCustomAttribute:(NSString *_Nonnull) forKey APS_DEPRECATED_MESSAGE();

/*
 * Alternative method to store and retrieve the local extras.
 */
+ (NSDictionary * _Nullable)getLocalExtras:(NSString *_Nonnull) adUnitId APS_DEPRECATED_MESSAGE();
+ (void)setLocalExtras:(NSString * _Nonnull)adUnitId localExtras:(NSDictionary *_Nonnull) localExtras APS_DEPRECATED_MESSAGE();
+ (void)removeLocalExtras:(NSString *_Nonnull) key APS_DEPRECATED_MESSAGE();

- (void)setDsaTransparency:(NSDictionary* _Nullable)dict;

- (NSDictionary* _Nullable)getDsaTransparancyDict;
@end
