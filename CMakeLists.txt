project(CS321)

SET(CMAKE_CXX_FLAGS "-std=c++17 -lc++")

add_executable("app1" "app1.cpp")
add_executable("app2" "app2.cpp")
add_executable("app3" "app3.cpp")
add_executable("app4" "app4.cpp")

add_subdirectory("lab1")
add_subdirectory("lab2")
