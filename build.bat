@echo off
cd engine && call ./build.bat && cd ../
cd sandbox && call ./build.bat && cd ../
cd bin && call sandbox.exe