cmake_minimum_required(VERSION 3.16)
project(ZFModuleDemo_lib)
set(ZF_ROOT_PATH "${PROJECT_SOURCE_DIR}/../../../../../../ZFFramework")
include("${ZF_ROOT_PATH}/tools/spec/cmake/util.cmake")

include("${PROJECT_SOURCE_DIR}/zfprojConfig.cmake" OPTIONAL)

zfprojSrcFiles(
    ZF_SRC_FILES
    "${CMAKE_BINARY_DIR}/zfgensrc/zfgensrc_ZFModuleDemo_lib.cpp"
    "${ZF_ROOT_PATH}"
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/../../.."
    )
if(COMMAND zfprojConfigBefore_ZFModuleDemo_lib)
    zfprojConfigBefore_ZFModuleDemo_lib(ZFModuleDemo_lib ZF_SRC_FILES)
endif()
add_library(ZFModuleDemo_lib SHARED ${ZF_SRC_FILES})
target_compile_options(ZFModuleDemo_lib PRIVATE "$<$<CONFIG:DEBUG>:-DDEBUG>")
zfprojStripFILE(ZFModuleDemo_lib)
set_target_properties(ZFModuleDemo_lib PROPERTIES LINKER_LANGUAGE CXX)
target_compile_definitions(ZFModuleDemo_lib PUBLIC ZFLIB_ZFModuleDemo_lib=ZF_ENV_EXPORT)
if(COMMAND zfprojConfigAfter_ZFModuleDemo_lib)
    zfprojConfigAfter_ZFModuleDemo_lib(ZFModuleDemo_lib)
endif()

target_include_directories(ZFModuleDemo_lib PRIVATE "${PROJECT_SOURCE_DIR}/../../../zfsrc")

function(ZFAddLib ZF_LIB_NAME_)
    target_include_directories(ZFModuleDemo_lib PRIVATE "${ZF_ROOT_PATH}/_release/cmake/all/include")
    target_link_directories(ZFModuleDemo_lib PUBLIC "${ZF_ROOT_PATH}/_release/cmake/module/${ZF_LIB_NAME_}/lib")
    target_link_libraries(ZFModuleDemo_lib PRIVATE ${ZF_LIB_NAME_})
endfunction()

ZFAddLib(ZFCore)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/../../../zfsrc/"
    DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
    FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
    )
install(
    TARGETS ZFModuleDemo_lib
    DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
    )
zfprojExec("${ZF_ROOT_PATH}/tools/util/copy_res" "${PROJECT_SOURCE_DIR}/../../../zfres/" "${CMAKE_INSTALL_PREFIX}/zfres")

