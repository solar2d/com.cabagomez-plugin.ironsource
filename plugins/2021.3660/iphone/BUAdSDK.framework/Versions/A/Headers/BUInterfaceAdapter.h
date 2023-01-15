//
//  BUInterfaceAdapter.h
//  ProtocolTest
//
//  Created by zth on 2022/2/17.
//

/**
 接口适配器
 */
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface BUInterfaceAdapter : NSObject


/// 接口转换
/// @param originalClass 原接口类
/// @return 新接口类
+ (Class )adapterWithOriginalClass:(Class)originalClass;

@end

NS_ASSUME_NONNULL_END
