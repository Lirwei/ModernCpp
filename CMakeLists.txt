cmake_minimum_required(VERSION 3.22)
project(CPP11)

set(CMAKE_CXX_STANDARD 14)

set(MODULES Cpp11 Cpp20)

foreach (module ${MODULES})
    add_subdirectory(${module})
endforeach ()