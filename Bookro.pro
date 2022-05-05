QT       += core gui waylandcompositor

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17  qevdevkeyboard

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/EvDevKeyboardListener.cpp \
    src/emulation/xkeys.cpp \
    src/main.cpp \
    src/Bookro.cpp

HEADERS += \
    src/Bookro.h \
    src/EvDevKeyboardListener.h \
    src/emulation/xkeys.h

FORMS += \
    src/Bookro.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
linux: LIBS += -lXtst -lX11 -levdev
