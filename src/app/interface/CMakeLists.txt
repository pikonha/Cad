file(GLOB INTERFACE *.h *.cpp)

include_directories("${PROJECT_SOURCE_DIR}/src/app/command")
include_directories("${PROJECT_SOURCE_DIR}/src/domain")
include_directories("${PROJECT_SOURCE_DIR}/src/app/persist")

add_library(interface ${INTERFACE})

find_package(Qt5Widgets CONFIG
        PATHS C:/Qt/5.9.2/msvc2017_64/lib/cmake/Qt5Widgets
        NO_DEFAULT_PATH)

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core Qt5::Gui)

target_link_libraries(interface cmd)
target_link_libraries(interface domain)
target_link_libraries(interface persist)
target_link_libraries(interface Qt5::Widgets)
target_link_libraries(interface Qt5::Gui)