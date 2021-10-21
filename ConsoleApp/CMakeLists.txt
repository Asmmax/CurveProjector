cmake_minimum_required (VERSION 3.8)

set(console_include
"include/PolylineGateway.hpp" 
"include/PolylineFile.hpp" 
"include/Context.hpp" 
"include/Parser.hpp")

set(console_src
"src/main.cpp" 
"src/PolylineFile.cpp" 
"src/Context.cpp" 
"src/Parser.cpp")

add_executable (ConsoleApp ${console_include} ${console_src})

target_compile_features (ConsoleApp PRIVATE cxx_std_14)
target_link_libraries(ConsoleApp PRIVATE Kernel)
target_include_directories(ConsoleApp PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")