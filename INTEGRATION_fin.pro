QT       += core gui sql
QT       += charts
QT       += axcontainer
QT       +=network
QT       += printsupport
QT       += core gui  serialport
QT       += multimedia
QT       += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = equipementintr
TEMPLATE = app

CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=  \
    Chercheur1.cpp \
    Conference1.cpp \
    Equipement1.cpp \
    arduino.cpp \
    article.cpp \
    article1.cpp \
    chercheur.cpp \
    conference.cpp \
    connection.cpp\
    dialog.cpp \
    equipements.cpp \
    image.cpp \
    main.cpp \
    menu.cpp \
    qrcodegen.cpp \
    smtp.cpp

HEADERS +=  \
    Chercheur1.h \
    Conference1.h \
    Equipement1.h \
    arduino.h \
    article.h \
    article1.h \
    chercheur.h \
    conference.h \
    connection.h\
    dialog.h \
    equipements.h \
    image.h \
    menu.h \
    qrcodegen.hpp \
    smtp.h

FORMS += \
    Chercheur1.ui \
    Conference1.ui \
    Equipement1.ui \
    article1.ui \
    dialog.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#LIBS += "C:\Users\Oumayma\OneDrive\Bureau\build-equipementintr-Desktop_Qt_5_9_9_MinGW_32bit-Debug\debug\libeay32.dll"
#LIBS+= "C:\Users\Oumayma\OneDrive\Bureau\build-equipementintr-Desktop_Qt_5_9_9_MinGW_32bit-Debug\debug\libssl32.dll"
#LIBS += "C:\Users\Oumayma\OneDrive\Bureau\build-equipementintr-Desktop_Qt_5_9_9_MinGW_32bit-Debug\debug\ssleay32.dll"*/


DISTFILES += \
    led.ino
