# Set CMake Version Required
cmake_minimum_required(VERSION 2.8)

# Set Project Name
project(ImageViewer)

# Set Compiler Flags
set(CMAKE_CXX_FLAGS "-std=c++11")

# Turn On Automoc
set(CMAKE_AUTOMOC ON)

# Set Libraries Path
set(Qt5Core_DIR "${CMAKE_CURRENT_LIST_DIR}/Libraries/Qt/lib/cmake/Qt5Core")
set(Qt5Gui_DIR "${CMAKE_CURRENT_LIST_DIR}/Libraries/Qt/lib/cmake/Qt5Gui")
set(Qt5Widgets_DIR "${CMAKE_CURRENT_LIST_DIR}/Libraries/Qt/lib/cmake/Qt5Widgets")

# Find Packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Include Directories
include_directories("SourceFiles")

# Get Source Files
file(GLOB_RECURSE SOURCE_FILES SourceFiles/*.cpp)

# Add Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} SourceFiles/WindowTab.cpp SourceFiles/WindowTab.h)

# Link Libraries
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

# Run
add_custom_target(run
        ${CMAKE_COMMAND} -E env QT_PLUGIN_PATH=${CMAKE_CURRENT_LIST_DIR}/Libraries/Qt/plugins
        ${CMAKE_CURRENT_LIST_DIR}/Build/${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

# Install
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "/opt/${PROJECT_NAME}")
install(FILES "Extras/icon.svg" DESTINATION "/opt/${PROJECT_NAME}")
install(FILES "Extras/${PROJECT_NAME}.desktop" DESTINATION /usr/share/applications)
install(DIRECTORY "Images" DESTINATION "/opt/${PROJECT_NAME}")
install(DIRECTORY "Libraries" DESTINATION "/opt/${PROJECT_NAME}")
install(PROGRAMS "Extras/Run${PROJECT_NAME}.sh" DESTINATION "/opt/${PROJECT_NAME}")
