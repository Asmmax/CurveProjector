# CMakeList.txt: проект CMake для CurveProjector; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set (kernel_include 
"include/ApproxDouble.hpp" 
"include/Point.hpp"
"include/Segment.hpp"
"include/Vector.hpp" 
"include/Polyline.hpp"
"include/Projector.hpp")

set (kernel_src 
"src/ApproxDouble.cpp" 
"src/Point.cpp"
"src/Segment.cpp"
"src/Vector.cpp" 
"src/Polyline.cpp"
"src/Projector.cpp")

# Добавьте источник в исполняемый файл этого проекта.
add_library (Kernel  SHARED ${kernel_include} ${kernel_src})

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_compile_features (Kernel PRIVATE cxx_std_14)
target_include_directories(Kernel PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

include(GNUInstallDirs)

install(TARGETS Kernel LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${kernel_include} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
