# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("WeCycle")

# Include linked directories
link_directories("Firebase libs" ${WinSDK} "cryptopp_libs")
include_directories("firebase" ${WinSDK} "nlohmann" "cryptopp")

# Include sub-projects.
add_subdirectory ("WeCycle")


