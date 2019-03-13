QT       += testlib qml

TARGET = qmlshellunittests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES +=     main.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
DEFINES += QUICK_TEST_SOURCE_DIR=\\\"$$PWD/qmltests\\\"

ROOTDIR = $$PWD/../../

include(vendor/vendor.pri)
include($$ROOTDIR/qmlshell.pri)

DISTFILES +=     qpm.json \    
    qmltests/tst_QmlShell.qml \
    testdata/dummy1.txt \
    ../../README.md \
    ../../qpm.json \
    ../../appveyor.yml
