//
//  DTBExpectedSize.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <UIKit/UIKit.h>
#import "APSDeprecatedMessage.h"

NS_ASSUME_NONNULL_BEGIN

@protocol DTBExpectedSize <NSObject>

@property(nonatomic, copy) NSNumber *_Nullable APS_targetWidth APS_DEPRECATED_MESSAGE(); // append prefix to prevent name clashes (APS-TTT-6968)
@property(nonatomic, copy) NSNumber *_Nullable APS_targetHeight APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
