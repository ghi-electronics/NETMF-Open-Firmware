ECHO OFF
CLS
ECHO *************************************************************************************
ECHO Make sure to HAND-EDIT the dotNetMF.proj files. There are changes to the native version 
ECHO that the generated stubs do not have that we must maintain. So add any new changes to 
ECHO the file yourself.
ECHO *************************************************************************************

XCOPY "..\Managed\Stubs\*.h" "." /Y
XCOPY "..\Managed\Stubs\*.featureproj" "." /Y
XCOPY "..\Managed\Stubs\HAL.*" "." /Y
XCOPY "..\Managed\Stubs\*_mshl.cpp" "." /Y

PAUSE