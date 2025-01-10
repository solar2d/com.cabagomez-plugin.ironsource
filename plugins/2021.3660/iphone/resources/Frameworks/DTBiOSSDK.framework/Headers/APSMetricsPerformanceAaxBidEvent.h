//
//  APSMetricsPerformanceAaxBidEvent.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSMetricsPerformanceEventBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsPerformanceAaxBidEvent : APSMetricsPerformanceEventBase

@property(nonatomic, nullable, copy) NSString *hostName;
@property(nonatomic) BOOL refreshFlag;

- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
