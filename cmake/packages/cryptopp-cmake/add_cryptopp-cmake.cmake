include(${CMAKE_CURRENT_LIST_DIR}/../../get_cpm.cmake)

CPMAddPackage(
  NAME cryptopp-cmake
  GITHUB_REPOSITORY abdes/cryptopp-cmake
  GIT_TAG master
)
