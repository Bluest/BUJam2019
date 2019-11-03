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

target_link_libraries(Jam SDL2 SDL2main SDL2_mixer)

add_custom_command(TARGET Jam
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/SDL2/SDL2.dll"
		$<TARGET_FILE_DIR:Jam>
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/SDL2/SDL2_mixer.dll"
		$<TARGET_FILE_DIR:Jam>
)
