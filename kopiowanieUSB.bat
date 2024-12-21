@echo off

REM Set environment variables if not already set
if not defined source set "source=C:\Programowanie"
if not defined destination set "destination=D:\Test"

REM Debug: Show the environment variables
echo source=%source%
echo destination=%destination%

REM Check if the source and destination folders exist
if not exist "%source%" (
    echo Source folder "%source%" does not exist!
    pause
    exit /b 1
)

if not exist "%destination%" (
    echo Destination folder "%destination%" does not exist!
    pause
    exit /b 1
)

REM Run the C++ program with the environment variables
echo Running kopiowanieUSB.exe with the environment variables...
start "" /B kopiowanieUSB.exe

REM Do not pause after execution if there are no errors
exit
