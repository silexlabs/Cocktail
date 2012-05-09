ECHO OFF
ECHO.
SET config_file=config.xml
SET input_files_path=icons splashScreens_PhoneGap config.xml index.html ../../bin/default.css ../../bin/images ../../bin/WebApp.js
SET output_file_path=WebApp_PhoneGapBuild_Dev.zip

cls

ECHO copying splashScreens directory to splashScreens_PhoneGap...
xcopy splashScreens splashScreens_PhoneGap /Q /I
ECHO.

ECHO preparing %config_file% file...
copy config_Dev.xml %config_file%
ECHO.

ECHO copying index file...
copy ..\..\bin\WebApp_js.html index.html
ECHO.

ECHO renaming files creating issues...
move splashScreens_PhoneGap\Default@2x.png splashScreens_PhoneGap\Default2x.png
ECHO.

ECHO Removing %output_file_path%...
del %output_file_path% /Q /S

ECHO.

ECHO Compressing %output_file_path%...
C:\"Program Files"\7-Zip\7z.exe a -tzip %output_file_path% %input_files_path%
ECHO.

ECHO Removing %config_file%, index.html and /splashScreens_PhoneGap...
del %config_file% /Q /S
del index.html /Q /S
rd splashScreens_PhoneGap /Q /S
ECHO.

ECHO Compression complete
ECHO.
