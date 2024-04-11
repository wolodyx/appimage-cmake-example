cmake_minimum_required(VERSION 3.15)

project(AppImage LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_library(model SHARED model.cpp)

add_executable(app main.cpp mainwindow.cpp resources/app.qrc)
target_link_libraries(app model Qt5::Core Qt5::Gui Qt5::Widgets)

install(TARGETS app model)

if(UNIX)
  add_custom_target(appimage
    COMMAND
         DESTDIR=AppDir cmake --install . --prefix=/usr
      && LD_LIBRARY_PATH=${CMAKE_BINARY_DIR}/AppDir/usr/lib linuxdeploy --appdir AppDir
      && cp ${CMAKE_SOURCE_DIR}/appimage/app.desktop ./AppDir/usr/share/applications/app.desktop
      && cp ${CMAKE_SOURCE_DIR}/appimage/app-icon-128x128.png ./AppDir/usr/share/icons/hicolor/128x128/apps/AppIcon.png
      && echo "ECHO = ${PWD}"
      && LD_LIBRARY_PATH=${CMAKE_BINARY_DIR}/AppDir/usr/lib linuxdeploy --appdir AppDir --output appimage
    WORKING_DIRECTORY
      ${CMAKE_BINARY_DIR}
  )
endif()

