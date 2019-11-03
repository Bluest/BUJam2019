cmake_minimum_required(VERSION 2.6)

project(Jam)

include_directories(
	SDL2
)

link_directories(
	${CMAKE_SOURCE_DIR}/SDL2
)

add_executable(Jam
	src/Jam.h
	src/Jam.cpp
	src/main.cpp
)

target_link_libraries(Jam SDL2 SDL2main)
