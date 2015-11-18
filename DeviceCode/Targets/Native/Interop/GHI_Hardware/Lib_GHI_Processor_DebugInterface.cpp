//-----------------------------------------------------------------------------
//
//                   ** WARNING! ** 
//    This file was generated automatically by a tool.
//    Re-running the tool will overwrite this file.
//    You should copy this file to a custom location
//    before adding any customization in the copy to
//    prevent loss of your changes when the tool is
//    re-run.
//
//-----------------------------------------------------------------------------


#include "Lib.h"
#include "Lib_GHI_Processor_DebugInterface.h"

using namespace GHI::Processor;

void DebugInterface::NativeLoad( INT32 * param0, INT32 * param1, HRESULT &hr )
{
    *param0 = 0;
    *param1 = 1;
}

INT8 DebugInterface::NativeSave( INT32 param0, INT32 param1, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}

