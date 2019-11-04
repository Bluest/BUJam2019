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
	src/Input.h
	src/Input.cpp
	src/Sprite.h
	src/Sprite.cpp
	src/Audio.h
	src/Audio.cpp
	src/main.cpp
	src/GameObject.h
	src/GameObject.cpp
	src/Button.h
	src/Button.cpp
	src/Invader.h
	src/Invader.cpp
	src/Defender.h
	src/Defender.cpp
)

target_link_libraries(Jam SDL2 SDL2main SDL2_image SDL2_mixer)

add_custom_command(TARGET Jam
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/SDL2/SDL2.dll"
		$<TARGET_FILE_DIR:Jam>
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/SDL2/SDL2_image.dll"
		$<TARGET_FILE_DIR:Jam>
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/SDL2/SDL2_mixer.dll"
		$<TARGET_FILE_DIR:Jam>
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/SDL2/zlib1.dll"
		$<TARGET_FILE_DIR:Jam>
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/SDL2/libpng16-16.dll"
		$<TARGET_FILE_DIR:Jam>
)
