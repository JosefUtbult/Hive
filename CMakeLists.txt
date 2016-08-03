cmake_minimum_required(VERSION 3.5.2)  	#minimum version krav för att köras
project(hive)				#Vad projektet heter.

add_subdirectory(${PROJECT_SOURCE_DIR}/deps/SDL2-2.0.4)
include_directories(${PROJECT_SOURCE_DIR}/deps/SDL2-2.0.4/include)
include_directories(${PROJECT_BINARY_DIR}/deps/SDL2-2.0.4/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/deps/freetype-2.6.4)
include_directories(${PROJECT_SOURCE_DIR}/deps/freetype-2.6.4/include)
add_library(SDL2_ttf STATIC ${PROJECT_SOURCE_DIR}/deps/SDL2_ttf-2.0.14/SDL_ttf.c)
target_link_libraries(SDL2_ttf freetype)

include_directories(${PROJECT_SOURCE_DIR}/deps/SDL2_ttf-2.0.14)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Zlib

set(DEPS_SRC_DIR ${PROJECT_SOURCE_DIR}/deps)
set(DEPS_BIN_DIR ${PROJECT_BINARY_DIR}/deps)

set(ZLIB_VERSION zlib-1.2.8)
set(ZLIB_DIR ${DEPS_SRC_DIR}/${ZLIB_VERSION})
set(ZLIB_BIN_DIR ${DEPS_BIN_DIR}/${ZLIB_VERSION})

include_directories(${ZLIB_BIN_DIR})
include_directories(${ZLIB_DIR})
add_subdirectory(${ZLIB_DIR})
set(ZLIB_INCLUDE_DIR ${ZLIB_DIR})
set(ZLIB_LIBRARY zlibstatic)


# libpng

set(CMAKE_PREFIX_PATH ${ZLIB_BIN_DIR})
set(PNG_STATIC ON CACHE BOOL "Build static png library")
set(PNG_SHARED OFF CACHE BOOL "Don't build shared png library")
set(SKIP_INSTALL_ALL ON)

set(PNG_VERSION libpng-1.6.21)
set(PNG_BIN_DIR ${DEPS_BIN_DIR}/${PNG_VERSION})
set(PNG_SRC_DIR ${DEPS_SRC_DIR}/${PNG_VERSION})

include_directories(${PNG_BIN_DIR})
add_subdirectory(${PNG_SRC_DIR})
include_directories(${PNG_SRC_DIR})


# SDL_image

set(SDL_IMAGE_VERSION SDL2_image-2.0.1)
set(SDL_IMAGE_SRC_DIR ${DEPS_SRC_DIR}/${SDL_IMAGE_VERSION})
set(SDL_IMAGE_FORMATS
	png
	bmp
	gif
	lbm
	jpg
	pcx
	pnm
	tga
	tif
	webp
	xcf
	xpm
	xv
)
set(SDL_IMAGE_SOURCES ${SDL_IMAGE_SRC_DIR}/IMG.c)
foreach(f ${SDL_IMAGE_FORMATS})
	set(SDL_IMAGE_SOURCES ${SDL_IMAGE_SOURCES} ${SDL_IMAGE_SRC_DIR}/IMG_${f}.c src/CommandParser.cpp include/CommandParser.h src/Player.cpp include/Player.h)
endforeach()

add_definitions(-D LOAD_PNG)
include_directories(${SDL_IMAGE_SRC_DIR})
add_library(SDL_image STATIC ${SDL_IMAGE_SOURCES})
target_link_libraries(SDL_image png16_static)

add_executable(hive main.cpp
src/GameObject.cpp
src/Text.cpp
src/RunGame.cpp
src/Map.cpp
src/Tile.cpp
src/TileFactory.cpp
		src/InterFactory.cpp
src/Interactable.cpp)
#Resulterande namn samt filer det ska innthålla

target_link_libraries(hive SDL2-static SDL2_ttf SDL_image)

add_definitions(-std=c++11)