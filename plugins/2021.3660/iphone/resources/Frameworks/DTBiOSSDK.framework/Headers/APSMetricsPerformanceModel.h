//
//  ApsMetricsPerformanceModel.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSMetricsPerformanceAaxBidEvent.h"
#import "APSMetricsPerfAdapterEvent.h"
#import "APSMetricsPerfAdFetchEvent.h"
#import "APSMetricsPerfImpressionFiredEvent.h"
#import "APSMetricsPerfAdClickEvent.h"
#import "APSMetricsPerfVideoCompletedEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsPerformanceModel : NSObject

@property(nonatomic, nullable, copy) NSString *networkName;
@property(nonatomic, nullable, copy) NSString *bidId;
@property(nonatomic) BOOL videoFlag;
@property(nonatomic, nullable, copy) NSString *adFormat;
@property(nonatomic, nullable, copy) NSString *correlationId;
@property(nonatomic, nullable) APSMetricsPerformanceAaxBidEvent *bidEvent;
@property(nonatomic, nullable) APSMetricsPerfAdapterEvent *adapterEvent;
@property(nonatomic, nullable) APSMetricsPerfAdFetchEvent *fetchEvent;
@property(nonatomic, nullable) APSMetricsPerfImpressionFiredEvent *impressionEvent;
@property(nonatomic, nullable) APSMetricsPerfAdClickEvent *adClickEvent;
@property(nonatomic, nullable) APSMetricsPerfVideoCompletedEvent *videoCompletedEvent;
@property(nonatomic, copy) NSNumber *timestamp;

- (NSDictionary *)toDictionary;
- (BOOL)isToSendDeviceInfo;

@end

NS_ASSUME_NONNULL_END
