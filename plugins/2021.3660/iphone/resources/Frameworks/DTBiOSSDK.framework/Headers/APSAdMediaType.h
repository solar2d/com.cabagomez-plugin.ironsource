//
//  APSAdMediaType.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#ifndef APSAdMediaType_h
#define APSAdMediaType_h

#import <Foundation/Foundation.h>

/**
 * @abstract Ad media type.
 * @description APS supports both display and video.
 */
typedef NS_ENUM(NSInteger, APSAdMediaType) {
    APSAdMediaTypeDisplay,
    APSAdMediaTypeVideo
};


#endif /* APSAdMediaType_h */
