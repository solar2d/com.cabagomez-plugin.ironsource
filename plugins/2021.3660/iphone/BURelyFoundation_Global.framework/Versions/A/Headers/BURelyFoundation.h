//
//  BURelyFoundation.h
//  BURelyFoundation
//
//  Created by zth on 2022/1/4.
//

#ifndef BURelyFoundation_h
#define BURelyFoundation_h

#if __has_include(<BURelyFoundation/BURelyFoundation.h>)

# pragma mark - NET

#import <BURelyFoundation/BUBaseRequest.h>
#import <BURelyFoundation/BUNetworkAgent.h>

# pragma mark - AFN

#import <BURelyFoundation/BU_AFHTTPSessionManager.h>
#import <BURelyFoundation/BU_AFURLRequestSerialization.h>
#import <BURelyFoundation/BU_AFURLResponseSerialization.h>
#import <BURelyFoundation/BU_AFURLSessionManager.h>

#else

#import "BUBaseRequest.h"
#import "BUNetworkAgent.h"

# pragma mark - AFN

#import "BU_AFHTTPSessionManager.h"
#import "BU_AFURLRequestSerialization.h"
#import "BU_AFURLResponseSerialization.h"
#import "BU_AFURLSessionManager.h"

#endif


#endif /* BURelyFoundation_h */
