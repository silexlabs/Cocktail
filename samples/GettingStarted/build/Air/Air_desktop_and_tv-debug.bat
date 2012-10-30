ECHO OFF
ECHO.
ECHO generating desktop and TV version via Air...
CALL copy Air_config.xml ..\..\bin\Air_config.xml /Y
CALL cd ../../bin
CALL adl Air_config.xml
CALL del Air_config.xml /Q
CALL cd ../build/Air
ECHO.
ECHO generation complete
ECHO.
