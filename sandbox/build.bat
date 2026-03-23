@echo off
setlocal enabledelayedexpansion

set filenames=
for /R %%f in (*.c) do (
    set filenames=!filenames! %%f
)

set binary=sandbox
set cflags=-g -Wvarargs -Wall -Werror
set iflags=-Isrc -I../engine/src -I../engine/external/glad/include -I../engine/external/stb/include
set lflags=../bin/engine.lib
set defines=-D_CRT_SECURE_NO_WARNINGS

echo "building %binary%..."
clang %filenames% %cflags% -o ../bin/%binary%.exe %iflags% %lflags% %defines%