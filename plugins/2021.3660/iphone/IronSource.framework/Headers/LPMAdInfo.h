//
//  LPMAdInfo.h
//  IronSource
//
//  Copyright © 2024 IronSource. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LPMAdSize.h"

NS_ASSUME_NONNULL_BEGIN

@interface LPMAdInfo : NSObject

@property(nonatomic, copy) NSString *adUnitId;
@property(nonatomic, copy, nullable) NSString *placementName;
@property(nonatomic, copy, nullable) LPMAdSize *adSize;
@property(nonatomic, copy) NSString *adFormat;
@property(nonatomic, copy) NSString *auction_id;
@property(nonatomic, copy) NSString *country;
@property(nonatomic, copy) NSString *ab;
@property(nonatomic, copy) NSString *segment_name;
@property(nonatomic, copy) NSString *ad_network;
@property(nonatomic, copy) NSString *instance_name;
@property(nonatomic, copy) NSString *instance_id;
@property(nonatomic, copy) NSNumber *revenue;
@property(nonatomic, copy) NSString *precision;
@property(nonatomic, copy) NSString *encrypted_cpm;
@property(nonatomic, copy) NSNumber *conversion_value;

@end

NS_ASSUME_NONNULL_END
