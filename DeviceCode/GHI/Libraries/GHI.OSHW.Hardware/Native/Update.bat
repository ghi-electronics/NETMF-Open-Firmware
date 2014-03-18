ECHO OFF
CLS
XCOPY "..\Managed\Stubs\*.h" "." /Y
XCOPY "..\Managed\Stubs\*.featureproj" "." /Y
XCOPY "..\Managed\Stubs\HAL.*" "." /Y
XCOPY "..\Managed\Stubs\*_mshl.cpp" "." /Y
XCOPY "..\Managed\Stubs\*.proj" "." /Y

PAUSE