ECHO OFF
CLS
ECHO Copying the firmware stubs.
ECHO *****************************************************************************
ECHO Make sure to HAND-EDIT the OSHW Native dotNetMF.proj files. There are changes 
ECHO to the native version that the generated stubs do not have that we must 
ECHO maintain. So add any new changes to the file yourself.
ECHO *****************************************************************************

FOR %%A IN (OSHW.Hardware OSHW.Native GameO.LowLevel) DO (
	XCOPY "GHI.%%A\Managed\Stubs\*.h" "GHI.%%A\Native\" /Y
	XCOPY "GHI.%%A\Managed\Stubs\*.featureproj" "GHI.%%A\Native\" /Y
	XCOPY "GHI.%%A\Managed\Stubs\HAL.*" "GHI.%%A\Native\" /Y
	XCOPY "GHI.%%A\Managed\Stubs\*_mshl.cpp" "GHI.%%A\Native\" /Y
	IF NOT "%%A"=="OSHW.Native" XCOPY "GHI.%%A\Managed\Stubs\*.proj" "GHI.%%A\Native\" /Y
)

PAUSE