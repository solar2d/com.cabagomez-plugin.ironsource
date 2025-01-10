//
//  APSMetricsDeviceInfo.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsDeviceInfo : NSObject

@property(nonatomic, nullable, copy) NSString *platformCategory;
@property(nonatomic, nullable, copy) NSString *screenSize;
@property(nonatomic, nullable, copy) NSString *deviceType;
@property(nonatomic, nullable, copy) NSString *connectionType;
@property(nonatomic, nullable, copy) NSString *platformCategoryVersion;
@property(nonatomic, nullable, copy) NSString *osVersion;
@property(nonatomic, nullable, copy) NSString *deviceModel;

- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
