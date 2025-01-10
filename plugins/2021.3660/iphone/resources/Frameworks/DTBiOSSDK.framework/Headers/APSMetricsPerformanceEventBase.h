//
//  APSMetricsPerformanceEventBase.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, APSMetricsResult) {
    APSMetricsResultUnknown,
    APSMetricsResultSuccess,
    APSMetricsResultFailure
};

@interface APSMetricsPerformanceEventBase : NSObject

@property(nonatomic, nullable, copy) NSNumber *startTime;
@property(nonatomic, nullable, copy) NSNumber *endTime;
@property(nonatomic) APSMetricsResult performanceMetricsResult;

@end

NS_ASSUME_NONNULL_END
