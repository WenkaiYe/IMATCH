#############################################################################
# Makefile for building: imatch
# Generated by qmake (3.0) (Qt 5.4.0)
# Project:  IMATCH.pro
# Template: app
# Command: /Users/Kevin/Qt5.4.0/5.4/clang_64/bin/qmake -spec macx-clang CONFIG+=debug CONFIG+=x86_64 -o Makefile IMATCH.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang
CXX           = /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++
DEFINES       = -DQT_CORE_LIB
CFLAGS        = -pipe -g -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk -mmacosx-version-min=10.10 -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -pipe -g -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk -mmacosx-version-min=10.10 -Wall -W -fPIE $(DEFINES)
INCPATH       = -I../../Qt5.4.0/5.4/clang_64/mkspecs/macx-clang -I. -I/usr/local/include -I../../Qt5.4.0/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers -I. -F/Users/Kevin/Qt5.4.0/5.4/clang_64/lib
QMAKE         = /Users/Kevin/Qt5.4.0/5.4/clang_64/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = imatch1.0.0
DISTDIR = /Users/Kevin/Desktop/IMATCH/.tmp/imatch1.0.0
LINK          = /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++
LFLAGS        = -headerpad_max_install_names -Wl,-syslibroot,/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk -mmacosx-version-min=10.10 -Wl,-rpath,/Users/Kevin/Qt5.4.0/5.4/clang_64/lib
LIBS          = $(SUBLIBS) -F/Users/Kevin/Qt5.4.0/5.4/clang_64/lib -L/usr/local/lib -lopencv_features2d -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_flann -lopencv_gpu -lopencv_ml -lopencv_imgproc -lopencv_video -lopencv_legacy -lopencv_highgui -lopencv_stitching -lopencv_photo -lopencv_ocl -lopencv_videostab -lopencv_superres -lopencv_nonfree -framework QtCore -framework DiskArbitration -framework IOKit 
AR            = /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ar cq
RANLIB        = /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib -s
SED           = sed
STRIP         = 

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		ncc.cpp \
		match.cpp \
		feature.cpp \
		utils.cpp \
		delaunay.cpp 
OBJECTS       = main.o \
		ncc.o \
		match.o \
		feature.o \
		utils.o \
		delaunay.o
DIST          = ../../Qt5.4.0/5.4/clang_64/mkspecs/features/spec_pre.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/qdevice.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/device_config.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/shell-unix.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/unix.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/mac.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/macx.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/gcc-base.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/gcc-base-mac.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/clang.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/clang-mac.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/qconfig.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_core.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_core_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_dbus.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_declarative.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_designer.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_enginio.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_gui.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_help.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_help_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_location.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_location_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_macextras.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_macextras_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_network.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_network_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_nfc.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_opengl.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_positioning.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qml.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quick.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_script.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_script_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sensors.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_serialport.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sql.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_svg.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_testlib.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_uitools.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webengine.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webengine_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginecore.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkit.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_websockets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webview.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webview_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_widgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xml.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/qt_functions.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/qt_config.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/macx-clang/qmake.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/exclusive_builds.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/default_pre.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/default_pre.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/resolve_config.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/default_post.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/sdk.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/default_post.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/objective_c.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/warn_on.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/qt.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/resources.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/moc.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/unix/thread.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/rez.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/testcase_targets.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/exceptions.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/yacc.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/lex.prf \
		IMATCH.pro ncc.h \
		match.h \
		feature.h \
		utils.h \
		delaunay.h main.cpp \
		ncc.cpp \
		match.cpp \
		feature.cpp \
		utils.cpp \
		delaunay.cpp
QMAKE_TARGET  = imatch
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = imatch

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-isysroot \
		/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk \
		-mmacosx-version-min=10.10 \
		-Wall \
		-W



first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: IMATCH.pro ../../Qt5.4.0/5.4/clang_64/mkspecs/macx-clang/qmake.conf ../../Qt5.4.0/5.4/clang_64/mkspecs/features/spec_pre.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/qdevice.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/device_config.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/shell-unix.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/unix.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/mac.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/macx.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/gcc-base.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/gcc-base-mac.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/clang.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/common/clang-mac.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/qconfig.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_core.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_core_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_dbus.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_declarative.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_designer.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_enginio.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_gui.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_help.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_help_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_location.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_location_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_macextras.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_macextras_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_network.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_network_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_nfc.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_opengl.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_positioning.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qml.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quick.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_script.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_script_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sensors.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_serialport.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sql.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_svg.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_testlib.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_uitools.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webengine.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webengine_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginecore.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkit.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_websockets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webview.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webview_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_widgets.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xml.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/qt_functions.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/qt_config.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/macx-clang/qmake.conf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/exclusive_builds.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/default_pre.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/default_pre.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/resolve_config.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/default_post.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/sdk.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/default_post.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/objective_c.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/warn_on.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/qt.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/resources.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/moc.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/unix/thread.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/rez.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/testcase_targets.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/exceptions.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/yacc.prf \
		../../Qt5.4.0/5.4/clang_64/mkspecs/features/lex.prf \
		IMATCH.pro \
		/Users/Kevin/Qt5.4.0/5.4/clang_64/lib/QtCore.framework/QtCore.prl
	$(QMAKE) -spec macx-clang CONFIG+=debug CONFIG+=x86_64 -o Makefile IMATCH.pro
../../Qt5.4.0/5.4/clang_64/mkspecs/features/spec_pre.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/qdevice.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/device_config.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/common/shell-unix.conf:
../../Qt5.4.0/5.4/clang_64/mkspecs/common/unix.conf:
../../Qt5.4.0/5.4/clang_64/mkspecs/common/mac.conf:
../../Qt5.4.0/5.4/clang_64/mkspecs/common/macx.conf:
../../Qt5.4.0/5.4/clang_64/mkspecs/common/gcc-base.conf:
../../Qt5.4.0/5.4/clang_64/mkspecs/common/gcc-base-mac.conf:
../../Qt5.4.0/5.4/clang_64/mkspecs/common/clang.conf:
../../Qt5.4.0/5.4/clang_64/mkspecs/common/clang-mac.conf:
../../Qt5.4.0/5.4/clang_64/mkspecs/qconfig.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_bluetooth.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_clucene_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_concurrent.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_core.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_core_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_dbus.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_declarative.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_declarative_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_designer.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_designer_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_enginio.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_enginio_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_gui.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_gui_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_help.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_help_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_location.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_location_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_macextras.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_macextras_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimedia.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimedia_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_network.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_network_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_nfc.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_nfc_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_opengl.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_openglextensions.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_positioning.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_positioning_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_printsupport.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qml.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qml_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qmltest.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quick.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quick_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_script.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_script_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_scripttools.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_scripttools_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sensors.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sensors_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_serialport.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_serialport_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sql.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_sql_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_svg.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_svg_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_testlib.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_uitools.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webchannel.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webchannel_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webengine.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webengine_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginecore.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginecore_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginewidgets.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkit.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkit_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_websockets.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_websockets_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webview.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_webview_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_widgets.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xml.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xml_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/qt_functions.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/qt_config.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/macx-clang/qmake.conf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/spec_post.prf:
.qmake.stash:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/exclusive_builds.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/default_pre.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/default_pre.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/resolve_config.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/default_post.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/sdk.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/default_post.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/objective_c.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/warn_on.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/qt.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/resources.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/moc.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/unix/thread.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/mac/rez.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/testcase_targets.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/exceptions.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/yacc.prf:
../../Qt5.4.0/5.4/clang_64/mkspecs/features/lex.prf:
IMATCH.pro:
/Users/Kevin/Qt5.4.0/5.4/clang_64/lib/QtCore.framework/QtCore.prl:
qmake: FORCE
	@$(QMAKE) -spec macx-clang CONFIG+=debug CONFIG+=x86_64 -o Makefile IMATCH.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents ncc.h match.h feature.h utils.h delaunay.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cpp ncc.cpp match.cpp feature.cpp utils.cpp delaunay.cpp $(DISTDIR)/


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp utils.h \
		/usr/local/include/opencv2/opencv.hpp \
		/usr/local/include/opencv2/core/core_c.h \
		/usr/local/include/opencv2/core/types_c.h \
		/usr/local/include/opencv2/core/core.hpp \
		/usr/local/include/opencv2/core/version.hpp \
		/usr/local/include/opencv2/core/operations.hpp \
		/usr/local/include/opencv2/core/mat.hpp \
		/usr/local/include/opencv2/flann/miniflann.hpp \
		/usr/local/include/opencv2/flann/defines.h \
		/usr/local/include/opencv2/flann/config.h \
		/usr/local/include/opencv2/imgproc/imgproc_c.h \
		/usr/local/include/opencv2/imgproc/types_c.h \
		/usr/local/include/opencv2/imgproc/imgproc.hpp \
		/usr/local/include/opencv2/photo/photo.hpp \
		/usr/local/include/opencv2/photo/photo_c.h \
		/usr/local/include/opencv2/video/video.hpp \
		/usr/local/include/opencv2/video/tracking.hpp \
		/usr/local/include/opencv2/video/background_segm.hpp \
		/usr/local/include/opencv2/features2d/features2d.hpp \
		/usr/local/include/opencv2/objdetect/objdetect.hpp \
		/usr/local/include/opencv2/calib3d/calib3d.hpp \
		/usr/local/include/opencv2/ml/ml.hpp \
		/usr/local/include/opencv2/highgui/highgui_c.h \
		/usr/local/include/opencv2/highgui/highgui.hpp \
		/usr/local/include/opencv2/contrib/contrib.hpp \
		/usr/local/include/opencv2/contrib/retina.hpp \
		/usr/local/include/opencv2/contrib/openfabmap.hpp \
		match.h \
		ncc.h \
		feature.h \
		delaunay.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

ncc.o: ncc.cpp ncc.h \
		utils.h \
		/usr/local/include/opencv2/opencv.hpp \
		/usr/local/include/opencv2/core/core_c.h \
		/usr/local/include/opencv2/core/types_c.h \
		/usr/local/include/opencv2/core/core.hpp \
		/usr/local/include/opencv2/core/version.hpp \
		/usr/local/include/opencv2/core/operations.hpp \
		/usr/local/include/opencv2/core/mat.hpp \
		/usr/local/include/opencv2/flann/miniflann.hpp \
		/usr/local/include/opencv2/flann/defines.h \
		/usr/local/include/opencv2/flann/config.h \
		/usr/local/include/opencv2/imgproc/imgproc_c.h \
		/usr/local/include/opencv2/imgproc/types_c.h \
		/usr/local/include/opencv2/imgproc/imgproc.hpp \
		/usr/local/include/opencv2/photo/photo.hpp \
		/usr/local/include/opencv2/photo/photo_c.h \
		/usr/local/include/opencv2/video/video.hpp \
		/usr/local/include/opencv2/video/tracking.hpp \
		/usr/local/include/opencv2/video/background_segm.hpp \
		/usr/local/include/opencv2/features2d/features2d.hpp \
		/usr/local/include/opencv2/objdetect/objdetect.hpp \
		/usr/local/include/opencv2/calib3d/calib3d.hpp \
		/usr/local/include/opencv2/ml/ml.hpp \
		/usr/local/include/opencv2/highgui/highgui_c.h \
		/usr/local/include/opencv2/highgui/highgui.hpp \
		/usr/local/include/opencv2/contrib/contrib.hpp \
		/usr/local/include/opencv2/contrib/retina.hpp \
		/usr/local/include/opencv2/contrib/openfabmap.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ncc.o ncc.cpp

match.o: match.cpp match.h \
		utils.h \
		/usr/local/include/opencv2/opencv.hpp \
		/usr/local/include/opencv2/core/core_c.h \
		/usr/local/include/opencv2/core/types_c.h \
		/usr/local/include/opencv2/core/core.hpp \
		/usr/local/include/opencv2/core/version.hpp \
		/usr/local/include/opencv2/core/operations.hpp \
		/usr/local/include/opencv2/core/mat.hpp \
		/usr/local/include/opencv2/flann/miniflann.hpp \
		/usr/local/include/opencv2/flann/defines.h \
		/usr/local/include/opencv2/flann/config.h \
		/usr/local/include/opencv2/imgproc/imgproc_c.h \
		/usr/local/include/opencv2/imgproc/types_c.h \
		/usr/local/include/opencv2/imgproc/imgproc.hpp \
		/usr/local/include/opencv2/photo/photo.hpp \
		/usr/local/include/opencv2/photo/photo_c.h \
		/usr/local/include/opencv2/video/video.hpp \
		/usr/local/include/opencv2/video/tracking.hpp \
		/usr/local/include/opencv2/video/background_segm.hpp \
		/usr/local/include/opencv2/features2d/features2d.hpp \
		/usr/local/include/opencv2/objdetect/objdetect.hpp \
		/usr/local/include/opencv2/calib3d/calib3d.hpp \
		/usr/local/include/opencv2/ml/ml.hpp \
		/usr/local/include/opencv2/highgui/highgui_c.h \
		/usr/local/include/opencv2/highgui/highgui.hpp \
		/usr/local/include/opencv2/contrib/contrib.hpp \
		/usr/local/include/opencv2/contrib/retina.hpp \
		/usr/local/include/opencv2/contrib/openfabmap.hpp \
		ncc.h \
		feature.h \
		delaunay.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o match.o match.cpp

feature.o: feature.cpp feature.h \
		utils.h \
		/usr/local/include/opencv2/opencv.hpp \
		/usr/local/include/opencv2/core/core_c.h \
		/usr/local/include/opencv2/core/types_c.h \
		/usr/local/include/opencv2/core/core.hpp \
		/usr/local/include/opencv2/core/version.hpp \
		/usr/local/include/opencv2/core/operations.hpp \
		/usr/local/include/opencv2/core/mat.hpp \
		/usr/local/include/opencv2/flann/miniflann.hpp \
		/usr/local/include/opencv2/flann/defines.h \
		/usr/local/include/opencv2/flann/config.h \
		/usr/local/include/opencv2/imgproc/imgproc_c.h \
		/usr/local/include/opencv2/imgproc/types_c.h \
		/usr/local/include/opencv2/imgproc/imgproc.hpp \
		/usr/local/include/opencv2/photo/photo.hpp \
		/usr/local/include/opencv2/photo/photo_c.h \
		/usr/local/include/opencv2/video/video.hpp \
		/usr/local/include/opencv2/video/tracking.hpp \
		/usr/local/include/opencv2/video/background_segm.hpp \
		/usr/local/include/opencv2/features2d/features2d.hpp \
		/usr/local/include/opencv2/objdetect/objdetect.hpp \
		/usr/local/include/opencv2/calib3d/calib3d.hpp \
		/usr/local/include/opencv2/ml/ml.hpp \
		/usr/local/include/opencv2/highgui/highgui_c.h \
		/usr/local/include/opencv2/highgui/highgui.hpp \
		/usr/local/include/opencv2/contrib/contrib.hpp \
		/usr/local/include/opencv2/contrib/retina.hpp \
		/usr/local/include/opencv2/contrib/openfabmap.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o feature.o feature.cpp

utils.o: utils.cpp utils.h \
		/usr/local/include/opencv2/opencv.hpp \
		/usr/local/include/opencv2/core/core_c.h \
		/usr/local/include/opencv2/core/types_c.h \
		/usr/local/include/opencv2/core/core.hpp \
		/usr/local/include/opencv2/core/version.hpp \
		/usr/local/include/opencv2/core/operations.hpp \
		/usr/local/include/opencv2/core/mat.hpp \
		/usr/local/include/opencv2/flann/miniflann.hpp \
		/usr/local/include/opencv2/flann/defines.h \
		/usr/local/include/opencv2/flann/config.h \
		/usr/local/include/opencv2/imgproc/imgproc_c.h \
		/usr/local/include/opencv2/imgproc/types_c.h \
		/usr/local/include/opencv2/imgproc/imgproc.hpp \
		/usr/local/include/opencv2/photo/photo.hpp \
		/usr/local/include/opencv2/photo/photo_c.h \
		/usr/local/include/opencv2/video/video.hpp \
		/usr/local/include/opencv2/video/tracking.hpp \
		/usr/local/include/opencv2/video/background_segm.hpp \
		/usr/local/include/opencv2/features2d/features2d.hpp \
		/usr/local/include/opencv2/objdetect/objdetect.hpp \
		/usr/local/include/opencv2/calib3d/calib3d.hpp \
		/usr/local/include/opencv2/ml/ml.hpp \
		/usr/local/include/opencv2/highgui/highgui_c.h \
		/usr/local/include/opencv2/highgui/highgui.hpp \
		/usr/local/include/opencv2/contrib/contrib.hpp \
		/usr/local/include/opencv2/contrib/retina.hpp \
		/usr/local/include/opencv2/contrib/openfabmap.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o utils.o utils.cpp

delaunay.o: delaunay.cpp delaunay.h \
		utils.h \
		/usr/local/include/opencv2/opencv.hpp \
		/usr/local/include/opencv2/core/core_c.h \
		/usr/local/include/opencv2/core/types_c.h \
		/usr/local/include/opencv2/core/core.hpp \
		/usr/local/include/opencv2/core/version.hpp \
		/usr/local/include/opencv2/core/operations.hpp \
		/usr/local/include/opencv2/core/mat.hpp \
		/usr/local/include/opencv2/flann/miniflann.hpp \
		/usr/local/include/opencv2/flann/defines.h \
		/usr/local/include/opencv2/flann/config.h \
		/usr/local/include/opencv2/imgproc/imgproc_c.h \
		/usr/local/include/opencv2/imgproc/types_c.h \
		/usr/local/include/opencv2/imgproc/imgproc.hpp \
		/usr/local/include/opencv2/photo/photo.hpp \
		/usr/local/include/opencv2/photo/photo_c.h \
		/usr/local/include/opencv2/video/video.hpp \
		/usr/local/include/opencv2/video/tracking.hpp \
		/usr/local/include/opencv2/video/background_segm.hpp \
		/usr/local/include/opencv2/features2d/features2d.hpp \
		/usr/local/include/opencv2/objdetect/objdetect.hpp \
		/usr/local/include/opencv2/calib3d/calib3d.hpp \
		/usr/local/include/opencv2/ml/ml.hpp \
		/usr/local/include/opencv2/highgui/highgui_c.h \
		/usr/local/include/opencv2/highgui/highgui.hpp \
		/usr/local/include/opencv2/contrib/contrib.hpp \
		/usr/local/include/opencv2/contrib/retina.hpp \
		/usr/local/include/opencv2/contrib/openfabmap.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o delaunay.o delaunay.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

