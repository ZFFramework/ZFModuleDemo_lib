cmake_minimum_required(VERSION 3.4.1)
project(ZFModuleDemo_lib)

set(ZF_ROOT_PATH "${PROJECT_SOURCE_DIR}/../../../../../../../ZFFramework")
include("${ZF_ROOT_PATH}/tools/spec/cmake/util.cmake")

file(GLOB_RECURSE ZF_SRC_FILES RELATIVE "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/../../../../zfsrc/*.c"
    "${PROJECT_SOURCE_DIR}/../../../../zfsrc/*.cpp"
    "${PROJECT_SOURCE_DIR}/../../../../zfsrc_ext/*.c"
    "${PROJECT_SOURCE_DIR}/../../../../zfsrc_ext/*.cpp"
    )
add_library(ZFModuleDemo_lib SHARED ${ZF_SRC_FILES})
zfprojStripFILE(ZFModuleDemo_lib)
set_target_properties(ZFModuleDemo_lib PROPERTIES LINKER_LANGUAGE CXX)

find_library(log-lib log)
find_library(android-lib android)
target_link_libraries(ZFModuleDemo_lib ${android-lib} ${log-lib})

target_include_directories(ZFModuleDemo_lib PRIVATE "${PROJECT_SOURCE_DIR}/../../../../zfsrc")

function(ZFAddLib ZF_LIB_NAME_)
    target_include_directories(ZFModuleDemo_lib PRIVATE "${ZF_ROOT_PATH}/_release/Android/all/src/main/cpp/include")
    add_library(${ZF_LIB_NAME_} SHARED IMPORTED)
    set_target_properties(${ZF_LIB_NAME_} PROPERTIES IMPORTED_LOCATION "${ZF_ROOT_PATH}/_release/Android/all/src/main/jniLibs/${ANDROID_ABI}/lib${ZF_LIB_NAME_}.so")
    target_link_libraries(ZFModuleDemo_lib ${ZF_LIB_NAME_})
endfunction()


ZFAddLib(ZFCore)

