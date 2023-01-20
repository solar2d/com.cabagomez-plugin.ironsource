local metadata =
{
	plugin =
	{
		format = 'staticLibrary',
		staticLibs = {
			"bz2",
			"iconv",
			"c++","z",
			"sqlite3",
			"xml2",
			"c++abi",
			"resolv.9",
			'plugin_ironsource'
		},
		frameworks = { 
			'Ironsource', 
			-- Tapjoy
			'ISTapjoyAdapter',
			'Tapjoy',
			-- Vungle
			'ISVungleAdapter', 
			'VungleSDK',
			-- Facebook
			'FBSDKCoreKit_Basics',
			'FBAudienceNetwork',
			'ISFacebookAdapter',
			-- Admob
			'GoogleMobileAds',
			'GoogleUtilities',
			'GoogleAppMeasurement',
			'nanopb',
			'UserMessagingPlatform',
			'PromisesObjC',
			'ISAdMobAdapter',
			-- Applovin
			'AppLovinSDK',
			'ISAppLovinAdapter',
			-- Unity
			'ISUnityAdsAdapter',
			'UnityAds',
			-- Chartboost
			'ISChartboostAdapter',
			'ChartboostSDK',
			-- Other libraries
			"AdSupport",
			"AudioToolbox",
			"AVFoundation",
			"CFNetwork",
			"CoreGraphics",
			"CoreLocation",
			"CoreMedia",
			"CoreTelephony",
			"CoreVideo",
			"Foundation",
			"MobileCoreServices",
			"QuartzCore",
			"Security",
			"StoreKit",
			"WebKit",
			"SystemConfiguration",
			"NotificationCenter"
		},
		usesSwift = true
	},
}



return metadata
