file (GLOB INTERACTION *.h *.cpp)

add_library(interaction ${INTERACTION})

find_package(Qt5Widgets CONFIG
        PATHS C:/Qt/5.9.2/msvc2017_64/lib/cmake/Qt5Widgets
        NO_DEFAULT_PATH)

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core)

target_link_libraries(interaction Qt5::Core)
target_link_libraries(interaction Qt5::Widgets)