//
//  APSDeprecatedMessage.h
//  DTBiOSSDK
//
//  Copyright © 2022 amazon.com. All rights reserved.
//

#ifndef APSDeprecatedMessage_h
#define APSDeprecatedMessage_h

#define APS_DEPRECATED_MESSAGE(msg)

/* Uncomment this to enable the macro.
#ifdef APS_INTERNAL
#define APS_DEPRECATED_MESSAGE(msg)
#else
#define APS_DEPRECATED_MESSAGE(msg) __attribute((deprecated(msg)))
#endif
*/

#endif /* APSDeprecatedMessage_h */
