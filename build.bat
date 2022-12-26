@echo off

:: .exe name
set name=cong.exe
:: out location
set OutFile=-o .\dst\%name%

:: Include and Lib Folders/Settings
set IncFolder=-I.\include -I.\include\SDL2\include
set LibFolder=-L.\include\SDL2\lib
set Libs=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

:: Source c files
set SrcFiles=.\src\main.c .\src\game.c .\src\window.c .\src\events.c .\src\render.c .\src\debug.c .\src\rand.c .\src\controls.c .\src\animation.c .\src\ui.c .\src\player.c .\src\enemy.c .\src\res\cong.res

:: Other helpful switches
set OtherSwitches=-Wall -std=c17

:: Actual GCC command
gcc %SrcFiles% %IncFolder% %LibFolder% %Libs% %OutFile% %OtherSwitches%