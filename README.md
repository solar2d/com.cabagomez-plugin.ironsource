# com.cabagomez-plugin.ironsource
Solar2d Ironsource Plugin.

-- The iOS version only supports iOS 12 and after. 
-- The frameworks for the networks have been bitcode and anything other than arm64 stripped.
-- User messaging platform (UMP) for consent is now integrated into the plugin.

-- If you find an issue please submit an issue on this repo. If I am able to reproduce it and impacts me, I will try to resolve it. If you need more support than this or want to individually ad plugins, I would recommend the ironsource plugin by Scott Harrison: https://solar2dmarketplace.com/plugins?IronSource_tech-scotth


1. Add the plugin.
```
    ["plugin.ironsource"] = 
        {
            publisherId = "com.cabagomez"
        },
```   
2. Plugin supports Android 21 and iOS 12 and above. Add to your build settings file:   
For android:   
```  
android =
    {
        minSdkVersion = "21",
    }
```   
For iOS:   
```   
iphone =
	{
        plist =
		{
            MinimumOSVersion = "12",
        }
    }
```   
3. Reference the plugin:
```
local ironsource = require("plugin.ironsource")
```

4. Init. 
```
ironsource.init(
    adListerner, -- Listener. Required.
        {
            key=<replace with your key>, -- Your ironsource app key. Required.
            showDebugLog=false, -- Optional debug param. Defaults to false. Show extended logs.
            coppaUnderAge=false, -- Optional. Defaults to false.
            gdprUnderAge=false, -- Optional. Defaults to false.
            showValidateIntegrationUI=false, -- Optional. Shows integration validation UI. Defaults to false.
            userId="xsdsfsd", -- Optional. UserId. If not provided ironsource will autogenerate one.
            hasUserConsent=false, -- Optional. Targeted ads. Defaults to false.
            ccpaDoNotSell=false, -- Optional. False = Sell the data. True = do not sell. Default is false.
            isAutoLoad = true, -- Optional. True = Banner and Interstitial will autoload. Default is true.
            consentView = false, -- Optional. True = send consent view events. iOS only. Default is false.
            attStatus = "authorized", -- Optional. Sending "authorized" will let Facebook know that tracking is enabled. Otherwise it will set it to not enabled.
            showConsentDialog = true, -- Optional. Enables consent dialog.
            iAmInEurope = true, -- Optional. Tests the consent dialog by placing the user in the EU.
            deviceTestId = "DABA74EACEC5434B8BFB152A3504B10A" -- Optional. REQUIRED if iAmInEurope is set to true.

        } -- Table with options.
    )
```

5. Show.
```
    ironsource.show("<adtype>", -- Ad type. Valid values are: "interstitial", "rewardedVideo", "banner", "consentView"
        {
            y=<bannerPosition>, -- Optional. Valid for banner. Valid values are "top" and "bottom". Defaults to "bottom".
            placementName=<placement name> -- Optional. Valid for "rewardedVideo", "interstitial".
        } -- Optional table.
    )
```

6. Is Available.
```
    ironsource.isAvailable("<adtype>",
        {
            placementName=<placement name> -- Optional. Valid for "rewardedVideo", "interstitial", "banner".
        } -- Optional table.
    
    )
```  
7. Hide.
```
    ironsource.hide() -- Only functions for banner.
```

8. Load.
```
   ironsource.load( "<adType>", -- Ad type. Valid values are: "interstitial", "banner". 
        "<network>" -- Optional. Only one supported is "aps". Amazon ads have to be loaded intentionally.
    ) 
   -- Ironsource autoloads rewarded.
```   
Load all ads network except Amazon:   
```
ironsource.load( "interstitial" )
```   
Load Amazon ad:   
```
ironsource.load( "interstitial", "aps")
```   

9. Set custom properties.   
```
ironsource.setCustomProperty(
    "<keyName>", 
    "<keyValue>"
)
```  

10. Logs example:

loaded ("interstitial", "banner")
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"loaded",
    "provider":"ironsource",
    "response":"", -- If error. The error reason would be here.
    "type":"<adType>",
    "isError":false -- Always true for show.
}
```

show ("rewardedVideo"-on error, "interstitial")
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"show",
    "provider":"ironsource",
    "response":"", -- If error. The error reason would be here. Always populated for rewarded.
    "type":"<adType>",
    "isError":false -- Always true for rewarded.
}
```

available ("rewardedVideo")
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"available",
    "provider":"ironsource",
    "response":"<isAvailable>", -- true it is currently available and loaded. If the ad expires you will get a similar event but false.
    "type":"<adType>",
    "isError":false -- Would be true if it couldn't load.
}
```

reward ( "rewardedVideo" )
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"reward",
    "provider":"ironsource",
    "response":"<>", -- error string if isError = true or awarded credit as string.
    "type":"<adtype>",
    "isError":false -- No error available for rewardedVideo.
}
```

opened      ("rewardedVideo", "interstitial")

closed      ("rewardedVideo", "interstitial")

started     ("rewardedVideo" ) 

ended       ("rewardedVideo" )

presented   ("banner")

dismissed   ("banner")

adLeftApp   ("banner")

```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"opened",
    "provider":"ironsource",
    "response":"", -- Never filled for these phases.
    "type":"rewardedVideo", 
    "isError":false -- Always false for these phases.
}
```


clicked ("rewardedVideo", "interstitial", "banner")
```
ironsource:	{
    "data":"",
    "name":"ironsource",
    "phase":"clicked",
    "provider":"ironsource",
    "response":"<placementname>", -- Placement name. Rewarded only.
    "type":"<adType>",
    "isError":false
}
```  

segmentReceived -- Segment being used by this particular user     
```
ironsource:	{
      "data":"",
      "name":"ironsource",
      "phase":"segmentReceived",
      "provider":"ironsource",
      "response":"<segmentName>",
      "type":"segment",
      "isError":false
    }   
```  

12. Please add these values to your build settings or your own values. These values come directly from Ironsource tool use at your own risk.
```
SKAdNetworkItems = {  
                { SKAdNetworkIdentifier = "su67r6k2v3.skadnetwork" },
                { SKAdNetworkIdentifier = "f7s53z58qe.skadnetwork" },
                { SKAdNetworkIdentifier = "2u9pt9hc89.skadnetwork" },
                { SKAdNetworkIdentifier = "hs6bdukanm.skadnetwork" },
                { SKAdNetworkIdentifier = "8s468mfl3y.skadnetwork" },
                { SKAdNetworkIdentifier = "c6k4g5qg8m.skadnetwork" },
                { SKAdNetworkIdentifier = "v72qych5uu.skadnetwork" },
                { SKAdNetworkIdentifier = "44jx6755aq.skadnetwork" },
                { SKAdNetworkIdentifier = "prcb7njmu6.skadnetwork" },
                { SKAdNetworkIdentifier = "m8dbw4sv7c.skadnetwork" },
                { SKAdNetworkIdentifier = "3rd42ekr43.skadnetwork" },
                { SKAdNetworkIdentifier = "4fzdc2evr5.skadnetwork" },
                { SKAdNetworkIdentifier = "t38b2kh725.skadnetwork" },
                { SKAdNetworkIdentifier = "f38h382jlk.skadnetwork" },
                { SKAdNetworkIdentifier = "424m5254lk.skadnetwork" },
                { SKAdNetworkIdentifier = "ppxm28t8ap.skadnetwork" },
                { SKAdNetworkIdentifier = "av6w8kgt66.skadnetwork" },
                { SKAdNetworkIdentifier = "cp8zw746q7.skadnetwork" },
                { SKAdNetworkIdentifier = "4468km3ulz.skadnetwork" },
                { SKAdNetworkIdentifier = "e5fvkxwrpn.skadnetwork" },
                { SKAdNetworkIdentifier = "4pfyvq9l8r.skadnetwork" },
                { SKAdNetworkIdentifier = "yclnxrl5pm.skadnetwork" },
                { SKAdNetworkIdentifier = "tl55sbb4fm.skadnetwork" },
                { SKAdNetworkIdentifier = "mlmmfzh3r3.skadnetwork" },
                { SKAdNetworkIdentifier = "klf5c3l5u5.skadnetwork" },
                { SKAdNetworkIdentifier = "9t245vhmpl.skadnetwork" },
                { SKAdNetworkIdentifier = "9rd848q2bz.skadnetwork" },
                { SKAdNetworkIdentifier = "7ug5zh24hu.skadnetwork" },
                { SKAdNetworkIdentifier = "7rz58n8ntl.skadnetwork" },
                { SKAdNetworkIdentifier = "ejvt5qm6ak.skadnetwork" },
                { SKAdNetworkIdentifier = "5lm9lj6jb7.skadnetwork" },
                { SKAdNetworkIdentifier = "mtkv5xtk9e.skadnetwork" },
                { SKAdNetworkIdentifier = "6g9af3uyq4.skadnetwork" },
                { SKAdNetworkIdentifier = "uw77j35x4d.skadnetwork" },
                { SKAdNetworkIdentifier = "u679fj5vs4.skadnetwork" },
                { SKAdNetworkIdentifier = "rx5hdcabgc.skadnetwork" },
                { SKAdNetworkIdentifier = "g28c52eehv.skadnetwork" },
                { SKAdNetworkIdentifier = "cg4yq2srnc.skadnetwork" },
                { SKAdNetworkIdentifier = "9nlqeag3gk.skadnetwork" },
                { SKAdNetworkIdentifier = "275upjj5gd.skadnetwork" },
                { SKAdNetworkIdentifier = "wg4vff78zm.skadnetwork" },
                { SKAdNetworkIdentifier = "qqp299437r.skadnetwork" },
                { SKAdNetworkIdentifier = "2fnua5tdw4.skadnetwork" },
                { SKAdNetworkIdentifier = "3qcr597p9d.skadnetwork" },
                { SKAdNetworkIdentifier = "3qy4746246.skadnetwork" },
                { SKAdNetworkIdentifier = "3sh42y64q3.skadnetwork" },
                { SKAdNetworkIdentifier = "5a6flpkh64.skadnetwork" },
                { SKAdNetworkIdentifier = "cstr6suwn9.skadnetwork" },
                { SKAdNetworkIdentifier = "kbd757ywx3.skadnetwork" },
                { SKAdNetworkIdentifier = "n6fk4nfna4.skadnetwork" },
                { SKAdNetworkIdentifier = "p78axxw29g.skadnetwork" },
                { SKAdNetworkIdentifier = "s39g8k73mm.skadnetwork" },
                { SKAdNetworkIdentifier = "wzmmz9fp6w.skadnetwork" },
                { SKAdNetworkIdentifier = "ydx93a7ass.skadnetwork" },
                { SKAdNetworkIdentifier = "zq492l623r.skadnetwork" },
                { SKAdNetworkIdentifier = "24t9a8vw3c.skadnetwork" },
                { SKAdNetworkIdentifier = "32z4fx6l9h.skadnetwork" },
                { SKAdNetworkIdentifier = "523jb4fst2.skadnetwork" },
                { SKAdNetworkIdentifier = "54nzkqm89y.skadnetwork" },
                { SKAdNetworkIdentifier = "578prtvx9j.skadnetwork" },
                { SKAdNetworkIdentifier = "5l3tpt7t6e.skadnetwork" },
                { SKAdNetworkIdentifier = "6xzpu9s2p8.skadnetwork" },
                { SKAdNetworkIdentifier = "79pbpufp6p.skadnetwork" },
                { SKAdNetworkIdentifier = "9b89h5y424.skadnetwork" },
                { SKAdNetworkIdentifier = "cj5566h2ga.skadnetwork" },
                { SKAdNetworkIdentifier = "feyaarzu9v.skadnetwork" },
                { SKAdNetworkIdentifier = "ggvn48r87g.skadnetwork" },
                { SKAdNetworkIdentifier = "glqzh8vgby.skadnetwork" },
                { SKAdNetworkIdentifier = "gta9lk7p23.skadnetwork" },
                { SKAdNetworkIdentifier = "k674qkevps.skadnetwork" },
                { SKAdNetworkIdentifier = "ludvb6z3bs.skadnetwork" },
                { SKAdNetworkIdentifier = "n9x2a789qt.skadnetwork" },
                { SKAdNetworkIdentifier = "pwa73g5rt2.skadnetwork" },
                { SKAdNetworkIdentifier = "xy9t38ct57.skadnetwork" },
                { SKAdNetworkIdentifier = "zmvfpc5aq8.skadnetwork" },
                { SKAdNetworkIdentifier = "22mmun2rn5.skadnetwork" },
                { SKAdNetworkIdentifier = "294l99pt4k.skadnetwork" },
                { SKAdNetworkIdentifier = "44n7hlldy6.skadnetwork" },
                { SKAdNetworkIdentifier = "4dzt52r2t5.skadnetwork" },
                { SKAdNetworkIdentifier = "4w7y6s5ca2.skadnetwork" },
                { SKAdNetworkIdentifier = "5tjdwbrq8w.skadnetwork" },
                { SKAdNetworkIdentifier = "6964rsfnh4.skadnetwork" },
                { SKAdNetworkIdentifier = "6p4ks3rnbw.skadnetwork" },
                { SKAdNetworkIdentifier = "737z793b9f.skadnetwork" },
                { SKAdNetworkIdentifier = "74b6s63p6l.skadnetwork" },
                { SKAdNetworkIdentifier = "84993kbrcf.skadnetwork" },
                { SKAdNetworkIdentifier = "97r2b46745.skadnetwork" },
                { SKAdNetworkIdentifier = "a7xqa6mtl2.skadnetwork" },
                { SKAdNetworkIdentifier = "b9bk5wbcq9.skadnetwork" },
                { SKAdNetworkIdentifier = "bxvub5ada5.skadnetwork" },
                { SKAdNetworkIdentifier = "dzg6xy7pwj.skadnetwork" },
                { SKAdNetworkIdentifier = "f73kdq92p3.skadnetwork" },
                { SKAdNetworkIdentifier = "g2y4y55b64.skadnetwork" },
                { SKAdNetworkIdentifier = "hdw39hrw9y.skadnetwork" },
                { SKAdNetworkIdentifier = "kbmxgpxpgc.skadnetwork" },
                { SKAdNetworkIdentifier = "lr83yxwka7.skadnetwork" },
                { SKAdNetworkIdentifier = "mls7yz5dvl.skadnetwork" },
                { SKAdNetworkIdentifier = "mp6xlyr22a.skadnetwork" },
                { SKAdNetworkIdentifier = "pwdxu55a5a.skadnetwork" },
                { SKAdNetworkIdentifier = "r45fhb6rf7.skadnetwork" },
                { SKAdNetworkIdentifier = "rvh3l7un93.skadnetwork" },
                { SKAdNetworkIdentifier = "s69wq72ugq.skadnetwork" },
                { SKAdNetworkIdentifier = "w9q455wk68.skadnetwork" },
                { SKAdNetworkIdentifier = "x44k69ngh6.skadnetwork" },
                { SKAdNetworkIdentifier = "x8uqf25wch.skadnetwork" },
                { SKAdNetworkIdentifier = "y45688jllp.skadnetwork" },
                { SKAdNetworkIdentifier = "v9wttpbfk9.skadnetwork" },
                { SKAdNetworkIdentifier = "n38lu8286q.skadnetwork" },
                { SKAdNetworkIdentifier = "238da6jt44.skadnetwork" },
                { SKAdNetworkIdentifier = "252b5q8x7y.skadnetwork" },
                { SKAdNetworkIdentifier = "488r3q3dtq.skadnetwork" },
                { SKAdNetworkIdentifier = "52fl2v3hgk.skadnetwork" },
                { SKAdNetworkIdentifier = "9yg77x724h.skadnetwork" },
                { SKAdNetworkIdentifier = "ecpz2srf59.skadnetwork" },
                { SKAdNetworkIdentifier = "gvmwg8q7h5.skadnetwork" },
                { SKAdNetworkIdentifier = "n66cz3y3bx.skadnetwork" },
                { SKAdNetworkIdentifier = "nzq8sh4pbs.skadnetwork" },
                { SKAdNetworkIdentifier = "pu4na253f3.skadnetwork" },
                { SKAdNetworkIdentifier = "v79kvwwj4g.skadnetwork" },
                { SKAdNetworkIdentifier = "yrqqpx2mcb.skadnetwork" },
                { SKAdNetworkIdentifier = "z4gj7hsk7h.skadnetwork" },
                { SKAdNetworkIdentifier = "7953jerfzd.skadnetwork" }
            },
```


---------------
Current versions for android:  
---------------
--------------- AppLovin     
Adapter 4.3.41         
SDK Version - 12.1.0      

--------------- APS Network       
Adapter 4.3.10   
SDK Version - 9.8.+    

--------------- Chartboost    
Adapter 4.3.14      
SDK Version - 9.6.0        

--------------- Facebook   
Adapter 4.3.45        
SDK Version - 6.16.0    

--------------- Google (AdMob and Ad Manager)   
Adapter 4.3.41     
SDK Version - 22.6.0    

--------------- IronSource   
Adapter 7.7.0   

--------------- Pangle     
Adapter 4.3.23     
SDK Version - 5.6.0.4   

--------------- Smaato     
Adapter 4.3.9     
SDK Version - 22.0.2    

--------------- Vungle       
Adapter 4.3.21     
SDK Version - 7.1.0   

--------------- Unity       
Adapter 4.3.34        
SDK Version - 4.9.2        

---------------
Current versions for Amazon   
--------------- APS Network       
Adapter 4.3.9   
SDK Version - 9.8.+    

--------------- Chartboost    
Adapter 4.3.12      
SDK Version - 9.3.1     

--------------- Facebook   
Adapter 4.3.44       
SDK Version - 6.15.0    

--------------- Google (AdMob and Ad Manager)   
Adapter 4.3.39     
SDK Version - 22.2.0    

--------------- IronSource   
Adapter 7.4.0   

--------------- Vungle       
Adapter 4.3.21     
SDK Version - 6.12.1   

--------------- Tapjoy       
Adapter 4.1.25      
SDK Version - 13.0.1      

---------------
Current version for iOS  
---------------     
--------------- AppLovin     
     SDK - Version 12.4.0    
     Adapter - Version 4.3.40   

--------------- Chartboost    
     SDK - Version 9.7.0    
     Adapter - Version 4.3.15     

--------------- APS    
     SDK - Version 4.6.0     
     Adapter - Version 4.3.7    

--------------- Google (AdMob and Ad Manager)     
     SDK - Version 11.3.0     
     Adapter - Version 4.3.46     

--------------- IronSource     
     SDK - Version 8.1.0   
     Adapter - Version 8.1.0     

--------------- Meta     
     SDK - Version 6.12.0     
     Adapter - Version 4.3.39        

--------------- UnityAds     
     SDK - Version 4.12.2   
     Adapter - Version 4.3.31    

--------------- Liftoff (Vungle)
     SDK - Version 7.3.2  
     Adapter - Version 4.3.29 


