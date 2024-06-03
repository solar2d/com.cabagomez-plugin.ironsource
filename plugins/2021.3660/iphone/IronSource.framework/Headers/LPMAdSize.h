//
//  LPMAdSize.h
//  IronSource
//
//  Copyright © 2024 IronSource. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, LPMAdSizeType) {
  LPMAdSizeBanner,
  LPMAdSizeLarge,
  LPMAdSizeMediumRectangle,
  LPMAdSizeCustom,
  LPMAdSizeLeaderBoard
};

@interface LPMAdSize : NSObject <NSCopying>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@property(nonatomic, readonly) LPMAdSizeType type;
@property(nonatomic, readonly) NSInteger width;
@property(nonatomic, readonly) NSInteger height;
@property(nonatomic, readonly, copy) NSString* sizeDescription;

+ (instancetype)bannerSize;
+ (instancetype)largeSize;
+ (instancetype)mediumRectangleSize;
+ (instancetype)leaderBoardSize;
+ (instancetype)customSizeWithWidth:(NSInteger)width height:(NSInteger)height;

@end

NS_ASSUME_NONNULL_END
