ECHO OFF
ECHO.
ECHO uninstalling application...
CALL adt -uninstallApp -platform ios -appid fr.intermedia-paris.WatTV
ECHO.
ECHO generating iOS version via Air, which might take a few minutes...
CALL adt -package -target ipa-test-interpreter -provisioning-profile test1.mobileprovision -storetype pkcs12 -keystore iphone_dev.p12 ../../bin/native_apps/iOS_Air.ipa Air_config.xml -C ../../bin Main.swf assets
ECHO compilation complete
ECHO.
ECHO installing application on the device (needs Air 3.4+)...
CALL adt -installApp -platform ios -package ../../bin/native_apps/iOS_Air.ipa
ECHO installation complete
ECHO.
