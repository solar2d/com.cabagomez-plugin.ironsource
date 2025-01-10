//
//  APSMraidVersions.h
//  DTBiOSSDK
//
//  Copyright (c) 2023 Amazon Publisher Services. All rights reserved.

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "DTBMraidConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSMraidVersions : NSObject

/**
 * @return YES if the MRAID versions are defined.
 */
@property (nonatomic, class, assign) BOOL isDefined;
/**
 * @return An array of MRAID version strings, e.g., @[ @"1.0", @"2.0", @"3.0" ].
 */
@property (nonatomic, class, copy, nullable) NSArray<NSString *> *mraids;

/**
 * Determine the MRAID supported versions. Once the method is called, the @{ref isDefined} will be set to YES.
 */
+ (void)defineVersions;

/**
 * Reset the MRAID isDefined and @{ref mraids} class properties.
 */
+ (void)reset;

/**
 * @return YES if the environment supports creative rendering.
 */
+ (BOOL)isServerlessEnvironment;

@end

NS_ASSUME_NONNULL_END
