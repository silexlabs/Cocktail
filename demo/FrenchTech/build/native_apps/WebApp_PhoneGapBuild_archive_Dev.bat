ECHO OFF
ECHO.
SET target=Dev
SET config_file=config.xml
SET input_files_path=icons ./icons/icon_114.png splashScreens ./splashScreens/splashScreen-640x960.png config.xml index.html ../../bin/default.css ../../bin/assets ../../bin/WebApp.js
SET output_file_path=WebApp_PhoneGapBuild_%target%.zip

cls

ECHO preparing %config_file% file...
copy config_%target%.xml %config_file%
ECHO.

ECHO copying index file...
copy ..\..\bin\WebApp_js.html index.html
ECHO.

ECHO Removing %output_file_path%...
del %output_file_path% /Q /S

ECHO.

ECHO Compressing %output_file_path%...
C:\"Program Files"\7-Zip\7z.exe a -tzip %output_file_path% %input_files_path%
ECHO.

ECHO Removing %config_file% ...
del %config_file% /Q /S
del index.html /Q /S
ECHO.

ECHO Compression complete
ECHO.
