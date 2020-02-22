@echo off

pushd UVa%1

cls
echo COMPILING...
g++ -std=c++11 UVa%1.cpp -o UVa%1.exe -DDBG

echo FINISH
if %ERRORLEVEL% EQU 0 (
	UVa%1.exe
)

popd
