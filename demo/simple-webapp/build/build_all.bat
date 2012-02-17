ECHO OFF
ECHO.
ECHO starting full build process...

WebApp_as3.hxml
WebApp_js.hxml
cd native_apps
CALL WebApp_PhoneGapBuild_archive.bat
CALL WebApp_air_desktop_and_tv.bat
CALL WebApp_air_android.bat
CALL WebApp_air_iOS_Dev.bat
cd ..

ECHO.
ECHO full build process complete
ECHO.

ECHO ON

PAUSE
