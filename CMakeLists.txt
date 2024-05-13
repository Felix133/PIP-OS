cmake_minimum_required(VERSION 3.16)

project(PipOS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Core Quick)

qt_standard_project_setup()

qt_add_executable(appPipOS
    main.cpp
)

set_source_files_properties(Style.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

qt_add_qml_module(appPipOS
    URI PipOS
    VERSION 1.0
    QML_FILES
        Main.qml
        Style.qml
        NavButton.qml
        SubMenu.qml
        PageStat.qml
        PageInv.qml
        PageData.qml
        PageMap.qml
        PageRadio.qml
        ProgressBar.qml
        TabStatus.qml
        ItemStat.qml
    SOURCES
        dweller.h dweller.cpp
        QML_FILES BootSequence.qml
)

qt_add_resources(appPipOS "fonts"
    PREFIX "/"
    FILES
        fonts/RobotoCondensedFallout.ttf
        fonts/RobotoCondensedLightFallout.ttf
        fonts/RobotoCondensedBoldFallout.ttf
)

qt_add_resources(appPipOS "images"
    PREFIX "/"
    FILES
        images/body_0.png
        images/head_0.png
        images/head_1.png
        images/weapon.svg
        images/armor.svg
        images/defence.svg
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPipOS PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPipOS
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPipOS
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appPipOS
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
