@ECHO OFF
TITLE 设置IP
:menu 
echo.
echo ====================
echo 1. show interface id
echo.
echo 2. set arp table
echo.
echo 3. set ip
echo.
echo 4. quit
echo.
echo ====================
set /p user_input=input choice:
if %user_input% equ 1 goto showNum
if %user_input% equ 2 goto setarp
if %user_input% equ 3 goto setip
if %user_input% equ 4 goto end_pro

:showNum
netsh interface ipv4 show neighbors
goto menu

:setarp
netsh -c "i i" add neighbors 11 "192.168.0.2" "00-01-35-01-fe-c0"
goto menu

:setip
netsh interface ip set address "本地连接" static 192.168.0.4 255.255.255.0
goto menu

:end_pro
exit