//
//  BaseAdapter.h
//  IronSource
//
//  Created by Clementine on 3/9/15.
//  Copyright (c) 2015 IronSource. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ISAdapterConfig.h"

#import "ISBannerAdapterProtocol.h"
#import "ISRewardedVideoAdapterProtocol.h"
#import "ISInterstitialAdapterProtocol.h"
#import "ISOfferwallAdapterProtocol.h"
#import "ISBiddingDataAdapterProtocol.h"

#import "ISLoadWhileShowSupportState.h"

@protocol ISBannerAdapterProtocol;
@protocol ISRewardedVideoAdapterProtocol;
@protocol ISInterstitialAdapterProtocol;
@protocol ISOfferwallAdapterProtocol;

@interface ISBaseAdapter : NSObject <ISInterstitialAdapterProtocol, ISRewardedVideoAdapterProtocol, ISBannerAdapterProtocol, ISOfferwallAdapterProtocol, ISBiddingDataAdapterProtocol>
{
    @protected ISLoadWhileShowSupportState LWSState;
}

@property (nonatomic, strong) NSString *adapterName;

/* Configuration */

@property (strong, nonatomic) NSString  *pluginType;
@property (strong, nonatomic) NSString  *userId;

- (instancetype)initAdapter:(NSString *)name;
- (void)earlyInitWithAdapterConfig:(ISAdapterConfig *)adapterConfig;

/* Shared */
- (NSString *)sdkVersion;
- (NSString *)version;
- (NSString *)dynamicUserId;
- (ISLoadWhileShowSupportState)getLWSSupportState:(ISAdapterConfig *)adapterConfig;
//check if the network supports adaptive banners
- (BOOL)getAdaptiveBannerSupport;

@end
