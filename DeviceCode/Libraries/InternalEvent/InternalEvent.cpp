#include "InternalEvent.h"

static HRESULT InitializeDriver( CLR_RT_HeapBlock_NativeEventDispatcher *pContext, UINT64 userData )
{
	GLOBAL_LOCK(irq);

	return S_OK;
}


static HRESULT EnableDisableDriver( CLR_RT_HeapBlock_NativeEventDispatcher *pContext, bool fEnable )
{
	GLOBAL_LOCK(irq);

	return S_OK;
}


static HRESULT CleanupDriver( CLR_RT_HeapBlock_NativeEventDispatcher *pContext )
{
	GLOBAL_LOCK(irq);

	return S_OK;
}

static const CLR_RT_DriverInterruptMethods g_Callback_DriverMethods = 
{
	InitializeDriver,
	EnableDisableDriver,
	CleanupDriver
};

const CLR_RT_NativeAssemblyData g_CLR_AssemblyNative_GHI_Utilities_InternalEvent =
{
    "GHI_Utilities_InternalEvent", 
    DRIVER_INTERRUPT_METHODS_CHECKSUM,
    &g_Callback_DriverMethods
};