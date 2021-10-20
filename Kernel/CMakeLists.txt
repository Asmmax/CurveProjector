# CMakeList.txt: проект CMake для CurveProjector; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Добавьте источник в исполняемый файл этого проекта.
add_library (Kernel  SHARED 
"src/ApproxDouble.cpp" 
"src/Point.cpp"
"src/Segment.cpp"
"src/Vector.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_compile_features (Kernel PRIVATE cxx_std_14)
target_include_directories(Kernel PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
