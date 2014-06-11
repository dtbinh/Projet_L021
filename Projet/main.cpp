#include <iostream>
#include <QString>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include "Application.h"
#include "Exception.h"
#include "Acceuil.h"

using namespace std;


int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MainWindow test;
    test.show();
    try
    {
        Application app("dossiers/enormand/configuration.xml");
        app.load();

        // J'ai laissé ça car je pense que DossierManager est à virer
        DossierManager dosman;
        QString fichier="dossiers/enormand/enormand.xml";
        dosman.load(fichier, app.getFormationManager(), app.getPeriodeManager(), app.getUVManager(), app.getNoteManager());

        // Quelques essais en guise d'exemple
        //app.getNoteManager().getNote("A").setMention("Mention");
        //app.getUVManager().getUV("LO21").setNom(app.getUVManager().getUV("LO21").getNom() + " (une UV qu'elle est bien !)");

        app.save();
        dosman.save();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return app.exec();
}

