cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
project(ZFModuleDemo_lib)
message("Build with type: ${CMAKE_BUILD_TYPE}, path: ${PROJECT_SOURCE_DIR}")

set(ZF_ROOT_PATH ${PROJECT_SOURCE_DIR}/../../../../../../ZFFramework)
include("${ZF_ROOT_PATH}/tools/spec/cmake/util.cmake")

file(GLOB_RECURSE srcfiles RELATIVE ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/../../../zfsrc/*.c
    ${PROJECT_SOURCE_DIR}/../../../zfsrc/*.cpp
    ${PROJECT_SOURCE_DIR}/../../../zfsrc_ext/*.c
    ${PROJECT_SOURCE_DIR}/../../../zfsrc_ext/*.cpp
    )
include("${PROJECT_SOURCE_DIR}/zfprojConfig.cmake" OPTIONAL)
if(COMMAND zfprojConfigBefore_ZFModuleDemo_lib)
    zfprojConfigBefore_ZFModuleDemo_lib(ZFModuleDemo_lib srcfiles)
endif()
add_library(ZFModuleDemo_lib SHARED ${srcfiles})
zfprojStripFILE(ZFModuleDemo_lib)
set_target_properties(ZFModuleDemo_lib PROPERTIES LINKER_LANGUAGE CXX)
target_compile_definitions(ZFModuleDemo_lib PUBLIC ZFLIB_ZFModuleDemo_lib=ZF_ENV_EXPORT)
if(COMMAND zfprojConfigAfter_ZFModuleDemo_lib)
    zfprojConfigAfter_ZFModuleDemo_lib(ZFModuleDemo_lib)
endif()

include_directories(${PROJECT_SOURCE_DIR}/../../../zfsrc)
include_directories(${ZF_ROOT_PATH}/_release/cmake/all/include)

function(ZFAddLib ZF_LIB_NAME_)
    add_library(${ZF_LIB_NAME_} SHARED IMPORTED)
    file(GLOB_RECURSE libPath ${ZF_ROOT_PATH}/_release/cmake/module/${ZF_LIB_NAME_}/lib/*${ZF_LIB_NAME_}*)
    set_target_properties(${ZF_LIB_NAME_} PROPERTIES IMPORTED_LOCATION ${libPath})
    target_link_libraries(ZFModuleDemo_lib PUBLIC ${ZF_LIB_NAME_})
endfunction(ZFAddLib)

ZFAddLib(ZFCore)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/../../../zfsrc/"
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/include"
    FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
    )
install(TARGETS ZFModuleDemo_lib EXPORT ZFModuleDemo_lib
    LIBRARY DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/lib"
    ARCHIVE DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/lib"
    RUNTIME DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/bin")
install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/../../../zfres/"
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/zfres"
    PATTERN "ZF_PUT_RES_FILES_HERE" EXCLUDE
    )

install(
    DIRECTORY "${ZF_ROOT_PATH}/_release/cmake/module/ZFModuleDemo_lib/"
    DESTINATION "${ZF_ROOT_PATH}/_release/cmake/all"
    )

