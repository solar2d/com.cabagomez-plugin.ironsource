//
//  APSMetricsEvent.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSMetricsPerformanceModel.h"
#import "APSMetricsCustomModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsEvent : NSObject

- (instancetype)initWithPerformanceModel:(APSMetricsPerformanceModel *)model;
- (instancetype)initWithCustomModel:(APSMetricsCustomModel *)model;
- (NSDictionary *)toDictionary;
- (BOOL)isToSendDeviceInfo;

@end

NS_ASSUME_NONNULL_END
