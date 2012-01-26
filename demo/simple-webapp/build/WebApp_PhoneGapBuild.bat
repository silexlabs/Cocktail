ECHO OFF
ECHO.
SET input_files_path=../bin/index.html ../bin/default.css ../bin/images ../bin/WebApp.js
SET output_file_path=WebApp_PhoneGapBuild.zip

ECHO Compressing %output_file_path% ...
C:\"Program Files"\7-Zip\7z.exe a -tzip %output_file_path% %input_files_path%
ECHO.

ECHO Compression complete
ECHO.

PAUSE
