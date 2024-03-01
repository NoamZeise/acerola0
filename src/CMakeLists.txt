add_executable(acerola0
  main.cpp
)
target_link_libraries(acerola0 GraphicsEnv)

set(exec-name acerola0)
include("../graphics/cmake/copy-libs.cmake")
# Copy Resource Folder
add_custom_command(TARGET ${exec-name} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  "${CMAKE_CURRENT_LIST_DIR}/../resources"
  $<TARGET_FILE_DIR:${exec-name}>)
