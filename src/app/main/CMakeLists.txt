file (GLOB MAIN *.h *.cpp)

include_directories("${PROJECT_SOURCE_DIR}/src/app/interface")

add_executable(main ${MAIN})

target_link_libraries(main interface)

