//
//  SKAdNetworkInfo.h
//  DTBiOSSDK
//
//  Copyright © 2024 amazon.com. All rights reserved.
//

#ifndef SKAdNetworkInfo_h
#define SKAdNetworkInfo_h

//#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

NS_ASSUME_NONNULL_BEGIN

// Constants for JSON keys
extern NSString *const kExtKey;
extern NSString *const kSKAdNetworkKey;
extern NSString *const kVersionKey;
extern NSString *const kNetworkKey;
extern NSString *const kSourceIdentifier;
extern NSString *const kCampaignKey;
extern NSString *const kiTunesItemKey;
extern NSString *const kSourceAppKey;
extern NSString *const kProductPageIDKey;
extern NSString *const kFidelitiesKey;
extern NSString *const kFidelityKey;
extern NSString *const kSignatureKey;
extern NSString *const kNonceKey;
extern NSString *const kTimestampKey;
extern NSString *const kSKAdNetworkVersion2_0;
extern NSString *const kSKAdNetworkVersion2_2;
extern NSString *const kSKAdNetworkVersion4_0;

@interface Fidelity : NSObject

@property (nonatomic, assign) NSInteger fidelity;
@property (strong, nonatomic) NSString *signature;
@property (strong, nonatomic) NSString *nonce;
@property (strong, nonatomic) NSNumber *timestamp;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface SKAdNetworkInfo : NSObject

@property (strong, nonatomic) NSString *version;
@property (strong, nonatomic) NSString *network;
@property (strong, nonatomic) NSNumber *campaign;         // used for SKAN 2.0, 2.2 and 3
@property (strong, nonatomic) NSNumber *sourceidentifier; // used for SKAN 4
@property (strong, nonatomic) NSNumber *itunesitem;
@property (strong, nonatomic) NSNumber *sourceapp;
@property (strong, nonatomic) NSString *productpageid;
@property (strong, nonatomic) NSArray<Fidelity *> *fidelities;  // used for SKAN 2.2, 3, 4
@property (strong, nonatomic) NSDictionary *ext;
@property (strong, nonatomic) NSString *signature;         // used for SKAN 2.0
@property (strong, nonatomic) NSString *nonce;             // used for SKAN 2.0
@property (strong, nonatomic) NSNumber *timestamp;         // used for SKAN 2.0

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
- (NSDictionary *)storeLoadProductParameters;
- (NSArray<SKAdImpression *> * _Nullable)adImpressions API_AVAILABLE(ios(14.5));

@end

NS_ASSUME_NONNULL_END

#endif /* SKAdNetworkInfo_h */
