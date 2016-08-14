#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T22:56:52
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = imatch
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    ncc.cpp \
    match.cpp

QMAKE_MAC_SDK = macosx10.11

HEADERS += \
    common.h \
    ncc.h \
    match.h

INCLUDEPATH +=/usr/local/include              \

LIBS += -L/usr/local/lib                        \
        -lopencv_features2d                     \
        -lopencv_calib3d                        \
        -lopencv_contrib                        \
        -lopencv_core                           \
        -lopencv_flann                          \
        -lopencv_gpu                            \
        -lopencv_ml                             \
        -lopencv_imgproc                        \
        -lopencv_video                          \
        -lopencv_legacy                         \
        -lopencv_highgui                        \
        -lopencv_stitching                      \
        -lopencv_photo                          \
        -lopencv_ocl                            \
        -lopencv_videostab                      \
        -lopencv_superres                       \
        -lopencv_nonfree                        \
