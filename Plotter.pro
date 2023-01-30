QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    baseoperation.cpp \
    commondesignes.cpp \
    discretefunction.cpp \
    equationhandler.cpp \
    inputfunctionform.cpp \
    main.cpp \
    mainform.cpp \
    mainwindow.cpp \
    parseequation.cpp \
    plotterform.cpp

HEADERS += \
    baseoperation.h \
    commondesignes.h \
    constants.h \
    discretefunction.h \
    equationhandler.h \
    inputfunctionform.h \
    mainform.h \
    mainwindow.h \
    parseequation.h \
    plotterform.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
