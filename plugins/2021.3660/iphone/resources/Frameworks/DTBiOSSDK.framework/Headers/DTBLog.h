//
//  DTBLog.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>

// Log level for the DTBLog util class.
// Lower = finer-grained logs.
typedef enum {
    DTBLogLevelAll   = 0,
    DTBLogLevelTrace = 10,
    DTBLogLevelDebug = 20,
    DTBLogLevelInfo  = 30,
    DTBLogLevelWarn  = 40,
    DTBLogLevelError = 50,
    DTBLogLevelFatal = 60,
    DTBLogLevelOff   = 70
} DTBLogLevel;
