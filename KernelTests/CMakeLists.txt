# CMakeList.txt: проект CMake для CurveProjector; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (KernelTests 
"Tests.cpp" 
"SegmentTests.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_compile_features (KernelTests PRIVATE cxx_std_14)
target_link_libraries(KernelTests PRIVATE catch2 PRIVATE Kernel)
