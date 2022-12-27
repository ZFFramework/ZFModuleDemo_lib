/**
 * @file ZFModuleDemo_libDef.h
 * @brief global header for ZFModuleDemo_lib module
 */

#ifndef _ZFI_ZFModuleDemo_libDef_h_
#define _ZFI_ZFModuleDemo_libDef_h_

#include "ZFCore.h"
ZF_NAMESPACE_GLOBAL_BEGIN

/** @brief used to export symbols */
#ifndef ZFLIB_ZFModuleDemo_lib
    #define ZFLIB_ZFModuleDemo_lib ZF_ENV_IMPORT
#endif

extern ZFLIB_ZFModuleDemo_lib zfstring demoFunc(void);

ZF_NAMESPACE_GLOBAL_END
#endif // #ifndef _ZFI_ZFModuleDemo_libDef_h_

