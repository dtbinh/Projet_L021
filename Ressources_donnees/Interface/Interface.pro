QT += widgets
QT += xml
QMAKECXXFLAGS=−std=c++11QMAKELFLAGS=−std=c++11
CONFIG   += console c++11

HEADERS += \
    Profiler.h \
    UTProfiler.h \
    UVEditeur.h

SOURCES += \
    main.cpp \
    Profiler.cpp \
    UTProfiler.cpp \
    UVEditeur.cpp
