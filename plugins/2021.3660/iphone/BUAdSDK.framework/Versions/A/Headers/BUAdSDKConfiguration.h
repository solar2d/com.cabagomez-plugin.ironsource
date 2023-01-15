//
//  BUAdSDKConfiguration.h
//  BUAdSDK
//
//  Created by Eason on 2021/3/4.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BUAdSDKDefines.h"


NS_ASSUME_NONNULL_BEGIN

/// Provide a protocol for custom private data
/// Only valid in the CN environment
@protocol BUAdSDKPrivacyProvider <NSObject>

@optional

/// Specify whether to allow the SDK to use location data
- (BOOL)canUseLocation;
/// Return a latitude value
- (CLLocationDegrees)latitude;
/// Return a longitude value
- (CLLocationDegrees)longitude;

@end

@interface BUAdSDKConfiguration : NSObject

+ (instancetype)configuration;

/// This property should be set when integrating non-China and china areas at the same time,
/// otherwise it need'nt to be set.you‘d better set Territory first,  if you need to set them
@property (nonatomic, assign) BUAdSDKTerritory territory;

///Register the App key that’s already been applied before requesting an ad from TikTok Audience Network.
/// the unique identifier of the App
@property (nonatomic, copy) NSString *appID;

/// the unique identifier of the App, more safely
@property (nonatomic, copy) NSString *secretKey;

/// Configure development mode. default BUAdSDKLogLevelNone
@property (nonatomic, assign) BUAdSDKLogLevel logLevel;

/// the age group of the user
/// only works in CN environment
@property (nonatomic, assign) BUAdSDKAgeGroup ageGroup;

/// the COPPA of the user, COPPA is the short of Children's Online Privacy Protection Rule,
/// the interface only works in the United States.
/// Coppa 0 adult, 1 child
/// You can change its value at any time
@property (nonatomic, strong) NSNumber *coppa;

/// additional user information.
@property (nonatomic, copy) NSString *userExtData;

/// Solve the problem when your WKWebview post message empty,
/// default is BUOfflineTypeWebview
@property (nonatomic, assign) BUOfflineType webViewOfflineType;

/// Custom set the GDPR of the user,GDPR is the short of General Data Protection Regulation,the interface only works in The European.
/// GDPR 0 close privacy protection, 1 open privacy protection
/// You can change its value at any time
@property (nonatomic, strong) NSNumber *GDPR;

/// Custom set the CCPA of the user,CCPA is the short of General Data Protection Regulation,the interface only works in USA.
/// CCPA  0: "sale" of personal information is permitted, 1: user has opted out of "sale" of personal information -1: default
@property (nonatomic, strong) NSNumber *CCPA;
/// Custom set the debugLog to print debug Log.
/// debugLog 0: close debug log, 1: open debug log.
@property (nonatomic, strong) NSNumber *debugLog;

@property (nonatomic, strong) NSNumber *themeStatus;

/// Custom set the AB vid of the user. Array element type is NSNumber
@property (nonatomic, strong) NSArray<NSNumber *> *abvids;

/// Custom set the tob ab sdk version of the user.
@property (atomic, copy) NSString *abSDKVersion;

/// Custom set idfa value
/// You can change its value at any time
@property (nonatomic, copy) NSString *customIdfa;

/**
 In CN environment Whether to allow SDK to modify the category and options of AVAudioSession when playing audio, default is NO.
 The category set by the SDK is AVAudioSessionCategoryAmbient, and the options are AVAudioSessionCategoryOptionDuckOthers
 In VA environment Whether to allow SDK to modify the category and options of AVAudioSession when playing audio. When the scene is native or banner and current category is AVAudioSessionCategorySoloAmbient, default value is YES and the category set by the SDK is AVAudioSessionCategoryAmbient, the options are AVAudioSessionCategoryOptionMixWithOthers.The other scenes, default is NO.
 */
@property (nonatomic, assign) BOOL allowModifyAudioSessionSetting;

/**
 If you are a Unity developer, set this to Yes
 */
@property (nonatomic, assign) BOOL unityDeveloper;

/// You can use this property to set whether the SDK can use certain privacy data, or pass these privacy data yourself.
/// If this property is not set, the SDK will execute the default privacy data usage logic.
/// Note: This property is only valid for the CN environment. Unless you know what you need, it is recommended not to assign a value to this property.
@property (nonatomic, strong) id<BUAdSDKPrivacyProvider> privacyProvider;

/// App logo image. If set, it will be displayed in the App open ad.
@property (nonatomic, strong, nullable) UIImage *appLogoImage;


/// Whether the SDK is in debug mode ,the default is NO
/// When set to YES, some necessary debugging information will be initialized
/// @warning It is recommended to set it to YES in the development phase, which can output necessary debugging information during the development phase, which is convenient for debugging and exception resolution.
/// When publishing the app, it is recommended to set it to NO, otherwise the extra output will increase the performance.
@property (nonatomic, assign) BOOL SDKDEBUG;


@end

NS_ASSUME_NONNULL_END
