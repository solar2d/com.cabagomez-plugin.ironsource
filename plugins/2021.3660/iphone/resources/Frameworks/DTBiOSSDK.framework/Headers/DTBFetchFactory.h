//
//  DTBFetchFactory.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"
#import "DTBSlotGroup.h"

NS_ASSUME_NONNULL_BEGIN

@class DTBFetchManager;
@class DTBAdLoader;

@interface DTBFetchFactory : NSObject

+ (DTBFetchFactory *_Nonnull) sharedInstance APS_DEPRECATED_MESSAGE();

/* CREATING FETCH MANAGERS */
- (NSError * _Nullable)createFetchManagerForLoader:(DTBAdLoader *_Nonnull) loader APS_DEPRECATED_MESSAGE();
- (NSError * _Nullable)createFetchManagerForLoader:(DTBAdLoader * _Nonnull)loader isSmartBanner:(BOOL) isSmartBanner APS_DEPRECATED_MESSAGE();

/* RETRIEVING FETCH MANAGERS */
- (DTBFetchManager * _Nullable)fetchManagerBySlotType:(DTBSlotType) slotType APS_DEPRECATED_MESSAGE();

/* REMOVING FETCH MANAGERS */
- (void)removeFetchManagerForSlotType:(DTBSlotType) slotType APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
