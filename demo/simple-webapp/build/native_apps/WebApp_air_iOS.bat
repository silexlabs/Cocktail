ECHO OFF
ECHO.
ECHO generating iOS version via Air, which might take a few minutes...
CALL adt -package -target ipa-ad-hoc -provisioning-profile Cocktail_Web_App.mobileprovision -storetype pkcs12 -keystore iphone_dev.p12 ../../bin/native_apps/WebApp_iOS_Air.ipa WebApp_air.xml icons -C splashScreens Default.png Default@2x.png Default-Landscape.png Default-Portrait.png -C ../../bin WebApp.swf images
ECHO.
ECHO generation complete
ECHO.
