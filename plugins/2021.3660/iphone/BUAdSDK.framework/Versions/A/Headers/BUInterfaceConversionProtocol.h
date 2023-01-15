//
//  BUInterfaceConversionProtocol.h
//  ProtocolTest
//
//  Created by zth on 2022/2/17.
//

/**
 接口转换协议
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BUInterfaceConversionProtocol <NSObject>

@required

/// 接口转换_转换到新的执行类
/// @param originalInterfaceCls 原有的类
- (Class)conversionWithOriginalInterfaceClass:(Class)originalInterfaceCls;




@end

NS_ASSUME_NONNULL_END
