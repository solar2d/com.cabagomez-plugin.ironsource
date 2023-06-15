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
			"plugin_ironsource"
		},
		frameworks = { 
			'Ironsource', 
			--AdColony
			'AdColony',
			'ISAdColonyAdapter',
			-- Admob
			'GoogleMobileAds',
			'UserMessagingPlatform',
			'ISAdMobAdapter',
			-- Applovin
			'AppLovinSDK',
			'ISAppLovinAdapter',
			-- Chartboost
			'ISChartboostAdapter',
			'ChartboostSDK',
			-- Facebook
			'FBSDKCoreKit_Basics',
			'FBAudienceNetwork',
			'ISFacebookAdapter',
			-- Tapjoy
			'ISTapjoyAdapter',
			'Tapjoy',
			-- Vungle
			'ISVungleAdapter', 
			'VungleAdsSDK',
			-- Unity
			'UnityAds',
			'ISUnityAdsAdapter',
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
