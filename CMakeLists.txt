cmake_minimum_required(VERSION 3.17)
project(transazioniFinanziarie)

set(CMAKE_CXX_STANDARD 14)

add_executable(transazioniFinanziarie main.cpp transazione.cpp transazione.h bonifico.cpp bonifico.h acquisto.cpp acquisto.h)