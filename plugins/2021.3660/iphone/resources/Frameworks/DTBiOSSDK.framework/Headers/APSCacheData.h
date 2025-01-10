//
//  APSCacheData.h
//  DTBiOSSDK
//
//  Copyright © 2021 amazon.com. All rights reserved.
//

#ifndef APSCacheData_h
#define APSCacheData_h

#define DEFAULT_ADMOB_AUTO_REFRESH_TIME_IN_SEC 29

#import "DTBAdLoader.h"
#import "DTBAdResponse.h"

@interface APSCacheData : NSObject

@property (nonatomic, strong) DTBAdLoader *adLoaderReq;
@property (nonatomic, strong) DTBAdResponse *adResponse;
@property (nonatomic, copy) NSNumber *timestamp;
@property (nonatomic, copy) NSString *requestId;
@property (nonatomic, copy) NSString *serverParameter;
@property (nonatomic, strong) id request;

- (id)initWithRequestId:(NSString *)requestId adLoaderReq:(DTBAdLoader *)adLoaderReq;

@end

#endif /* APSCacheData_h */
