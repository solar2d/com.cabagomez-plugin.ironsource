//
//  DTBAdResponse+Mediation.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <UIKit/UIKit.h>
#import "APSDeprecatedMessage.h"
#import "DTBAdResponse.h"
NS_ASSUME_NONNULL_BEGIN

@interface DTBAdResponse (Mediation)

- (NSString *_Nonnull) bidInfo APS_DEPRECATED_MESSAGE();

- (NSString *_Nonnull) amznSlots APS_DEPRECATED_MESSAGE("Use -[APSAd amznSlots] instead.");

- (NSDictionary * _Nonnull)mediationHints:(BOOL) isSmartBanner APS_DEPRECATED_MESSAGE();

- (NSDictionary *_Nonnull) mediationHints APS_DEPRECATED_MESSAGE("Use -[APSAd mediationHints] instead.");

- (void)setHostName:(NSString *_Nonnull) hostName APS_DEPRECATED_MESSAGE();

- (void)setCrid:(NSString *_Nonnull) crid APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
