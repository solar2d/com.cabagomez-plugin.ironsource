//
//  APSMetricsPerfImpressionFiredEvent.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSMetricsPerformanceEventBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsPerfImpressionFiredEvent : APSMetricsPerformanceEventBase

- (instancetype)initWithMetricsResult:(APSMetricsResult)result endTime:(NSNumber *)endTimeInMilliseconds;
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
