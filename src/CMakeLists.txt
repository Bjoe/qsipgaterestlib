
#set(QT_MOC_HEADERS
#    parsereply.h
#)

#set(QT_UI
#    mainwindow.ui
#)

set(QT_SRCS
    parsereply.cpp
    uicontrol.cpp
    replyhandler.cpp
)

set(RECOURCES ../resources.qrc)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/config.h"
  )

#Link the helloworld executable to the Qt 5 widgets library.
#qt5_wrap_cpp(MOC_OUTFILES ${QT_MOC_HEADERS})

# Die ui_xxxx.h files werden im CMAKE_CURRENT_BINARY_DIR erzeugt.
#qt5_wrap_ui(UI_OUTFILES ${QT_UI})

add_library(qsrLib STATIC ${QT_SRCS}) # ${MOC_OUTFILES}) # ${UI_OUTFILES}
target_link_libraries(qsrLib Qt5::Network Qt5::Xml Qt5::Core)
#qt5_use_modules(qsrLib Core Network)

qt5_add_resources(QRC ${RECOURCES})
add_executable(qsr main.cpp ${QRC})
target_link_libraries(qsr qsrLib Qt5::Core Qt5::Widgets Qt5::Qml Qt5::Quick)

#qt5_use_modules(qsr Core)

#add_assembler_output(libfooLib.a)
#add_assembler_output(foo.exe)
