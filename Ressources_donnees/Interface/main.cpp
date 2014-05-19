#include <QApplication>
#include <QString>
#include <QFileDialog>
#include "UTProfiler.h"
#include "UVEditeur.h"
#include "Profiler.h"

/*
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    UVManager& m=UVManager::getInstance();
    QString chemin = QFileDialog::getOpenFileName();
    m.load(chemin);
    UV& uv=m.getUV("LO21");
    UVEditeur fenetre(uv);
    fenetre.show();
    return app.exec();
}*/

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    Profiler profiler;
    profiler.show();
    return app.exec();
}
