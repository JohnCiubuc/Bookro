QT       += core gui waylandcompositor

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    keepassx/src/autotype/wayland/UInput.cpp \
    src/BookroEvTest.cpp \
    src/BookroSystemTrayIcon.cpp \
    src/EvDevKeyboardListener.cpp \
    src/ScriptEngineLite.cpp \
    src/emulation/xkeys.cpp \
    src/main.cpp \
    src/Bookro.cpp


HEADERS += \
    keepassx/src/autotype/wayland/UInput.h \
    src/Bookro.h \
    src/BookroEvTest.h \
    src/BookroSystemTrayIcon.h \
    src/EvDevKeyboardListener.h \
    src/ScriptEngineLite.h \
    src/emulation/xkeys.h

FORMS += \
    src/Bookro.ui

INCLUDEPATH += keepassx/src/autotype/wayland/ evtest-qt/src/
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
linux: LIBS += -lXtst -lX11 -levdev

RESOURCES += \
    resource.qrc
