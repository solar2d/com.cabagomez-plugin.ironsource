//
//  APSAd+MAXAdditions.h
//  DTBiOSSDK
//
//  Copyright © 2023 amazon.com. All rights reserved.
//

#ifndef APSAd_MAXAdditions_h
#define APSAd_MAXAdditions_h

/**
 * Use the constant as a key for passing a local extra paramerter with a successful APSAd
 * in the APSAdRequest completion handler.
 *
 * [maxBannerView setLocalExtraParameterForKey:AMAZON_SUCCESS_RESPONSE
 *                                     value:ad.adResponse];
 */
#define AMAZON_SUCCESS_RESPONSE @"amazon_ad_response"

/**
 * Use the constant as a key for passing a local extra paramerter with a failed APSAd
 * in the APSAdRequest completion handler.
 *
 * [maxBannerView setLocalExtraParameterForKey:AMAZON_ERROR_RESPONSE
 *                                     value:ad.adError];
 */
#define AMAZON_ERROR_RESPONSE   @"amazon_ad_error"

#endif /* APSAd_MAXAdditions_h */
