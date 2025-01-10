//
//  APSMetricsCustomEventInfo.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsCustomEventInfo : NSObject

@property(nonatomic, copy) NSString *name;
@property(nonatomic, nullable, copy) NSString *value;
@property(nonatomic, nullable, copy) NSDictionary *extraAttrs;

- (instancetype)initWithName:(NSString *)name value:(NSString * _Nullable)value extraAttributes:(NSDictionary * _Nullable)extras;

- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
