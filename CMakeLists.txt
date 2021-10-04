cmake_minimum_required(VERSION 3.0.0)
project(banglejs-algos-tester LANGUAGES C VERSION 0.1.0)

include_directories(${PROJECT_SOURCE_DIR}/src/stepcounters)
include_directories(${PROJECT_SOURCE_DIR}/src/stepcounters/*)
set(SOURCES, "src/main.c")
file(GLOB SOURCES "src/*.c")
file(GLOB STEPCOUNTERSLIB "src/stepcounters/*.c")
file(GLOB STEPCOUNTERS "src/stepcounters/*/*.c")

add_executable(banglejs-algos-tester ${SOURCES} ${STEPCOUNTERSLIB} ${STEPCOUNTERS})
target_link_libraries(banglejs-algos-tester m)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
