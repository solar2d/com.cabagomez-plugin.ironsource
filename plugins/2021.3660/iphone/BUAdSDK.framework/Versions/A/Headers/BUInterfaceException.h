//
//  BUInterfaceException.h
//  BUAdSDK
//
//  Created by zth on 2022/4/8.
//

/**
 老接口层的断言处理.  因SDK 给到媒体产物是RELEASE环境.  这里代替了断言功能.
 */
#import <Foundation/Foundation.h>

#define BUInterfaceAssert(re, userinfo)     [BUInterfaceException exceptionWithName:@"BUInterface Custom Error" reason:re userInfo:userinfo];

NS_ASSUME_NONNULL_BEGIN

@interface BUInterfaceException : NSObject

+ (void)exceptionWithName:(NSExceptionName)name reason:(NSString *)reason userInfo:(NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END
