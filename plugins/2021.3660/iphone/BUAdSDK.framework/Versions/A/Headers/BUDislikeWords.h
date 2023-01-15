//
//  BUDislikeWords.h
//  BUAdSDK
//
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import "BUInterfaceBaseObject.h"

 __attribute__((objc_subclassing_restricted))
@interface BUDislikeWords : BUInterfaceBaseObject <NSCoding>
@property (nonatomic, copy, readonly) NSString *dislikeID;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, assign, readonly) BOOL isSelected;
@property (nonatomic, copy,readonly) NSArray<BUDislikeWords *> *options;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError **)error;

@end
