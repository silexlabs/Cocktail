ECHO OFF
ECHO.
SET input_dir=C:\Users\raph\Downloads
SET output_dir=..\..\bin\native_apps

ECHO moving PhoneGap app files from downlad directory to native_apps directory
ECHO.
ECHO moving iOS app
move %input_dir%\CocktailDemo.ipa %output_dir%\WebApp_iOS_PhoneGap.ipa
ECHO moving android app
move %input_dir%\CocktailDemo-debug.apk %output_dir%\WebApp_android_PhoneGap.apk
ECHO moving BlackBerry app
move %input_dir%\CocktailDemo.jad %output_dir%\WebApp_BlackBerry_PhoneGap.jad
ECHO moving webOS app
move %input_dir%\org.silexlabs.cocktailsimplewebapp_1.0.4_all.ipk %output_dir%\WebApp_webOS_PhoneGap.ipk
ECHO moving symbian app
move %input_dir%\app.wgz %output_dir%\WebApp_symbian_PhoneGap.wgz
ECHO.

ECHO PhoneGap apps moved with success
ECHO.
