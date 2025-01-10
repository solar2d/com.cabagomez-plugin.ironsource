//
//  APSMetricsPerfAdapterEvent.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSMetricsPerformanceEventBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsPerfAdapterEvent : APSMetricsPerformanceEventBase

- (instancetype)initWithMetricsResult:(APSMetricsResult)result;

- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
