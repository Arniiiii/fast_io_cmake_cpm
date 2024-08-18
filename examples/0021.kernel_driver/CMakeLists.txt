if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  add_subdirectory(linux)
  message(STATUS "Example with kernel driver for Linux is going to be build.")
else()
  message(STATUS "Example with kernel driver for Linux is NOT going to be
  build, because you are not on Linux.")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows"
   OR CMAKE_SYSTEM_NAME STREQUAL "Cygwin"
   OR CMAKE_SYSTEM_NAME STREQUAL "Msys"
)
  add_subdirectory(nt)
  message(STATUS "Example with kernel driver for Windows is going to be build.")
else()
  message(STATUS "Example with kernel driver for Windows is NOT going to be
  build, because CMake thinks you are not on something Windows-like.")
endif()
