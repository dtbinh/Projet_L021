#include <QApplication>
#include "core/Application.h"
#include "core/Exception.h"
#include "gui/mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication qapp(argc, argv);
    Application app("dossiers", "dossiers/default", "configuration.xml");

    MainWindow mw(&app);
    mw.show();

    return qapp.exec();
}
