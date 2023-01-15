//
//  BUAdSmartlookManager.h
//  BUAdSDK
//
//  Created by wangchao on 2020/3/30.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "BUInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

 __attribute__((objc_subclassing_restricted))
@interface BUAdSmartlookManager : BUInterfaceBaseObject


+ (instancetype)sharedInstance;

+ (void)setupSmartlookConfig:(NSString *)config;
+ (void)resetConfig;

@end

NS_ASSUME_NONNULL_END
