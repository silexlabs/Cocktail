ECHO OFF
ECHO.
ECHO starting full build process...

REM WebApp_as3.hxml
WebApp_js.hxml
cd native_apps
CALL WebApp_PhoneGapBuild_archive_Dev.bat
REM CALL WebApp_air_desktop_and_tv.bat
REM CALL WebApp_air_android.bat
REM CALL WebApp_air_iOS.bat
cd ..

ECHO.
ECHO full build process complete
ECHO.

ECHO ON

PAUSE
