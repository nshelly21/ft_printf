cmake_minimum_required(VERSION 3.14)
project(libft.a)
file(GLOB_RECURSE FT_FILES "${PROJECT_SOURCE_DIR}/ft_*.c")
add_library(libft.a STATIC ${FT_FILES})