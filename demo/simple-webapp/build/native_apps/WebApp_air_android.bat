ECHO OFF
ECHO.
ECHO generating android version via Air...
CALL adt -package -target apk -storetype pkcs12 -keystore sampleCert.pfx -storepass password ../../bin/native_apps/WebApp_android_Air.apk WebApp_air.xml icons -C ../../bin WebApp.swf images
ECHO.
ECHO generation complete
ECHO.
