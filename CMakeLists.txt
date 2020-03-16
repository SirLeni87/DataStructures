cmake_minimum_required (VERSION 2.6)

project (ProjektSDiZO)

add_link_options(-static)

include_directories("src/")
file(GLOB SOURCES "src/*.cpp")

add_executable(ProjektSDiZO ${SOURCES})
