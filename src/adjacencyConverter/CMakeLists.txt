# The name of our project is "ADJACENCY_CONVERTER". CMakeLists files in this project can
# refer to the root source directory of the project as ${ADJACENCY_CONVERTER_SOURCE_DIR} and
# to the root binary directory of the project as ${ADJACENCY_CONVERTER_BINARY_DIR}.
project (ADJACENCY_CONVERTER) 

set(QT_DIR "" CACHE PATH "")

set(EXEC_NAME "AdjacencyConverter")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH ${QT_DIR})
# Find the QtWidgets library
find_package(Qt5Widgets)

SET(SOURCE
    "main.cpp"
    "ConverterWidget.cpp"
    "../utils/adjacency.cpp"
    )

SET(HEADER
    "ConverterWidget.h"
    "../utils/adjacency.h"
    )
    
qt5_wrap_ui(UI_HEADERS AdjacencyConverter.ui)

add_executable(${EXEC_NAME}
               ${SOURCE}
               ${HEADER}
               ${UI_HEADERS})

include_directories($(ADJACENCY_CONVERTER_SOURCE_DIR)/../utils)

# Use the Widgets module from Qt 5.
target_link_libraries(${EXEC_NAME} Qt5::Widgets)