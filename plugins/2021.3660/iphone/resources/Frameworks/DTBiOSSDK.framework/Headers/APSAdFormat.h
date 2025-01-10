//
//  APSAdFormat.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#ifndef APSAdFormat_h
#define APSAdFormat_h

#import <Foundation/Foundation.h>

#define APS_SIZE_MAX                      9999
#define APS_BANNER_WIDTH                  320
#define APS_BANNER_HEIGHT                 50
#define APS_MREC_WIDTH                    300
#define APS_MREC_HEIGHT                   250
#define APS_LEADERBOARD_WIDTH             728
#define APS_LEADERBOARD_HEIGHT            90
#define APS_INSTREAM_VIDEO_DEFAULT_WIDTH  320
#define APS_INSTREAM_VIDEO_DEFAULT_HEIGHT 480

/**
 * @abstract Ad Format.
 * @description APS supports both banner and interstitial ad formats with predefined sizes.
 * However we give the flexibility for publishers to set the height and width for instreamVideo using AdFormatProperties
 */
typedef NS_ENUM(NSInteger, APSAdFormat) {
    APSAdFormatBanner,       /* 320x50 */
    APSAdFormatMREC,         /* 300x250 */
    APSAdFormatLeaderBoard,  /* 728x90 */
    APSAdFormatInterstitial, /* full screen */
    APSAdFormatRewardedVideo, /* full screen */
    APSAdFormatInstreamVideo /* video player width and height set by publisher, default is 320x480*/
};

/**
 * @abstract Checks whether the ad format is a kind of banners.
 * @return YES if the ad format is a kind of banner that is a part of the current screen.
 */
BOOL APSAdFormatIsBanner(APSAdFormat adFormat);

/**
 * @abstract Checks whether the ad format is a kind of interstitials.
 * @return YES if the ad format is a kind of interstitial that takes full screen.
 */
BOOL APSAdFormatIsInterstitial(APSAdFormat adFormat);

#endif /* APSAdFormat_h */
