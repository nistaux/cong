@echo off

:: .exe name
set name=cong.exe
:: out location
set OutFile=-o .\dst\%name%

:: Include and Lib Folders/Settings
set IncFolder=-I.\include -I.\include\SDL2\include
set LibFolder=-L.\include\SDL2\lib
set Libs=-lmingw32 -lSDL2main -lSDL2

:: Source c files
set SrcFiles=.\src\main.c .\src\game.c .\src\window.c .\src\events.c .\src\render.c .\src\pong.c .\src\debug.c .\src\rand.c .\src\puck.c .\src\controls.c

:: Other helpful switches
set OtherSwitches=-Wall -std=c17

:: Actual GCC command
gcc %SrcFiles% %IncFolder% %LibFolder% %Libs% %OutFile% %OtherSwitches%