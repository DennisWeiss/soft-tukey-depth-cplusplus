cmake_minimum_required(VERSION 3.22)
project(soft_tukey_depth_cplusplus)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH ./lib/libtorch)
set(CUDNN_INCLUDE_PATH "C:/Program Files/NVIDIA/CUDNN/v8.7/include")
set(CUDNN_LIBRARY_PATH "C:/Program Files/NVIDIA/CUDNN/v8.7")

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")


add_executable("${PROJECT_NAME}" main.cpp)
target_link_libraries("${PROJECT_NAME}" "${TORCH_LIBRARIES}")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

if (MSVC)
    file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
    add_custom_command(TARGET "${PROJECT_NAME}"
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${TORCH_DLLS}
            $<TARGET_FILE_DIR:soft_tukey_depth_cplusplus>)
endif (MSVC)