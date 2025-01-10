//
//  APSMetricsPerfEventModelBuilder.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import "APSMetricsPerformanceAaxBidEvent.h"
#import "APSMetricsPerfImpressionFiredEvent.h"
#import "APSMetricsPerfAdFetchEvent.h"
#import "APSMetricsPerfAdapterEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsPerfEventModelBuilder : NSObject
- (APSMetricsPerfEventModelBuilder *)withMediationName:(NSString *)mediationName;
- (APSMetricsPerfEventModelBuilder *)withCorrelationId:(NSString *)correlationId;
- (APSMetricsPerfEventModelBuilder *)withAdFormat:(NSString *)adFormat;
- (APSMetricsPerfEventModelBuilder *)withVideoFlag:(BOOL)videoFlag;
- (APSMetricsPerfEventModelBuilder *)withAdImpressionEndTime:(APSMetricsResult)result endTime:(NSNumber *)endTimeInMilliseconds;
- (APSMetricsPerfEventModelBuilder *)withBidId:(NSString *)bidId;
- (APSMetricsPerfEventModelBuilder *)withAdFetchStartTime:(NSNumber *)startTimeInMilliseconds;
- (APSMetricsPerfEventModelBuilder *)withAdFetchEndTime:(APSMetricsResult)result endTime:(NSNumber *)endTimeInMilliseconds;
- (APSMetricsPerfEventModelBuilder *)withAdapterStartTime:(NSNumber *)startTimeInMilliseconds;
- (APSMetricsPerfEventModelBuilder *)withAdapterEndTime:(APSMetricsResult)result endTime:(NSNumber *)endTimeInMilliseconds;
- (APSMetricsPerfEventModelBuilder *)withAaxBidEvent:(APSMetricsPerformanceAaxBidEvent *)event;
- (APSMetricsPerfEventModelBuilder *)withImpressionFiredEvent:(APSMetricsPerfImpressionFiredEvent *)event;
- (APSMetricsPerfEventModelBuilder *)withAdFetchEvent:(APSMetricsPerfAdFetchEvent *)event;
- (APSMetricsPerfEventModelBuilder *)withAdapterEvent:(APSMetricsPerfAdapterEvent *)event;
- (APSMetricsPerfEventModelBuilder *)withAdClickEvent:(NSNumber *)timestamp;
- (APSMetricsPerfEventModelBuilder *)withVideoCompletedEvent:(NSNumber *)timestamp;
- (NSDictionary * _Nullable)build;
@end

NS_ASSUME_NONNULL_END
