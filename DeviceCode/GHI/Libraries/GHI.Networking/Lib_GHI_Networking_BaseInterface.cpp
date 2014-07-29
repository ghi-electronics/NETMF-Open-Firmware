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
#include "Lib_GHI_Networking_BaseInterface.h"

using namespace GHI::Networking;

// in NetwrokInterfaces.cpp
BOOL Network_Interface_Bind(int index);
int  Network_Interface_Open(int index);
BOOL Network_Interface_Close(int index);
void Network_Interface_Activate(int index);
void Network_Interface_Deactivate(int index);
void Network_Interface_UpdateMacAddressConfig(int index, UINT8* mac);
void Network_Interface_SetAsDefauiltInterfaces(int index);

//lwIP_Sockets_functions.cpp
void HAL_SOCK_LWIP_SOCKETS_Driver_SET_InterfaceNumber(UINT32 index, int interfaceNumber);

void BaseInterface::NativeOpen( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	int index = Get_type(pMngObj);
	int interfaceNumber;
	
    Network_Interface_Bind(index);
	
    interfaceNumber = Network_Interface_Open(index);

    if (interfaceNumber == SOCK_SOCKET_ERROR)
    {
		hr = -1;
		return;
    }
	
	HAL_SOCK_LWIP_SOCKETS_Driver_SET_InterfaceNumber(index, interfaceNumber);
	
	Network_Interface_SetAsDefauiltInterfaces(index);	
	Network_Interface_Activate(index);
}

void BaseInterface::NativeClose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	int index = Get_type(pMngObj);
	
	Network_Interface_Deactivate(index);
	Network_Interface_SetAsDefauiltInterfaces(-1);
	Network_Interface_Close(index);
}

void BaseInterface::NativeUpdateMacAddress( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
}
