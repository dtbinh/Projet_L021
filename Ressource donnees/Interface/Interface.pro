QT += widgets
QT += xml
QMAKECXXFLAGS=−std=c++11QMAKELFLAGS=−std=c++11
CONFIG   += console c++11
SOURCES += \
    main.cpp \
    UTProfiler.cpp \
    UVEditeur.cpp \
    Profiler.cpp

HEADERS += \
    UTProfiler.h \
    UVEditeur.h \
    Profiler.h
