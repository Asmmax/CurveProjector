# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("CurveProjector")

# Включите подпроекты.
add_subdirectory ("deps/catch2")
add_subdirectory ("Kernel")
add_subdirectory ("KernelTests")
