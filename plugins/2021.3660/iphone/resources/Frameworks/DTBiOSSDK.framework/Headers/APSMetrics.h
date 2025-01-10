//
//  APSMetrics.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import "APSMetricsPerfEventModelBuilder.h"
#import "APSMetricsSdkInfo.h"
#import "APSMetricsDeviceInfo.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const APSMETRICS_FIELD_VERSION;
extern NSString * const APSMETRICS_FIELD_APS;
extern NSString * const APSMETRICS_FIELD_TIMESTAMP;
extern NSString * const APSMETRICS_FIELD_DEVICEINFO;
extern NSString * const APSMETRICS_FIELD_OS;
extern NSString * const APSMETRICS_FIELD_PLATFORM;
extern NSString * const APSMETRICS_FIELD_PLATFORMCATEGORY;
extern NSString * const APSMETRICS_FIELD_PLATFORMCATEGORYVERSION;
extern NSString * const APSMETRICS_FIELD_DEVICETYPE;
extern NSString * const APSMETRICS_FIELD_SCREENSIZE;
extern NSString * const APSMETRICS_FIELD_ID;
extern NSString * const APSMETRICS_FIELD_OSVERSION;
extern NSString * const APSMETRICS_FIELD_MANUFACTURER;
extern NSString * const APSMETRICS_FIELD_MODEL;
extern NSString * const APSMETRICS_FIELD_SDK;
extern NSString * const APSMETRICS_FIELD_APSVERSION;
extern NSString * const APSMETRICS_FIELD_ADAPTERVERSION;
extern NSString * const APSMETRICS_FIELD_METRICS;
extern NSString * const APSMETRICS_FIELD_CUSTOM;
extern NSString * const APSMETRICS_FIELD_NAME;
extern NSString * const APSMETRICS_FIELD_VALUE;
extern NSString * const APSMETRICS_FIELD_EXTRAATTRS;
extern NSString * const APSMETRICS_FIELD_VIDEOFLAG;
extern NSString * const APSMETRICS_FIELD_PERFORMANCE;
extern NSString * const APSMETRICS_FIELD_BIDID;
extern NSString * const APSMETRICS_FIELD_NETWORK;
extern NSString * const APSMETRICS_FIELD_RESULT;
extern NSString * const APSMETRICS_FIELD_STARTTIME;
extern NSString * const APSMETRICS_FIELD_ENDTIME;
extern NSString * const APSMETRICS_FIELD_HOSTNAME;
extern NSString * const APSMETRICS_FIELD_REFRESHFLAG;
extern NSString * const APSMETRICS_FIELD_BIDEVENT;
extern NSString * const APSMETRICS_FIELD_ADAPTEREVENT;
extern NSString * const APSMETRICS_FIELD_FETCHEVENT;
extern NSString * const APSMETRICS_FIELD_IMPRESSIONEVENT;
extern NSString * const APSMETRICS_FIELD_URL;
extern NSString * const APSMETRICS_FIELD_CONNECTIONTYPE;
extern NSString * const APSMETRICS_FIELD_ADCLICKEVENT;
extern NSString * const APSMETRICS_FIELD_VIDEOCOMPLETEDEVENT;
extern NSString * const APSMETRICS_FIELD_VIDEOFLAG;
extern NSString * const APSMETRICS_FIELD_ADFORMAT;
extern NSString * const APSMETRICS_FIELD_CORRELATIONID;

extern NSString * const METRICS_DEFAULT_ENDPOINT_URL;
extern NSString * const METRICS_DEFAULT_METRICS_API_KEY;

/*
 * This ApsMetrics class handles performance and custom metrics.
 * Sending metrics events from the SDK is enabled/disabled using the
 * remote config service.
 *
 * {
 *      ...
 *      "apsmetrics" : {
 *          "mobile" : {
 *              "samplingPercentage" : 0.25,              //default is 0, Range is from 0 to 100
 *              "apiKey": "apiKeyValue",                  //default is empty
 *              "url": "https://x.amazon.com/metricsurl"  //default is emptyString
 *          }
 *      }
 *      ...
 * }
 */
@interface APSMetrics : NSObject

/**
 * Called when AAX bid event needs to be logged
 */
+ (void)bidEvent:(APSMetricsPerformanceAaxBidEvent *)aaxBidEvent bidId:(NSString * _Nullable)bidId;

/**
 * Called when custom event needs to be logged
 */
+ (void)customEvent:(NSString *)eventName value:(NSString * _Nullable)eventValue extra:(NSDictionary * _Nullable)extra;

/**
 * Called when ad event needs to be logged as part of performance events funnel
 */
+ (void)adEvent:(NSString * _Nullable)bidId builder:(APSMetricsPerfEventModelBuilder *)builder;

/**
 * Called when adapterevent needs to be logged as part of performance events funnel
 */
+ (void)adapterEvent:(NSString * _Nullable)bidId builder:(APSMetricsPerfEventModelBuilder *)builder;

/**
 * @return the current time
 */
+ (NSNumber *)currentTimeInMilliseconds;

/**
 * @return metrics API schema version
 */
+ (NSInteger)metricsApiSchemaVersion;

/**
 * @return adapter version
 */
+ (NSString *)adapterVersion;

/**
 * Sets adapter version
 */
+ (void)setAdapterVersion:(NSString *)adapterVersion;

/**
 * @return Metrics device information
 */
+ (APSMetricsDeviceInfo *)apsMetricsDeviceInfo;

/**
 * Sets device information
 */
+ (void)setApsMetricsDeviceInfo:(APSMetricsDeviceInfo *)deviceInfo;

/**
 * @return Metrics SDK information
 */
+ (APSMetricsSdkInfo *)apsMetricsSdkInfo;

/**
 * Sets SDK information
 */
+ (void)setApsMetricsSdkInfo:(APSMetricsSdkInfo *)sdkInfo;

// Sample rate in percent
+ (double)samplingPercentage;
+ (void)setSamplingPercentage:(double)rate;

// Performance and custom metrics endpoint URL
+ (NSString *)endpointUrl;
+ (void)setEndpointUrl:(NSString * _Nullable)url;

// Performance and custom metrics API key
+ (NSString *)apiKey;
+ (void)setApiKey:(NSString * _Nullable)key;

@end

NS_ASSUME_NONNULL_END
