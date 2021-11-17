QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstractFactory/abstractfactory.cpp \
    configuration/loadsolution.cpp \
    configuration/registrator.cpp \
    configuration/solution.cpp \
    facade/basecommand.cpp \
    facade/facade.cpp \
    load/builder.cpp \
    load/camerabuilder.cpp \
    load/camerafileloader.cpp \
    load/figurebuilder.cpp \
    load/figurefileloader.cpp \
    load/loadcreator.cpp \
    load/loader.cpp \
    load/scenebuilder.cpp \
    load/scenefileloader.cpp \
    managers/basemanager.cpp \
    managers/configmanager.cpp \
    managers/drawmanager.cpp \
    managers/loadmanager.cpp \
    managers/scenemanager.cpp \
    objects/camera.cpp \
    objects/composite.cpp \
    AbstractFactory/drawer.cpp \
    objects/data.cpp \
    objects/edge.cpp \
    objects/figure.cpp \
    main/main.cpp \
    main/mainwindow.cpp \
    Mathobj/mathobjs.cpp \
    Mathobj/pixel.cpp \
    objects/object.cpp \
    objects/point.cpp \
    scene/scene.cpp \
    visitor/basevisitor.cpp \
    visitor/visitor.cpp \
    load/loaddirector.cpp

HEADERS += \
    AbstractFactory/abstractfactory.h \
    configuration/loadsolution.h \
    configuration/registrator.h \
    configuration/solution.h \
    facade/basecommand.h \
    load/builder.h \
    load/camerabuilder.h \
    load/camerafileloader.h \
    load/figurebuilder.h \
    load/figurefileloader.h \
    load/loadcreator.h \
    load/loader.h \
    load/scenebuilder.h \
    load/scenefileloader.h \
    managers/basemanager.h \
    managers/configmanager.h \
    managers/drawmanager.h \
    managers/loadmanager.h \
    managers/scenemanager.h \
    objects/camera.h \
    objects/composite.h \
    AbstractFactory/drawer.h \
    objects/data.h \
    objects/edge.h \
    exceptions/exceptions.h \
    objects/figure.h \
    main/mainwindow.h \
    Mathobj/mathobjs.h \
    objects/object.h \
    Mathobj/pixel.h \
    objects/point.h \
    scene/scene.h \
    facade/facade.h \
    visitor/basevisitor.h \
    visitor/visitor.h \
    load/loaddirector.h

FORMS += \
    main/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/config.txt \
    data/scene.txt
