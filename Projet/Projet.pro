QT += xml
QT += widgets

SOURCES += \
    core/Application.cpp \
    core/CategorieManager.cpp \
    core/Completion.cpp \
    core/CreditsManager.cpp \
    core/Dossier.cpp \
    core/Formation.cpp \
    core/FormationManager.cpp \
    core/Inscription.cpp \
    main.cpp \
    core/Manager.cpp \
    core/NoteManager.cpp \
    core/Periode.cpp \
    core/PeriodeManager.cpp \
    core/Solution.cpp \
    core/UV.cpp \
    core/UVManager.cpp \
    gui/mainwindow.cpp \
    gui/accueil.cpp \
    gui/configuration.cpp

HEADERS += \
    core/Application.h \
    core/Categorie.h \
    core/CategorieManager.h \
    core/Completion.h \
    core/Credits.h \
    core/CreditsManager.h \
    core/Dossier.h \
    core/Exception.h \
    core/Factory.h \
    core/Formation.h \
    core/FormationManager.h \
    core/Inscription.h \
    core/Manager.h \
    core/Note.h \
    core/NoteManager.h \
    core/Periode.h \
    core/PeriodeManager.h \
    core/Solution.h \
    core/UV.h \
    core/UVManager.h \
    gui/mainwindow.h \
    gui/accueil.h \
    gui/configuration.h \
    gui/applicationcomposant.h

FORMS += \
    gui/mainwindow.ui \
    gui/accueil.ui \
    gui/configuration.ui

OTHER_FILES +=
