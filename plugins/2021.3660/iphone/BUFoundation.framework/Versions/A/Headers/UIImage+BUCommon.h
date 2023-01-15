//
//  UIImage+BUCommon.h
//  BUFoundation
//
//  Created by ByteDance on 2022/3/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (BUCommon)

// 图片高斯模糊效果
- (UIImage *)bu_transToBlurLevel:(NSUInteger)blurRadius;

@end

NS_ASSUME_NONNULL_END
