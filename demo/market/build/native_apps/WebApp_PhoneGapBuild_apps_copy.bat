ECHO OFF
ECHO.
SET input_dir=C:\Users\Raph\Downloads
SET output_dir=..\..\bin\native_apps
SET app_name=FrenchTech

ECHO moving PhoneGap app files from download directory to native_apps directory
ECHO.
ECHO moving iOS app
move %input_dir%\%app_name%.ipa %output_dir%\WebApp_iOS_PhoneGap.ipa
ECHO moving android app
move %input_dir%\%app_name%-debug.apk %output_dir%\WebApp_android_PhoneGap.apk
ECHO moving BlackBerry app
move %input_dir%\%app_name%.jad %output_dir%\WebApp_BlackBerry_PhoneGap.jad
ECHO moving webOS app
move %input_dir%\fr.intermedia-paris.francetech_1.0.0_all.ipk %output_dir%\WebApp_webOS_PhoneGap.ipk
ECHO moving symbian app
move %input_dir%\app.wgz %output_dir%\WebApp_symbian_PhoneGap.wgz
ECHO moving windows phone app
move %input_dir%\app.xap %output_dir%\WebApp_windowsPhone_PhoneGap.xap
ECHO.

ECHO PhoneGap apps moved with success
ECHO.
