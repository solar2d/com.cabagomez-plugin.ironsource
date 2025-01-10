//
//  UIView+DTB.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <UIKit/UIKit.h>
#import "APSDeprecatedMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIView (DTB)

- (void)setWidth:(CGFloat)width height:(CGFloat) height APS_DEPRECATED_MESSAGE();
- (void)setBorderWidth:(CGFloat)width borderColor:(UIColor *) borderColor APS_DEPRECATED_MESSAGE();
- (void) setParentSize APS_DEPRECATED_MESSAGE();
- (void) setParentWidth APS_DEPRECATED_MESSAGE();
- (void) setParentHeight APS_DEPRECATED_MESSAGE();

- (UIViewController *) findOwningController APS_DEPRECATED_MESSAGE();
- (NSArray *)findChildrenOfClass:(Class) clz APS_DEPRECATED_MESSAGE();
- (UIView *)findAncestorOfClass:(Class) clz APS_DEPRECATED_MESSAGE();
+ (UIInterfaceOrientation) currentOrientation APS_DEPRECATED_MESSAGE();
- (CGSize) screenSize APS_DEPRECATED_MESSAGE();
- (CGSize) maxSize APS_DEPRECATED_MESSAGE();

+ (UIViewController *) getTopViewController APS_DEPRECATED_MESSAGE();
+ (BOOL) isStoreKitInTheForeground APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
