file (GLOB CMD *.h *.cpp)

include_directories("${PROJECT_SOURCE_DIR}/src/app/interaction")
include_directories("${PROJECT_SOURCE_DIR}/src/domain")
include_directories("${PROJECT_SOURCE_DIR}/src/app/persist")
include_directories("${PROJECT_SOURCE_DIR}/src/app/interface")

add_library(cmd ${CMD})

target_link_libraries(cmd persist)
target_link_libraries(cmd interaction)
target_link_libraries(cmd domain)
target_link_libraries(cmd interface)