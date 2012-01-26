ECHO OFF
ECHO.
SET input_files_path=icons splashScreens_PhoneGap config.xml index.html ../../bin/default.css ../../bin/images ../../bin/WebApp.js
SET output_file_path=WebApp_PhoneGapBuild.zip

ECHO copying splashScreens directory to splashScreens_PhoneGap...
xcopy splashScreens splashScreens_PhoneGap /Q /I
ECHO.

ECHO copying index file...
copy ..\..\bin\WebApp_js.html index.html
ECHO.

ECHO renaming files creating issues...
move splashScreens_PhoneGap\Default@2x.png splashScreens_PhoneGap\Default2x.png
ECHO.

ECHO Compressing %output_file_path%...
C:\"Program Files"\7-Zip\7z.exe a -tzip %output_file_path% %input_files_path%
ECHO.

ECHO Removing index.html and splashScreens_PhoneGap...
del index.html /Q /S
rd splashScreens_PhoneGap /Q /S
ECHO.

ECHO Compression complete
ECHO.

PAUSE
