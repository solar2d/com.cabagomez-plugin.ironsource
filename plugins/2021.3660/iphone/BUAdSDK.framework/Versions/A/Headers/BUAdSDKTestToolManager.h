//
//  BUAdSDKTestToolManager.h
//  BUAdSDK
//
//  Created by wangyanlin on 2020/4/14.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "BUInterfaceBaseObject.h"


 __attribute__((objc_subclassing_restricted))
@interface BUAdSDKTestToolManager : BUInterfaceBaseObject

+ (instancetype)sharedInstance;

+ (void)setHostIP:(NSString *)hostIP;

+ (void)setHostPort:(NSString *)hostPort;

+ (void)setInputOneContent:(NSString *)oneContent;

+ (void)setInputTwoContent:(NSString *)twoContent;

+ (void)clearIPAddress;

+ (void)clearInputContent;

- (NSString *)testTimeStamp;

@end


