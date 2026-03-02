@echo off

set EXE=C:\Path\To\ssmi.exe

reg add "HKCU\Software\Classes\.ms" /ve /d "ssmi.msfile" /f

reg add "HKCU\Software\Classes\ssmi.msfile" /ve /d "SSMI File" /f

reg add "HKCU\Software\Classes\ssmi.msfile\DefaultIcon" /ve /d "\"%EXE%\",0" /f

reg add "HKCU\Software\Classes\ssmi.msfile\shell\open\command" /ve /d "\"%EXE%\" \"%%1\"" /f

echo.
echo Association installed.
pause
