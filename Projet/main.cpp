#include <QApplication>
#include "core/Application.h"
#include "core/Exception.h"
#include "gui/mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    //QApplication qapp(argc, argv);
    Application app("donnees/dossiers", "donnees/default", "configuration.xml");
    app.charger("enormand");
    app.getCompletion().ajouterSolution(app.getDossier(),app.getCategorieManager(),app.getUVManager(),app.getNoteManager(),true);
    app.getCompletion().ajouterSolution(app.getDossier(),app.getCategorieManager(),app.getUVManager(),app.getNoteManager(),false);

    /*MainWindow mw(&app);
    mw.show();
    return qapp.exec();*/
}
