#include <QApplication>
#include "core/Application.h"
#include "core/Exception.h"
#include "gui/mainwindow.h"
#include "core/Completion.h"
using namespace std;

int main(int argc, char *argv[])
{

    //QApplication qapp(argc, argv);
    Application app("dossiers", "dossiers/default", "configuration.xml");
    app.charger("enormand");
    Completion compa(app.getUVManager());
    //compa.ajouterSolution(app.getDossier(),app.getCategorieManager(),app.getUVManager(),true);
    //compa.ajouterSolution(app.getDossier(),app.getCategorieManager(),app.getUVManager(),false);


    //MainWindow mw(&app);
    //mw.show();

    //return qapp.exec();*/

}
