ECHO OFF
ECHO.
ECHO uninstalling application...
CALL adt -uninstallApp -platform android -appid fr.intermedia-paris.test1
ECHO.
ECHO generating android version via Air...
CALL adt -package -target apk -storetype pkcs12 -keystore sampleCert.pfx -storepass password ../../bin/native_apps/Android_Air.apk Air_config.xml -C ../../bin Main.swf assets
ECHO compilation complete
ECHO.
ECHO installing application on the device (needs Air 3.4+)...
CALL adt -installApp -platform android -package ../../bin/native_apps/Android_Air.apk
ECHO installation complete
ECHO.
