//
//  APSMetricsCustomEventModelBuilder.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsCustomEventModelBuilder : NSObject
- (APSMetricsCustomEventModelBuilder *)withEventName:(NSString *)eventName;
- (APSMetricsCustomEventModelBuilder *)withEventValue:(NSString *)eventValue;
- (APSMetricsCustomEventModelBuilder *)withEventDetail:(NSDictionary *)extraAttributes;
- (APSMetricsCustomEventModelBuilder *)withTahoeEventCategory:(NSString *)tahoeEventCategory;

- (NSDictionary * _Nullable)build;
@end

NS_ASSUME_NONNULL_END
