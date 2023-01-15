//
//  BUAdSDKPlayableToolManager.h
//  BUAdSDK
//
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "BUInterfaceBaseObject.h"

 __attribute__((objc_subclassing_restricted))
@interface BUAdSDKPlayableToolManager : BUInterfaceBaseObject

+ (instancetype)sharedInstance;

+ (void)setPlayableURL:(NSString *)url;

+ (void)setDownloadUrl:(NSString *)url;

+ (void)setDeeplinkUrl:(NSString *)url;

+ (void)setIsLandScape:(BOOL)isLandScape;

+ (void)clearAll;

@end

