# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/bookro_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/bookro_autogen.dir/ParseCache.txt"
  "bookro_autogen"
  )
endif()
