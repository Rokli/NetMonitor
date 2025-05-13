QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += /usr/include/mysql
LIBS += -L/usr/lib64/mysql -lmysqlclient
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Models/agent.cpp \
    Models/server.cpp \
    dialogclient.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Models/agent.h \
    Models/server.h \
    dialogclient.h \
    mainwindow.h

FORMS += \
    dialogclient.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
