//
//  NSMutableURLRequest+Additions.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, APSHTTPMethod) {
    APSHTTPMethodGET,
    APSHTTPMethodPOST
};

typedef NS_ENUM(NSInteger, APSHTTPContentType) {
    APSHTTPContentTypeDefault,
    APSHTTPContentTypeJavascript,
    APSHTTPContentTypeJSON
};

@interface NSMutableURLRequest (Additions)

/**
 * Factory method to create a new NSMutableURLRequest.
 *
 * @param url The URL string.
 * @param method The HTTP method @{ref APSHTTPMethod} value, must be either APSHTTPMethodGET or APSHTTPMethodPOST.
 * @param acceptType The accepted HTTP resposne content type @{ref APSHTTPContentType} used in the http request header
 * 'Accept' field. If the type is APSHTTPContentTypeDefault, it will not explicitly set the 'Accept' field and rely on
 * the default.
 * @return a new NSMutableURLRequest instance.
 */
+ (NSMutableURLRequest *)requestWithURL:(NSString *)url
                             HTTPMethod:(APSHTTPMethod)method
                             acceptType:(APSHTTPContentType)acceptType;

/**
 * A convenient method to set the HTTP body from an input string. If the request does not have payload, this method
 * is optional.
 * @param body The HTTP request body string.
 */
- (void)setHTTPBodyString:(NSString *)body;

/**
 * Set the HTTP content type of the request payload. If the request does not have payload, this method is optional.
 * @param contentType The HTTP content type @{ref APSHTTPContentType}
 */
- (void)setHTTPContentType:(APSHTTPContentType)contentType;

@end

NS_ASSUME_NONNULL_END
