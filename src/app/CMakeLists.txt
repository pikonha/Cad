project(app CXX)

file (GLOB APP *.h *.cpp)

add_executable(app ${APP})

target_include_directories(app PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(app PROPERTIES ENABLE_EXPORTS 1)

target_link_libraries(app cmd)
target_link_libraries(app persist)
target_link_libraries(app domain)
target_link_libraries(app interface)
target_link_libraries(app Qt5::Widgets)
target_link_libraries(app Qt5::Core)
