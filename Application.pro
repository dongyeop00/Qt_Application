QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator.cpp \
    main.cpp \
    notepad.cpp \
    paintboard.cpp \
    stopwatch.cpp \
    timer.cpp \
    widget.cpp

HEADERS += \
    calculator.h \
    notepad.h \
    paintboard.h \
    stopwatch.h \
    timer.h \
    widget.h

FORMS += \
    calculator.ui \
    notepad.ui \
    paintboard.ui \
    stopwatch.ui \
    timer.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
