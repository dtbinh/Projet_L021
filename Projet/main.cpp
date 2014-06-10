#include <iostream>
#include <QString>
#include "Application.h"
#include "Exception.h"

using namespace std;

int main()
{
    try
    {
        Application app("dossiers/enormand/configuration.xml");
        app.load();

        // J'ai laissé ça ici car pour moi il y a un point à discuter encore
        DossierManager dosman;
        QString fichier="dossiers/enormand/enormand.xml";
        dosman.load(fichier, app.getFormationManager(), app.getPeriodeManager(), app.getUVManager(), app.getNoteManager());

        app.getNoteManager().getNote("A").setMention("Mention");
        app.getUVManager().getUV("LO21").setNom(app.getUVManager().getUV("LO21").getNom() + " (une UV qu'elle est bien !)");

        app.save();
        dosman.save();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

