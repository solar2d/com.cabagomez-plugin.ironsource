//
//  DTBDebugProperties.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DTBDebugProperties : NSObject

// Test flag to test out or enable SKAdnetwork response
@property (nonatomic) BOOL skadnTestMode;
@property (nonatomic) NSString * skadnTestModeVersion;

// Test flag to test out the mocked config response for GDPR region
@property (nonatomic) BOOL gdprRegionTestMode;

+ (BOOL)isDebugFlagTurnedOnForFeature:(NSString *)feature;

@end

NS_ASSUME_NONNULL_END
