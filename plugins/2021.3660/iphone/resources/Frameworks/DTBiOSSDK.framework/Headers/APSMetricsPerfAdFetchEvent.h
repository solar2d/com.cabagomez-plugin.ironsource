//
//  APSMetricsPerfAdFetchEvent.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSMetricsPerformanceEventBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsPerfAdFetchEvent : APSMetricsPerformanceEventBase

@property(nonatomic, nullable, copy) NSString *url;
- (instancetype)initWithStartTime:(NSNumber *)timeInMilliseconds;
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
