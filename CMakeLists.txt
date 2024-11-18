cmake_minimum_required(VERSION 3.3)
project(BoostTest)

FIND_PACKAGE( Boost 1.60 COMPONENTS system REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES wiring.cpp dbgMetrics.cpp log.cpp demonisator.cpp config.cpp locker.cpp)
add_executable(wiring ${SOURCE_FILES})
target_link_libraries(wiring ${Boost_LIBRARIES} -lwiringPi -lncurses -lpthread)