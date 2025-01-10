//
//  NSJSONSerialization+Helpers.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSJSONSerialization (Helpers)

/**
 * Returns a JSON string of an input dictionary.
 * @param dictionary The input dictionary. Must not be nil.
 * @returns A Json string from the input dictionary. If there is an error during the conversion or the input is nil, the method will return nil.
 */
+ (NSString * _Nullable)jsonToString:(NSDictionary *)dictionary;

/**
 * @param data A non-null NSData of serialized JSON object.
 * @return A dictionary of the JSON object. Returns nil if 1) there are exceptions or 2) top level JSON is an array, not object.
 */
+ (NSDictionary * _Nullable)dataToJSON:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
