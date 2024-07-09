#include "ZFModuleDemo_libDef.h"
#include "protocol/ZFProtocolZFModuleDemo.h"
ZF_NAMESPACE_GLOBAL_BEGIN

zfstring demoFunc(void) {
    return "string from demo lib";
}

ZF_GLOBAL_INITIALIZER_INIT(ZFModuleDemo_lib_test) {
    zfLog() << "contents from ZFProtocolZFModuleDemo: " << ZFPROTOCOL_ACCESS(ZFModuleDemo)->demoImpl();
}
ZF_GLOBAL_INITIALIZER_END(ZFModuleDemo_lib_test)

ZF_NAMESPACE_GLOBAL_END

