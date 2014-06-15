#include <QApplication>
#include "core/Application.h"
#include "core/Exception.h"
#include "gui/mainwindow.h"
#include "core/CategorieManager.h"
#include "core/Factory.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication qapp(argc, argv);
    Application app("donnees/dossiers", "donnees/default", "configuration.xml");

    MainWindow mw(&app);
    mw.show();

    return qapp.exec();
}
