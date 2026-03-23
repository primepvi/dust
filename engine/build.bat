@echo off
setlocal enabledelayedexpansion

set filenames=
for /R %%f in (*.c) do (
    set filenames=!filenames! %%f
) 

set binary=engine
set cflags=-g -shared -Wvarargs -Wall -Werror
set iflags=-Isrc -Iexternal/glad/include -Iexternal/stb/include
set lflags=-luser32 -lopengl32
set defines=-D_CRT_SECURE_NO_WARNINGS -DCB_EXPORT

echo "building %binary%%..."
clang %filenames% %cflags% -o ../bin/%binary%.dll %iflags% %lflags% %defines%