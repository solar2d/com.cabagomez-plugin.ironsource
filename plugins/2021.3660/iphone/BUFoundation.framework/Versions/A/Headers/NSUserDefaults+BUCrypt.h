//
//  NSUserDefaults+BUCrypt.h
//  BUFoundation
//
//  Created by Willie on 2020/9/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSUserDefaults (BUCrypt)

- (void)setValue:(nullable id)value
          forKey:(NSString *)key
           crypt:(BOOL)crypt
           error:(NSError **)error  __attribute__((deprecated("This method will become invalid in version 4300, please use '[BUPersistence commonPersistence] setObject:forkey'")));

- (nullable id)valueForKey:(NSString *)defaultName
                     crypt:(BOOL)crypt
                     error:(NSError **)error  __attribute__((deprecated("This method will become invalid in version 4300, please use '[BUPersistence commonPersistence] objectForKey:'")));

- (void)removeObjectForKey:(NSString *)defaultName
                     crypt:(BOOL)crypt
                     error:(NSError **)error  __attribute__((deprecated("This method will become invalid in version 4300, please use '[BUPersistence commonPersistence] removeObjectsForKeys:'")));;

- (void)bu_synchronize;

@end

NS_ASSUME_NONNULL_END
