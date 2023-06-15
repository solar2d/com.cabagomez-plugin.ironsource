//
//  ISProductSettings.h
//  IronSource
//
//  Created by Yotam Ohayon on 07/01/2016.
//  Copyright © 2016 IronSource. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ISProductSettings : NSObject

@property (readonly, strong)    NSArray         *placements;
@property (readonly, assign)    NSUInteger      maxNumOfAdaptersToLoadOnStart;
@property (readonly, assign)    BOOL            advancedLoading;
@property (readonly, assign)    NSUInteger      adapterTimeOutInSeconds;
@property (assign)              NSInteger       bannerInterval;
@property (assign)              NSInteger       loadRVInterval;
@property (assign)              NSUInteger      delayLoadFailureNotificationInSeconds;
@property (readonly,assign)     NSInteger       expiredDurationInMinutes;
@property (readonly,assign)     NSInteger       delayLoadFailureTimeout;
@property (readonly,assign)     BOOL            isOneFlow;
@property (readonly,assign)     BOOL            isBiddingDataAsyncEnabled;
@property (readonly,strong)     NSMeasurement   *biddingDataAsyncTimeout;


- (instancetype) initWithplacements:(NSArray *)placements
      maxNumOfAdaptersToLoadOnStart:(NSUInteger)maxAdapters
                    advancedLoading:(BOOL)advancedLoading
            adapterTimeOutInSeconds:(NSUInteger)adapterTimeout
delayLoadFailureNotificationInSeconds:(NSUInteger)delayLoadFailure
           expiredDurationInMinutes:(NSInteger)expiredDurationInMinutes
            delayLoadFailureTimeout:(NSInteger)delayLoadFailureTimeout
                          isOneFlow:(BOOL)isOneFlow
          isBiddingDataAsyncEnabled:(BOOL)isBiddingDataAsyncEnabled
            biddingDataAsyncTimeout:(NSMeasurement *)biddingDataAsyncTimeout;
@end
