#include <iostream>
#include <QString>
#include "Application.h"
#include "Exception.h"

using namespace std;

int main()
{
    try
    {
        Application app;
        app.load("enormand");

        // Quelques essais en guise d'exemple
        app.getDossier().ajouterInscription("GI01", app.getPeriodeManager().getPeriode("A2013"), app.getFormationManager().getFormation("GI"));
        app.getDossier().getInscription("GI01").ajouterUV(app.getUVManager().getUV("NF16"));
        app.getDossier().getInscription("GI01").modifierNote("NF16", app.getNoteManager().getNote("C"));

        //app.getNoteManager().getNote("A").setMention("Mention");
        //app.getUVManager().getUV("LO21").setNom(app.getUVManager().getUV("LO21").getNom() + " (une UV qu'elle est bien !)");

        app.save();

    } catch(Exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}

