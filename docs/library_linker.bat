@echo off
for /R %%f in (*.so.1.1) do mklink /j %%f .\lib
pause