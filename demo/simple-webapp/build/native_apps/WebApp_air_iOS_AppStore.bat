ECHO OFF
ECHO.
ECHO generating iOS version via Air, which might take a few minutes...
CALL adt -package -target ipa-app-store -provisioning-profile Cocktail_Web_App_AppStore.mobileprovision -storetype pkcs12 -keystore iOS_Distrib.p12 ../../bin/native_apps/WebApp_iOS_Air_AppStore.ipa WebApp_air.xml icons -C splashScreens Default.png Default@2x.png Default-Landscape.png Default-Portrait.png -C ../../bin WebApp.swf images
ECHO.
ECHO generation complete
ECHO.

PAUSE