#include <QApplication>
#include "core/Application.h"
#include "core/Exception.h"
#include "gui/mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication qapp(argc, argv);
    Application app("donnees/dossiers", "donnees/default", "configuration.xml");

    /*app.charger("enormand");
    Completion compa("donnees/dossiers/enormand", "completion.xml", app.getUVManager());
    compa.ajouterSolution(app.getDossier(),app.getCategorieManager(),app.getUVManager(),app.getNoteManager(),true);
    compa.ajouterSolution(app.getDossier(),app.getCategorieManager(),app.getUVManager(),app.getNoteManager(),false);*/
    MainWindow mw(&app);
    mw.show();
    return qapp.exec();
}
