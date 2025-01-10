//
//  DTBSlotGroup.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "APSDeprecatedMessage.h"
#import "DTBAdSize.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    SLOT_320_50 = 0,
    SLOT_300_250 = 1,
    SLOT_728_90 = 2,
    SLOT_SMART = 3
} DTBSlotType APS_DEPRECATED_MESSAGE();

NSString *NSStringFromSlotType(DTBSlotType slotType) APS_DEPRECATED_MESSAGE();
DTBSlotType slotTypeFromCGSize(CGSize slotCGSize) APS_DEPRECATED_MESSAGE();

@interface DTBSlotGroup : NSObject

- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, copy) NSString *_Nonnull name APS_DEPRECATED_MESSAGE();

- (instancetype)initWithName:(NSString *_Nonnull) name APS_DEPRECATED_MESSAGE();

- (void)addSize:(DTBAdSize *_Nonnull) size APS_DEPRECATED_MESSAGE();

- (DTBAdSize * _Nullable)sizeByWidth:(NSInteger)width height:(NSInteger) height APS_DEPRECATED_MESSAGE();

- (DTBAdSize * _Nullable)sizeByWidth:(NSInteger)width height:(NSInteger)height type:(ADType) type APS_DEPRECATED_MESSAGE();

- (DTBAdSize * _Nullable)sizeByUUID:(NSString *_Nonnull) slotUUID APS_DEPRECATED_MESSAGE();

- (DTBAdSize * _Nullable)sizeBySlotType:(DTBSlotType) type APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
