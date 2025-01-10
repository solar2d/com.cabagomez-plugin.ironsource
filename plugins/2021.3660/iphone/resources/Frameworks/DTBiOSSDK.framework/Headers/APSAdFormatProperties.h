//
//  APSAdFormatProperties.h
//  DTBiOSSDK
//
//  Copyright © 2023 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSAdFormatPropertyBuilder.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSAdFormatProperties : NSObject
+ (instancetype)adFormatPropertiesWithBlock:(void (^)(APSAdFormatPropertyBuilder *builder))builderBlock;
@end

NS_ASSUME_NONNULL_END
