//
//  BUPanguManager.h
//  BUVAAuxiliary
//
//  Created by bytedance on 2021/10/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BUPanguManager : NSObject

+ (instancetype)shareInstance;

- (BOOL)fl_connectSocket:(NSDictionary *)params
        startCallback:(void(^)(BOOL success, NSDictionary * _Nullable response))startCallback
        stateCallback:(void(^)(NSDictionary * _Nullable stateInfo))stateCallback;

@end

NS_ASSUME_NONNULL_END
