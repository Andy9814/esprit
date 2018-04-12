@echo off
mkdir ..\..\build
pushd ..\..\build
cl /Zi "C:\Users\ANDYSingh\source\repos\Game Development\code\win_32.cpp" user32.lib Gdi32.lib
popd
