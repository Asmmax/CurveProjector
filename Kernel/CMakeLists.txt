# CMakeList.txt: проект CMake для CurveProjector; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Добавьте источник в исполняемый файл этого проекта.
add_library (Kernel  SHARED 
"CurveProjector.cpp" 
"CurveProjector.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_compile_features (Kernel PRIVATE cxx_std_14)
