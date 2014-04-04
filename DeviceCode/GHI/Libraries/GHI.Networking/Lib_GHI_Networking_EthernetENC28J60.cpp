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
#include "Lib_GHI_Networking_EthernetENC28J60.h"

using namespace GHI::Networking;

void EthernetENC28J60::NativeSetHalConfig( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	if (Get_spi(pMngObj) != 0 || Get_chipSelect(pMngObj) != 45 || Get_externalInterrupt(pMngObj) != 40)
		hr = CLR_E_NOT_SUPPORTED;
}

INT8 EthernetENC28J60::NativeIsCableConnected( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
    hr = CLR_E_NOT_SUPPORTED;
	
	return 0;
}

