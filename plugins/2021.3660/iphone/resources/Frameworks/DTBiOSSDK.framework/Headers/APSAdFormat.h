//
//  APSAdFormat.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#ifndef APSAdFormat_h
#define APSAdFormat_h

#import <Foundation/Foundation.h>

#define APS_SIZE_MAX 9999
#define APS_BANNER_WIDTH 320
#define APS_BANNER_HEIGHT 50
#define APS_MREC_WIDTH 300
#define APS_MREC_HEIGHT 250
#define APS_LEADERBOARD_WIDTH 728
#define APS_LEADERBOARD_HEIGHT 90

/**
 @abstract Ad Format.
 @description APS supports both banner and interstitial ad formats with predefined sizes.
 */
typedef NS_ENUM(NSInteger, APSAdFormat) {
    APSAdFormatBanner,       /* 320x50 */
    APSAdFormatMREC,         /* 300x250 */
    APSAdFormatLeaderBoard,  /* 728x90 */
    APSAdFormatInterstitial, /* full screen */
    APSAdFormatRewardedVideo /* full screen */
};

/**
 @abstract Checks whether the ad format is a kind of banners.
 @return YES if the ad format is a kind of banner that is a part of the current screen.
 */
BOOL APSAdFormatIsBanner(APSAdFormat adFormat);

/**
 @abstract Checks whether the ad format is a kind of interstitials.
 @return YES if the ad format is a kind of interstitial that takes full screen.
 */
BOOL APSAdFormatIsInterstitial(APSAdFormat adFormat);

#endif /* APSAdFormat_h */
