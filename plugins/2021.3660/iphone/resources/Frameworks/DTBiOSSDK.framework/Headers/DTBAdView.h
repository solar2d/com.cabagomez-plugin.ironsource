//
//  DTBAdView.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "APSDeprecatedMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface DTBAdView : WKWebView

- (void)evaluateJavaScriptFromString:(NSString *) script APS_DEPRECATED_MESSAGE();

@end

NS_ASSUME_NONNULL_END
