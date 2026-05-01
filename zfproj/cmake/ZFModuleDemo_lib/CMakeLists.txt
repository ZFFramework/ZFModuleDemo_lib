cmake_minimum_required(VERSION 3.16)
project(ZFModuleDemo_lib)
set(ZF_ROOT_PATH "${PROJECT_SOURCE_DIR}/../../../../../../ZFFramework")
include("${ZF_ROOT_PATH}/tools/spec/cmake/util.cmake")
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")

include("${PROJECT_SOURCE_DIR}/zfprojConfig.cmake" OPTIONAL)

zfprojSrcFiles(
    ZF_SRC_FILES
    "${CMAKE_BINARY_DIR}/zfgensrc_ZFModuleDemo_lib.cpp"
    "${ZF_ROOT_PATH}"
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/../../.."
    )
if(COMMAND zfprojConfigBefore_ZFModuleDemo_lib)
    zfprojConfigBefore_ZFModuleDemo_lib(ZFModuleDemo_lib ZF_SRC_FILES)
endif()
add_library(ZFModuleDemo_lib SHARED ${ZF_SRC_FILES})
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
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/include"
    FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
    )
install(
    TARGETS ZFModuleDemo_lib
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/lib"
    )
install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/../../../zfres/"
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/zfres"
    PATTERN "ZF_PUT_RES_FILES_HERE" EXCLUDE
    )

install(
    DIRECTORY "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/"
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/all"
    )

