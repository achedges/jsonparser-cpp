cmake_minimum_required(VERSION 3.19)
project(jsonparser)

set(CMAKE_CXX_STANDARD 20)

add_library(jsonparser
        types/JsonTypes.h
        types/JsonArray.cpp
        types/JsonBoolean.cpp
        types/JsonFloat.cpp
        types/JsonInteger.cpp
        types/JsonNull.cpp
        types/JsonObject.cpp
        types/JsonString.cpp)

link_libraries(jsonparser)

add_executable(tests
        jsonparser
        tests/serializers.cpp)