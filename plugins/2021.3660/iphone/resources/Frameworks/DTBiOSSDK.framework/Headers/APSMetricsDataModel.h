//
//  APSMetricsDataModel.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import "APSMetricsEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsDataModel : NSObject

/**
 * @return A new instance of APSMetricsEvent.
 */
- (instancetype)initWithMetricsEvent:(APSMetricsEvent *)event;

/**
 * @return dictionary for JSON
 */
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
