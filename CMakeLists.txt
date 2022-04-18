cmake_minimum_required(VERSION 3.17)
project(transazioniFinanziarie)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES transazione.cpp transazione.h conto.cpp conto.h)
add_executable(transazioniFinanziarie main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(transazioniFinanziarie core)