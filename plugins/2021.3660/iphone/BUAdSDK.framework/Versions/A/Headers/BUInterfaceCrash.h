//
//  BUInterfaceCrash.h
//  BUAdSDK
//
//  Created by zth on 2022/3/22.
//
/**
  接口层的防崩溃处理
  @WARNING  主要是为了防止同时接入Pangle 和  CSJ时 出现媒体错误调用时, 防止因为api 或 class类 双方SDK不一致时的崩溃问题
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BUInterfaceCrash : NSObject

@end

NS_ASSUME_NONNULL_END
