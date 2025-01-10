//
//  APSMetricsPerfAdClickEvent.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsPerfAdClickEvent : NSObject

@property(nonatomic, copy) NSNumber *startTime;
- (instancetype)initWithStartTime:(NSNumber *)timeInMilliseconds;
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
