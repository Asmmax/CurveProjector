cmake_minimum_required (VERSION 3.8)

add_executable (ConsoleApp 
"src/main.cpp" 
"src/PolylineFile.cpp" 
"src/Context.cpp" 
"src/PointParser.cpp" 
"src/ProjectionParser.cpp")

target_compile_features (ConsoleApp PRIVATE cxx_std_14)
target_link_libraries(ConsoleApp PRIVATE Kernel)
target_include_directories(ConsoleApp PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")