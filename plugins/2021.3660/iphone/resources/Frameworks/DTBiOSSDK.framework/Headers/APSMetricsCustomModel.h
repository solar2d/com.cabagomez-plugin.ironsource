//
//  APSMetricsCustomModel.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSMetricsCustomEventInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsCustomModel : NSObject

@property(nonatomic, nullable) APSMetricsCustomEventInfo *customEvent;

- (instancetype)initWithCustomEvent:(APSMetricsCustomEventInfo *)event;

- (NSDictionary * _Nullable)toDictionary;

@end

NS_ASSUME_NONNULL_END

