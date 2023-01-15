//
//  BUQueueManager.h
//  BUFoundation
//
//  Created by Rush.D.Xzj on 2021/8/6.
//

#import <Foundation/Foundation.h>
#import "BUQueueManagerConfig.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, BUHierarchy) {
    BUHierarchy_BUAdSDK,
    BUHierarchy_BUFoundation,
    BUHierarchy_BURelyFoundation,
    BUHierarchy_BUCore,
};

@interface BUQueueManager : NSObject

@property (nonatomic, strong, readonly) BUQueueManagerConfig *config;

- (void)updateConfig:(BUQueueManagerConfig *)config;


- (dispatch_queue_t)serialQueueWithHierarchy:(BUHierarchy)hierarchy suffixLabel:(NSString *)suffixLabel;
- (dispatch_queue_t)concurrentQueueWithHierarchy:(BUHierarchy)hierarchy suffixLabel:(NSString *)suffixLabel;

#pragma mark - Signal
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
