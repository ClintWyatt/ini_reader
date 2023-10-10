cmake_minimum_required(VERSION 3.20)

project(IniReader)
set(CXX_STANDARD 20)


set(Headers
    include/ini_reader.h
)

set(Sources
    src/ini_reader.cpp
)

option(BUILD_TESTS "build tests" OFF)

if(${BUILD_TESTS})

    find_package(GTest REQUIRED)
    enable_testing()
    set(Tests
        test/main.cpp
    )
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
    add_executable(${PROJECT_NAME} ${Tests} ${Sources} ${Headers})

    target_link_libraries(${PROJECT_NAME}
        GTest::gtest
        GTest::gtest_main
    )

    
else()

    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
    add_library(${PROJECT_NAME} SHARED
        ${Sources}
    )


endif()
