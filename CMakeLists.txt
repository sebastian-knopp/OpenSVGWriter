

cmake_minimum_required(VERSION 2.8)


project (OpenSVGWriter CXX)


file(GLOB SOURCES *.h
                                 *.hpp
                                 *.cpp)


set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11" )

add_executable(OpenSVGWriter ${SOURCES} )



