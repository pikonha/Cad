file (GLOB MAIN *.h *.cpp)

include_directories("${PROJECT_SOURCE_DIR}/src/app/interface")

add_executable(main ${MAIN})


find_package(Qt5Widgets CONFIG
        PATHS C:/Qt/5.9.2/msvc2017_64/lib/cmake/Qt5Widgets
        NO_DEFAULT_PATH)

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core)

target_link_libraries(main Qt5::Core)
target_link_libraries(main interface)
target_link_libraries(main Qt5::Widgets)
