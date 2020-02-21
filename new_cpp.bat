@echo off

cls
mkdir UVa%1

if ERRORLEVEL 1 (
	echo.
	set /p ch=Clear/Keep the origin file?[Y/N]:
	echo.
) else (
	goto create
)

::Created before
if /I %ch% == N (
	echo Commend canceled.
	goto end
)

:create
type template > UVa%1\UVa%1.cpp
echo.>UVa%1\UVa%1.in
echo.>UVa%1\UVa%1.out

echo UVa%1 Created

:end
set ch=
