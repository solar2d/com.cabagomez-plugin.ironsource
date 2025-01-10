//
//  DTBFetchManager.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"

NS_ASSUME_NONNULL_BEGIN

@class DTBAdResponse;
@class DTBFetchManager;

@interface DTBFetchManager : NSObject

@property (nonatomic, copy) NSError *_Nullable error APS_DEPRECATED_MESSAGE();
@property (nonatomic, assign) BOOL isActive APS_DEPRECATED_MESSAGE();

- (instancetype)init NS_UNAVAILABLE;

- (DTBAdResponse *_Nullable) peek APS_DEPRECATED_MESSAGE();
- (DTBAdResponse *_Nullable) pop APS_DEPRECATED_MESSAGE();

- (void) start APS_DEPRECATED_MESSAGE();
- (void) stop APS_DEPRECATED_MESSAGE();
- (BOOL) isEmpty APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
