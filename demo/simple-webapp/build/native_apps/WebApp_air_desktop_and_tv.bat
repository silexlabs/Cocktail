ECHO OFF
ECHO.
ECHO generating desktop and TV version via Air...
CALL adt -package -storetype pkcs12 -keystore sampleCert.pfx -storepass password -tsa http://timestamp.geotrust.com/ ../../bin/native_apps/WebApp_desktop.air WebApp_air.xml icons -C ../../bin WebApp.swf images
ECHO.
ECHO generation complete
ECHO.
