cmake_minimum_required(VERSION 3.26)
project(KPABE)


set(GMP_INCLUDE_DIR "/opt/homebrew/Cellar/gmp/6.3.0/include")
set(GMP_LIBRARY_DIR "/opt/homebrew/Cellar/gmp/6.3.0/lib") # Update this path if necessary
add_executable(KPABE main.cpp
        global_params.h
        global_params.cpp
        attribute.h
        utils/utils.cpp
        KeyGenerator.h
        KeyGenerator.cpp
)

include_directories(KPABE "${GMP_INCLUDE_DIR}")
include_directories(KPABE "/opt/homebrew/Cellar/pbc/0.5.14/include")

# Link libraries
target_link_libraries(KPABE "${GMP_LIBRARY_DIR}/libgmp.a") # Assuming libgmp.a exists at this location
target_link_libraries(KPABE pbc pbc)