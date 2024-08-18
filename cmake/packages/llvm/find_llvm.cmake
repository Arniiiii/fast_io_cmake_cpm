# cmake-format: off
# if(NOT ${${PROJECT_NAME}_WAS_LOOKING_FOR_LLVM})
#   set(${PROJECT_NAME}_WAS_LOOKING_FOR_LLVM
#        TRUE
#   )
  find_package(LLVM CONFIG)
  message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
  message(STATUS "LLVM_FOUND: ${LLVM_FOUND}")
  message(STATUS "LLVM_VERSION: ${LLVM_VERSION}")
# endif()
# cmake-format: on
