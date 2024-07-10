cmake_minimum_required(VERSION 3.26)
project(KPABE)
set(CMAKE_CXX_STANDARD 26)
set(GMP_INCLUDE_DIR "/opt/homebrew/Cellar/gmp/6.3.0/include")
set(GMP_LIBRARY_DIR "/opt/homebrew/Cellar/gmp/6.3.0/lib") # Update this path if necessary
set(PBC_INCLUDE_DIR "/opt/homebrew/Cellar/pbc/0.5.14/include")
set(PBC_LIBRARY_DIR "/opt/homebrew/Cellar/pbc/0.5.14/lib") # Update this path if necessary

add_executable(KPABE main.cpp
        global_params.h
        global_params.cpp
        attribute.h
        utils/utils.cpp
        KeyGenerator.h
        KeyGenerator.cpp
        utils/utils.h
        Encrypt.h
        Encrypt.cpp
        Decrypt.cpp
        Decrypt.h
        attribute.cpp
)

include_directories(KPABE "${GMP_INCLUDE_DIR}")
include_directories(KPABE "${PBC_INCLUDE_DIR}")

# Add linker flag globally
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-no_warn_duplicate_libraries")

# Link libraries
target_link_libraries(KPABE "${GMP_LIBRARY_DIR}/libgmp.a")
target_link_libraries(KPABE "${PBC_LIBRARY_DIR}/libpbc.a")

