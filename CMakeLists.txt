# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("CurveProjector")

if (WIN32)
  set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR} )
  set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR} )
  set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR} )
endif()

# Включите подпроекты.
add_subdirectory ("deps/catch2")
add_subdirectory ("Kernel")
add_subdirectory ("KernelTests")
add_subdirectory ("ConsoleApp")
