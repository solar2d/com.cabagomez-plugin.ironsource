//
//  BUPersonalizationPrompts.h
//  BUAdSDK
//
//  Created by bytedance on 2020/11/10.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "BUInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

 __attribute__((objc_subclassing_restricted))
@interface BUPersonalizationPrompts : BUInterfaceBaseObject
/// personalization prompts's name
@property (nonatomic, copy) NSString *personalizationName;
/// personalization prompts's url
@property (nonatomic, copy) NSString *personalizationUrl;
/// personalization prompts valid or not
- (BOOL)validPersonalPrompts;
@end

NS_ASSUME_NONNULL_END
