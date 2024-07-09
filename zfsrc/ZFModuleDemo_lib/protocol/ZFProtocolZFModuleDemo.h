/**
 * @file ZFProtocolZFModuleDemo.h
 * @brief protocol for ZFModuleDemo
 */

#ifndef _ZFI_ZFProtocolZFModuleDemo_h_
#define _ZFI_ZFProtocolZFModuleDemo_h_

#include "ZFCore/ZFProtocol.h"
#include "../ZFModuleDemo_libDef.h"
ZF_NAMESPACE_GLOBAL_BEGIN

// ============================================================
/**
 * @brief protocol for ZFModuleDemo
 */
ZFPROTOCOL_INTERFACE_BEGIN(ZFLIB_ZFModuleDemo_lib, ZFModuleDemo)
public:
    virtual zfstring demoImpl(void) zfpurevirtual;
ZFPROTOCOL_INTERFACE_END(ZFModuleDemo)

ZF_NAMESPACE_GLOBAL_END
#endif // #ifndef _ZFI_ZFProtocolZFModuleDemo_h_

