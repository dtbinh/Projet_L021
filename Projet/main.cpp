#include <iostream>
#include <QString>
#include "Application.h"
#include "Exception.h"

using namespace std;

int main()
{
    try
    {
        Application app("configuration.xml");
        app.load();

        // J'ai laissé ça ici car pour moi il y a un point à discuter encore
        DossierManager dosman;
        QString fichier="enormand.xml";
        dosman.load(fichier, app.getFormationManager(), app.getPeriodeManager(), app.getUVManager(), app.getNoteManager());
        QString fichier2="agermain.xml";
        dosman.load(fichier2, app.getFormationManager(), app.getPeriodeManager(), app.getUVManager(), app.getNoteManager());

        app.save();
        dosman.save();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

